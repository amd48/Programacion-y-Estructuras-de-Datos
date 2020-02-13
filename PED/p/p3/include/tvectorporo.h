//48666767D  Mas Devesa, Alejandro

#ifndef _TVectorPoro
#define _TVectorPoro

#include <iostream>
#include <vector>

using namespace std;

#include "tporo.h"

class TVectorPoro
{
	// Sobrecarga del operador salida
	friend ostream & operator<<(ostream &, const TVectorPoro &);
	
	private:

		// Dimension del vector
		int dimension;
		// Datos del vector
		TPoro *datos; //Puntero de tipo TPoro
		// Para cuando haya error en el operator[]
		TPoro error;

	public:
		
		//	FORMA CANONICA

		// Constructor por defecto
		TVectorPoro();
		// Constructor a partir de una dimensión
		TVectorPoro(int dimension);
		// Constructor de copia
		
		TVectorPoro(const TVectorPoro &);
		// Destructor
		~TVectorPoro();

		// Sobrecarga del operador asignación
		TVectorPoro& operator=(const TVectorPoro &);

		//METODOS
		// Sobrecarga del operador igualdad
		bool operator==(const TVectorPoro &);
		
		// Sobrecarga del operador desigualdad
		bool operator!=(TVectorPoro &);
		
		// Sobrecarga del operador corchete (parte IZQUIERDA)
		TPoro& operator[](int);
		
		// Sobrecarga del operador corchete (parte DERECHA)
		TPoro operator[](int) const;
		
		// Devuelve la longitud (dimensión) del vector
		int Longitud() {return dimension;}
		
		// Devuelve la cantidad de posiciones ocupadas (no vacías) en el vector
		int Cantidad();
		
		// REDIMENSIONAR el vector de TPoro
		bool Redimensionar(int);
		//////MIS METODOS AUXILIARES PARA REDIMENSIONAR
		void RedimensionarMayor(TPoro *, int);
		void RedimensionarMenor(TPoro *, int);
};

#endif
