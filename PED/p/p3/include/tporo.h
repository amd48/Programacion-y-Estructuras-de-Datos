//48666767D  Mas Devesa, Alejandro

#ifndef _TPoro
#define _TPoro

#include <iostream>
using namespace std;

class TPoro
{
	// Sobrecarga del operador SALIDA
	friend ostream& operator<<(ostream &os, const TPoro &Poro);
	
	private:

		// Coordenada x de la posición
		int x;
		// Coordenada y de la posición
		int y;	
		// Volumen
		double volumen;
		// Color
		char* color;

	public:

		//	FORMA CANONICA

		// Constructor por defecto
		TPoro();
		
		// Constructor a partir de una posición y un volumen
		TPoro(int x, int y, double volumen);
		
		// Constructor a partir de una posición, un volumen y un color
		TPoro(int x, int y, double volumen, char* color);
		
		// Constructor de copia
		TPoro(const TPoro &Poro);
		
		// Destructor
		~TPoro();
		
		// Sobrecarga del operador asignación
		TPoro & operator=(const TPoro &Poro);

		//METODOS

		// Sobrecarga del operador igualdad
		bool operator==(const TPoro &Poro);
		
		// Sobrecarga del operador desigualdad
		bool operator!=(const TPoro &Poro);
		
		// Devuelve cierto si el poro está vacío
		bool EsVacio()const;
			
		//////////////////DECLARACIONES INLINE  (get , set)

		// Modifica la posición
		void Posicion(int x, int y){this->x = x; this->y = y;}
		
		// Modifica el volumen
		void Volumen(double volumen){this->volumen = volumen;}
		
		// Modifica el color
		void Color(char * color);
		
		// Devuelve la coordenada x de la posición
		int PosicionX() {return x;}
		
		// Devuelve la coordenada y de la posición
		int PosicionY() {return y;}
		
		// Devuelve el volumen
		double Volumen() {return volumen;}
		
		// Devuelve el color
		char* Color() {return color;}
};

#endif
