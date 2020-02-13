//============================================================================
// Name        : TCalendario.cpp
// Author      : Daniel Siguenza Rico
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "tcalendario.h"
using namespace std;

TCalendario::TCalendario ()
{
	this->dia = 1;
	this->mes = 1;
	this->anyo = 1900;
	this->mensaje = NULL;
}

TCalendario::TCalendario(int dia, int mes, int anyo, char *mens)
{
	bool fechOk = true;

	int diaMax = compruebaFecha(mes,anyo);

	if(dia>diaMax || dia<1) // EL DIA NO ES CORRECTO
		fechOk = false;
	if(mes>12 || mes<1) // EL MES NO ES CORRECTO
		fechOk = false;
	if(anyo<1900)	// EL ANYO NO ES CORRECTO
		fechOk = false;

	if(!fechOk)	// Si la fecha no es correcta, poner por defecto
	{
		this->dia = 1;
		this->mes = 1;
		this->anyo = 1900;
		this->mensaje = NULL;
	}
	else
	{
		this->dia = dia;
		this->mes = mes;
		this->anyo = anyo;
		this->mensaje = NULL;
		
		if(mens!=NULL)
		{
			this->mensaje =  new char[strlen(mens)+1];
			strcpy(this->mensaje,mens);
		}
	}
}

//Constructor copia
TCalendario::TCalendario (const TCalendario &TCal)
{
	this->dia=TCal.dia;
	this->mes=TCal.mes;
	this->anyo=TCal.anyo;
	if(TCal.mensaje!=NULL)
	{
		this->mensaje =  new char[strlen(TCal.mensaje)+1];
		strcpy(this->mensaje,TCal.mensaje);
	}
	else
		this->mensaje = NULL;

}

// METODO PRIVADO QUE COMPRUEBA SI LA FECHA ES CORRECTA
int TCalendario::compruebaFecha(int mes, int anyo)
{
	int diaMax = 0;

	if(mes==1 || mes==3 || mes==5 || mes==7 || mes==8 || mes==10 || mes==12)
	{
		diaMax = 31;
	}
	else if(mes==4 || mes==6 || mes==9 || mes==11)
	{
		diaMax = 30;
	}
	else if(mes == 2)
	{
		if((anyo%4 == 0) && ((anyo%100 !=0) || (anyo%400 == 0)))
		{
			diaMax = 29;
		}
		else
		{
			diaMax = 28;
		}
	}
	else
	{
		diaMax = 31; // Suponemos el mes Enero por defecto
	}

	return diaMax;
}

TCalendario::~TCalendario()
{

	dia = 1;
	mes = 1;
	anyo = 1900;

	if (mensaje != NULL)
	{
		delete[] this->mensaje;
	}
	mensaje = NULL;
	
}

// Sobrecarga del operador asignación
TCalendario& TCalendario:: operator=(const TCalendario &t) 
{

	if (this != &t)
	{
		this->~TCalendario();
		this->dia=t.dia;
		this->mes=t.mes;
		this->anyo=t.anyo;
		
		if(t.mensaje!=NULL)
		{
			this->mensaje =  new char[strlen(t.mensaje)+1];
			strcpy(this->mensaje,t.mensaje);
		}
		else
		{
			this->mensaje = NULL;
		}
	}
	
	return (*this);
}

// Sobrecarga del operador SUMA de fecha + un número de dias;
TCalendario TCalendario:: operator+(int n)
{

	TCalendario tAux(*this);

	int diaMax = compruebaFecha(tAux.mes,tAux.anyo);

	// HACER OBJETO TEMPORAL
	if((tAux.dia+n)>diaMax)
	{
		while(n>0)
		{
			int diaMax = compruebaFecha(tAux.mes,tAux.anyo);

			if(tAux.mes>12)
			{
				tAux.anyo+= 1;
				tAux.mes = 1;
				tAux.dia = 1;
			}
			else if(tAux.dia>diaMax)
			{
				tAux.mes+=1;
				tAux.dia = 1;
			}
			else
			{
				tAux.dia+=1;
				n--;
			}
		}
	}
	else // INCREMENTAMOS LA EFICIENCIA CUANDO LLAMAMOS AL OPERADOR++
	{
		tAux.dia = dia+n;
	}

	this->dia = tAux.dia;
	this->mes = tAux.mes;
	this->anyo = tAux.anyo;

	return *this;
}


// Sobrecarga del operador RESTA de fecha - un número de dias;
TCalendario TCalendario:: operator-(int n)
{
	TCalendario tAux(*this);

	if((tAux.dia-n)<1)
	{

		while(n>0)
		{
			if(tAux.mes<=1 && tAux.dia<=1)
			{
				tAux.anyo-= 1;
				tAux.mes = 12;
				tAux.dia = compruebaFecha(tAux.mes,tAux.anyo);

			}
			else if(tAux.dia<=1)
			{
				tAux.mes-=1;
				tAux.dia = compruebaFecha(tAux.mes,tAux.anyo);
				
			}
			else
			{
				tAux.dia-=1;
				
			}
			n--;
		}
	}
	else
	{
		tAux.dia = tAux.dia-n;
	}

	TCalendario defecto;

	if(defecto>tAux)
	{
		tAux = defecto;
	}

	this->dia = tAux.dia;
	this->mes = tAux.mes;
	this->anyo = tAux.anyo;

	return (tAux);
}

// Modifica la fecha incrementandola en un dia (con postincremento);
TCalendario TCalendario:: operator++(int t)
{
	TCalendario tC(*this); // OBJETO TEMPORAL

	*this = *this + 1;
	return tC;
}

// Modifica la fecha incrementandola en un dia (con preincremento);
TCalendario& TCalendario:: operator++(void)
{
	*this  = *this + 1;
	return (*this);
}


// Modifica la fecha decrementándola en un dia (con postdecremento);
TCalendario TCalendario:: operator--(const int t)
{
	TCalendario tC(*this); // OBJETO TEMPORAL

	*this = (*this) - 1;
	return tC;
}


// Modifica la fecha decrementándola en un día (con predecremento);
TCalendario& TCalendario:: operator--(void)
{
	*this = *this - 1;
	return (*this);
}

// Modifica la fecha
bool TCalendario::ModFecha (int dia, int mes, int anyo)
{
	bool ok = true;
	int diaMax = compruebaFecha(mes,anyo); // DEVUELVE EL DIA MAXIMO QUE TIENE EL MES
	if(!((dia>diaMax || dia<1)||(mes<1 || mes>12) || (anyo<1900))) // LA FECHA ES CORRECTA
	{
		this->dia = dia;
		this->mes=mes;
		this->anyo=anyo;
	}
	else
	{
		ok = false;
	}

	return ok;
}

// Modifica el mensaje
bool TCalendario::ModMensaje(char *mens)
{
	if(mens!=NULL)
	{
		this->mensaje =  new char[strlen(mens)+1];
		strcpy(this->mensaje,mens);
		return true;
	}
	else
	{
		this->mensaje = NULL;
		return false;
	}
}


bool TCalendario::compara(const TCalendario &t) const
{
	bool ok = false;

	if((t.dia==dia) && (t.mes==mes) && (t.anyo==anyo))
	{
		ok = true;
	}
	else
		ok = false;

	return ok;
}

// Sobrecarga del operador igualdad;
bool TCalendario::operator ==(const TCalendario &t)
{
	bool ok = false;
	if(compara(t))
	{
		if(mensaje!=NULL && t.mensaje!=NULL )
		{
			if(strcmp(mensaje,t.mensaje)==0)
			{
				ok = true;
			}
			else
			{
				ok = false;
			}
		}
		else if(mensaje==NULL && t.mensaje==NULL)
		{
			ok = true;
		}
		else
		{
			ok = false;
		}
	}
	else
	{
		ok = false;
	}
	return ok;
}

// Sobrecarga del operador desigualdad;
bool TCalendario::operator !=(const TCalendario &t)
{
	return !(compara(t));
}

bool TCalendario:: esMayor(const TCalendario &t)
{
	bool mayor = false;

	if(anyo>t.anyo)
		mayor = true;
	else if(anyo == t.anyo && mes>t.mes)
		mayor = true;
	else if(anyo == t.anyo && mes == t.mes && dia>t.dia)
		mayor = true;

	return mayor;
}

bool TCalendario:: esMayorCadena(const TCalendario &t2)
{
	bool esMayor = false;
	
	if(mensaje != NULL && t2.mensaje != NULL) // COMPARAMOS LOS MENSAJES
	{
		if(strcmp(mensaje,t2.mensaje)>0) // LA CADENA ES MAYOR
			esMayor = true;
		else if(strcmp(mensaje,t2.mensaje)<0) // LA CADENA ES MENOR
			esMayor = false;
		else 								 // LAS CADENAS SON IGUALES
			esMayor = false;
			
	}
	if((mensaje==NULL || t2.mensaje == NULL) && !(mensaje==NULL && t2.mensaje == NULL)) // SI UNO DE LOS 2 SON NULL
	{
		if(mensaje==NULL && t2.mensaje!=NULL)
			esMayor = false;
		if(mensaje!=NULL && t2.mensaje==NULL)
			esMayor = true;
	}
	
	return esMayor;
}
// Sobrecarga del operador >; (ver ACLARACIÓN sobre ORDENACIÓN)
bool TCalendario:: operator>(const TCalendario &t2)
{
	bool mayor = false;

	if(this->compara(t2)) // SON IGUALES
	{
		
		if(mensaje!=NULL && t2.mensaje!=NULL )
		{
			if(strcmp(mensaje,t2.mensaje)==0)
			{
				mayor = false;
			}
			if(strcmp(mensaje,t2.mensaje)>0)
			{
				mayor = true;
			}
		}
		else if((mensaje==NULL || t2.mensaje == NULL) && !(mensaje==NULL && t2.mensaje == NULL)) // SI UNO DE LOS 2 SON NULL
		{
			if(mensaje==NULL && t2.mensaje!=NULL)
				mayor = false;
			if(mensaje!=NULL && t2.mensaje==NULL)
				mayor = true;
		}
	}
	else if(this->esMayor(t2)) // T1 ES MAYOR QUE T2
	{
		mayor = true;
	}
	else // T1 ES MENOR QUE T2
	{
		mayor = false;
	}

	return mayor;

}

// Sobrecarga del operador <; (ver ACLARACIÓN sobre ORDENACIÓN)
bool TCalendario:: operator<(const TCalendario &t2)
{
	bool menor = false;

	if(this->compara(t2)) // SON IGUALES
	{

		if(mensaje!=NULL && t2.mensaje!=NULL )
		{
			if(strcmp(mensaje,t2.mensaje)==0)
			{
				menor = false;
			}
			if(strcmp(mensaje,t2.mensaje)<0)
			{
				menor = true;
			}
		}
		else if((mensaje==NULL || t2.mensaje == NULL) && !(mensaje==NULL && t2.mensaje == NULL)) // SI UNO DE LOS 2 SON NULL
		{
			if(mensaje==NULL && t2.mensaje!=NULL)
				menor = true;
			if(mensaje!=NULL && t2.mensaje==NULL)
				menor = false;
		}
	}
	else if(this->esMayor(t2)) // T1 ES MAYOR QUE T2
	{
		menor = false;
	}
	else // T1 ES MENOR QUE T2
	{
		menor = true;
	}

	return menor;
}

bool TCalendario:: EsVacio()
{
	if(dia==1 && mes==1 && anyo==1900 && mensaje == NULL)
		return true;
	else
		return false;
}

// Devuelve el día del calendario;
int TCalendario::Dia()
{
	return dia;
}

int TCalendario::Mes()
{
	return mes;
}

int TCalendario::Anyo()
{
	return anyo;
}

// NO FUNCIONA BIEN
char* TCalendario::Mensaje()
{
	return mensaje;
}

ostream&  operator<<(ostream &s,const TCalendario &obj)
{
	s << setfill('0') << setw(2)<< obj.dia<<"/";
	s << setfill('0') << setw(2)<< obj.mes<<"/";
	s << obj.anyo;

	if(obj.mensaje==NULL)
		s << " " << "\"\"";
	else
		s << " " << "\""<< obj.mensaje << "\"";

	return s;
}
