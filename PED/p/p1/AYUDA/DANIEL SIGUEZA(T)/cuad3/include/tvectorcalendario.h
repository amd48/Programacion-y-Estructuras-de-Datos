/*
 * TVectorCalendario.h
 *
 *  Created on: 13/03/2015
 *      Author: dsr20
 */

#ifndef TVECTORCALENDARIO_H_
#define TVECTORCALENDARIO_H_

#include "tcalendario.h"
#include <string.h>
#include <iomanip>
#include <sstream>

using namespace std;
class TVectorCalendario {
	private:
		TCalendario *c;
		int tamano;
		TCalendario error;

	public:
		// Constructor por defecto
		TVectorCalendario();
		// Constructor a partir de un tamaño
		TVectorCalendario(int);
		// Constructor de copia
		TVectorCalendario(const TVectorCalendario &);
		// Destructor
		~TVectorCalendario();
		// Sobrecarga del operador asignación
		TVectorCalendario & operator=(const TVectorCalendario &);
		// Sobrecarga del operador igualdad
		bool operator==(const TVectorCalendario &);
		// Sobrecarga del operador desigualdad
		bool operator!=(const TVectorCalendario &);
		// Sobrecarga del operador corchete (parte IZQUIERDA)
		TCalendario & operator[](int);
		// Sobrecarga del operador corchete (parte DERECHA)
		TCalendario operator[](int) const;
		// Tamaño del vector (posiciones TOTALES)
		int Tamano() const;
		// Cantidad de posiciones OCUPADAS (no vacías) en el vector
		int Ocupadas() ;
		// Devuelve true si existe el calendario en el vector
		bool ExisteCal(TCalendario &);
		// Mostrar por pantalla mensajes de TCalendario en el vector, de fecha IGUAL O POSTERIOR a la pasada
		void MostrarMensajes(int,int,int);
		// REDIMENSIONAR el vectorde TCalendario
		bool Redimensionar(int);

		// Sobrecarga del operador salida
		friend ostream & operator<<(ostream &,const TVectorCalendario &);


};
#endif /* TVECTORCALENDARIO_H_ */
