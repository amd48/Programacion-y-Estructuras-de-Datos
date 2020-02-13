	 #include "tvectorcom.h"

TVectorCom::TVectorCom()
{
	c = NULL;
	tamano = 0;
}

TVectorCom::TVectorCom(int tamano)
{
	if(tamano > 0)
	{
		c = new TComplejo[tamano];
		this->tamano = tamano;
	}
	else
	{
		this->tamano = 0;
		c = NULL;
	}
}


TVectorCom::TVectorCom(const TVectorCom &v)
{
	if(v.c != NULL && v.tamano != 0)
	{
		c = new TComplejo[v.tamano];
		tamano = v.tamano;
		for(int i = 0; i < tamano; i++)
		{
			c[i] = v.c[i];
		}
	}
	else
	{
		c = NULL;
		tamano = 0;
	}
}


TVectorCom::~TVectorCom()
{
	if(c != NULL)
	{
		delete [] c;
	}
	c = NULL;
	tamano = 0;
}


int TVectorCom::Tamano() const
{
	return tamano;
}


int TVectorCom::Ocupadas() const
{
	int num = 0;
	
	for(int i = 0; i < tamano; i++)
	{
			if(c[i].Re() != 0 || c[i].Im() != 0)
			{
				num++;
			}
	}
	return num;
}


bool TVectorCom::ExisteCom(const TComplejo &c) const
{
	bool ex = false;

	for(int i = 0; i < tamano; i++)
	{
		if(this-> c[i] == c)
			ex = true;
	}
	return ex;
}


void TVectorCom::MostrarComplejos(double re) const
{
	bool primero = true;
	
	cout << "[";
	for(int i = 0; i < tamano; i++){
		if(c[i].Re() >= re){
			if(primero){
				cout << c[i];
				primero = false;
			}
			else{
				cout << ", " << c[i];
			}
		}
	}
	cout << "]";
}


bool TVectorCom::Redimensionar(int tamano)
{
	bool sehace = false;
	TComplejo *comp = NULL;
	
	if(this->tamano != tamano && tamano > 0){
		sehace = true;
		comp = new TComplejo [tamano];
		for(int i = 0; i < tamano && i < this->tamano; i++){
			comp[i] = c[i];
		}
		if(c != NULL){
			delete []c;
			c = NULL;
		}
		c = comp;
		this->tamano = tamano;
	} 
	return sehace;
}


bool TVectorCom::operator== (const TVectorCom &v) const
{
	bool soniguales = false;

	if(this->tamano == v.tamano)
	{
		soniguales = true;
		for(int i = 0; i < tamano; i++)
		{
			if(v.c[i] != c[i])
			{
				soniguales = false;
			}
		}
	}
	return soniguales;
}


bool TVectorCom::operator!= (const TVectorCom &v) const
{
	return !(*this == v);
}


TVectorCom& TVectorCom::operator= (const TVectorCom &v)
{
	if(this != &v){
		this->~TVectorCom();
		if(v.tamano != 0)
		{
			c = new TComplejo [v.tamano];
			tamano = v.tamano;
			for(int i = 0; i < tamano; i++)
			{
				c[i] = v.c[i];	
			}
		}
	}
	return *this;
}


TComplejo& TVectorCom::operator[] (int pos)
{
	if(pos >= 1 && pos <= tamano && c != NULL)	
		return c[pos - 1];
	else
		return error;
}


TComplejo TVectorCom::operator [] (int pos) const
{
	if(pos >= 1 && pos <= tamano && c != NULL)
		return c[pos - 1];
	else
		return error;
}


ostream &operator<<(ostream &os, const TVectorCom &v)
{
	os<<"[";
	if(v.c && v.tamano>0)
	{
		for (int i=0;i<v.tamano;i++)
		{
			os << "(" << i + 1 << ") " << v.c[i];
			if(i < v.tamano-1)
				os << ", ";
		}
	}
	os << "]";

	return os;
}

