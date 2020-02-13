#ifndef _TVectorCom_
#define _TVectorCom_

#include "tcomplejo.h"

class TVectorCom
{

	friend ostream &operator<<(ostream &, const TVectorCom &);

	private:
		TComplejo *c;
		int tamano;
		TComplejo error;
	public:
		TVectorCom();
		TVectorCom(int tam);
		TVectorCom(const TVectorCom &);
		~TVectorCom();

		int Tamano() const;
		int Ocupadas() const;
		bool ExisteCom(const TComplejo &) const;
		void MostrarComplejos(double re) const;
		bool Redimensionar(int tam);

		bool operator== (const TVectorCom &) const;
		bool operator!= (const TVectorCom &) const;
		TVectorCom& operator= (const TVectorCom &);
		TComplejo& operator[] (int);
		TComplejo operator [] (int) const;
};

#endif