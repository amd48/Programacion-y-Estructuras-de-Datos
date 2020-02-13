//48666767D  Mas Devesa, Alejandro
#include "tvectorporo.h"

TVectorPoro::TVectorPoro()  
{
	datos = NULL; //Puntero interno a NULL
	dimension = 0;
}

TVectorPoro::TVectorPoro(int dimension)
{
	if(dimension > 0)
	{
		this->dimension = dimension;
		datos = new TPoro[dimension]; //Usando puntero para crear un vector de dimension especificada por parametros
	}
	else
		TVectorPoro();		
}


TVectorPoro::TVectorPoro(const TVectorPoro &vectorTPoro)
{
	if(vectorTPoro.dimension > 0 && vectorTPoro.datos != NULL)
	{
		dimension = vectorTPoro.dimension;
		datos = new TPoro[dimension];

		for(int i = 0; i < dimension; i++)	
			datos[i] = vectorTPoro.datos[i];

		error = vectorTPoro.error;
	}
	else
	{
		dimension = 0;
		datos = NULL;
	}

}

TVectorPoro::~TVectorPoro()
{
	dimension = 0;
	delete [] datos;//ASI BORRAMOS TODOS LOS DATOS
	datos = NULL;//
	//error?¿?¿¿?¿?¿?¿?¿?¿?¿?¿?¿?¿?¿?¿?¿?¿?¿?¿?¿?¿?¿?¿
}

TVectorPoro& TVectorPoro::operator=(const TVectorPoro &vectorTPoro)
{
	(*this).~TVectorPoro();
	if(vectorTPoro.dimension == 0)
		return *this;

	dimension = vectorTPoro.dimension;
	datos = new TPoro[dimension];//reservo memoria adaptada al nuevo SIZE para copiar los datos

	for(int i = 0; i < dimension; i++)
		datos[i] = vectorTPoro.datos[i];

	error = vectorTPoro.error;

	return *this;
}


bool TVectorPoro::operator==(const TVectorPoro &vectorTPoro)
{
	if(dimension == vectorTPoro.dimension)
	{
		for(int i = 0; i < dimension; i++)
			if(datos[i] != vectorTPoro.datos[i])
				return false;
	}
	else
		return false;
	return true;

}

bool TVectorPoro::operator!=(TVectorPoro &vectorTPoro)
{
	if(dimension == vectorTPoro.dimension)
	{
		for(int i = 0; i < dimension; i++)
			if(datos[i] != vectorTPoro.datos[i])
				return true;
	}
	else
		return true;

	return false;
}



//PARTE DERECHA DEL CORCHETE
TPoro& TVectorPoro::operator[](int size)
{
	if(datos != NULL && size > 0 && size <= dimension)
		return datos[size-1];
	else
		return error;
	
}

//PARTE  IZQUIERDA DEL CORCHETE
TPoro TVectorPoro::operator[](int size) const
{
	if(datos != NULL && size > 0 && size <= dimension)
		return datos[size-1];
	else
		return error;//PREGUNTAR XK SI QUITAMOS EL const DEL CONSTRUCTOR DE TPorO NO COMPILA
}

int TVectorPoro::Cantidad()
{
	int cont = 0;

	for(int i = 0; i < dimension; i++)
		if(!datos[i].EsVacio())
			cont++;
	
	return cont;
}

void TVectorPoro::RedimensionarMenor(TPoro *datosAux, int nuevoSize)//En este caso el vector nuevo es menor y los elementos que se quedan a la derecha(en el viejo) ¿?hay que borrarlos
{
	for(int i = 0; i < nuevoSize; i++)
		datosAux[i] = datos[i]; //copiamos los datos del vector // BORRAMOS VECTOR ANTIGUO
}

void TVectorPoro::RedimensionarMayor(TPoro *datosAux, int nuevoSize)
{
	for(int i = 0; i < nuevoSize; i++)
	{
		if(i < dimension)
			datosAux[i] = datos[i]; //copiamos los datos del vector 
		else
		{
			TPoro poroVacio;
			datosAux[i] = poroVacio;//Llenamos lo que queda del vector TPoros vacios
		}
	}
}

bool TVectorPoro::Redimensionar(int nuevoSize)
{
	if(nuevoSize > 0 && nuevoSize != dimension)
	{
		TPoro *datosAux = new TPoro[nuevoSize];//Creamos un vector auxilar para redimensionar;

		if(nuevoSize < dimension)
			RedimensionarMenor(datosAux, nuevoSize);// EL VECTOR LLEGA MODIFICADO?¿?¿¿?¿?¿?¿?
		else
			RedimensionarMayor(datosAux, nuevoSize);// EL VECTOR LLEGA MODIFICADO?¿?¿¿?¿?¿?¿?
			
		dimension = nuevoSize;
		datos = new TPoro[dimension];
		for(int i = 0; i < dimension; i++)
		{
			datos[i] = datosAux[i];
		}
		//delete datosAux;//Liberamos la memoria despues de utulizar new
		return true;
	}
	else
		return false;
}

ostream& operator<<(ostream &os, const TVectorPoro &vector)
{
	int size = vector.dimension;
	if(size == 0)
		return (os << "[]");
	
	os << "[";
	for(int i = 1; i <= size; i++)
	{
		if(i < size)
			os << i << " " << vector[i] << " ";
		else
			os << i << " " << vector[i];
	}

	os << "]";

	return os;	

}
