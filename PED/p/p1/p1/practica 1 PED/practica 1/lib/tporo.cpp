//48666767D  Mas Devesa, Alejandro
#include <iostream>
#include <cctype>
#include <string.h>
using namespace std;

#include "tporo.h"

TPoro::TPoro()
{
	x = 0;
	y = 0;
	volumen = 0;
	color = NULL;
}

TPoro::TPoro(int x, int y, double volumen)
{
	this-> x = x;
	this-> y = y;
	this->volumen = volumen;
	color = NULL;
}

TPoro::TPoro(int x, int y, double volumen, char* color)
{
	this-> x = x;
	this-> y = y;
	this->volumen = volumen;
	Color(color);
}

TPoro::TPoro(const TPoro &poro)
{
	x = poro.x;
	y = poro.y;
	volumen = poro.volumen;
	color = poro.color;//SE COPIA TODO EL NOMBRE ?¿?¿?, ES NECESARIO?¿?¿?¿? CON SABER DONDE EMPIEZA LA INFORMACION SOBRA
}

TPoro::~TPoro()
{ 
	x = 0;
	y = 0;
	volumen = 0;
	//delete []color;//BORRAMOS MEMORIA RESERVADA
	color = NULL;
	
}
void TPoro::Color(char * color)
{
	if(color != NULL)
	{	
		this->color = NULL;
		int sizeColor = strlen(color);
		this->color = new char[sizeColor+1]; 
		this->color[sizeColor+1] = '\0';
		for(int i = 0; i < sizeColor; i++)
			this->color[i] = tolower(color[i]);
	}
	else
		this->color=NULL;
}

bool TPoro::EsVacio() const
{
	return (x == 0 && y == 0 && volumen == 0 && color == NULL);
}

TPoro& TPoro::operator=(const TPoro &poro)
{
	(*this).~TPoro();//Liberacion de recursos

	x = poro.x;
	y = poro.y;
	volumen = poro.volumen;
	color = poro.color;

	return *this;
}

bool TPoro::operator==(TPoro& poro)
{
	if(color == NULL && poro.color != NULL || color != NULL && poro.color == NULL)
		return false;

	else if(color == NULL && poro.color == NULL)
		return (x == poro.x && y == poro.y && volumen == poro.volumen);
	else
		return (x == poro.x && y == poro.y && volumen == poro.volumen && strcmp(poro.color, this->color) == 0);
}

bool TPoro::operator!=(const TPoro& poro)
{
	return (x !=poro.x && y != poro.y && color != poro.color && volumen!= poro.volumen);	
}

ostream& operator<<(ostream &os, const TPoro &poro)
{
	if(!poro.EsVacio())
	{
		os.setf(ios::fixed);
		os.precision(2);

		os << "("<<poro.x<<", "<<poro.y<<") "<<poro.volumen<<" ";
		if(poro.color != NULL)
		{
			os << poro.color;
		}
		else
			os<<"-";
	}
	else
		os << "()";

	return os;
}