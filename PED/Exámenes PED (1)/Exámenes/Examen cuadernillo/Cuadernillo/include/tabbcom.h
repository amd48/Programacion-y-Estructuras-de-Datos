#ifndef _TABBCom_
#define _TABBCom_

#include "tcomplejo.h"
#include "tvectorcom.h"

class TNodoABB;
class TABBCom
{
	friend class TNodoABB;
	friend ostream &operator<<(ostream &, const TABBCom &);

	private:
		TNodoABB *nodo;
		void InordenAux(TVectorCom &,int &) const;
		void PreordenAux(TVectorCom &,int &) const;
		void PostordenAux(TVectorCom &,int &) const;
	public:
		TABBCom();
		TABBCom(const TABBCom &);
		~TABBCom();
		TABBCom &operator=(const TABBCom &);
		

		bool operator==(const TABBCom &)const;
		bool EsVacio() const;
		bool Insertar(const TComplejo &);
		bool Borrar (const TComplejo &);
		bool Buscar(const TComplejo &);
		TComplejo Raiz()const;
		int Altura()const;
		int Nodos()const;
		int NodosHoja()const;

		TVectorCom Inorden() const;
		TVectorCom Preorden() const;
		TVectorCom Postorden() const;
		TVectorCom Niveles() const;
};

class TNodoABB
{
	friend class TABBCom;

	private:
		TComplejo item;
		TABBCom iz, de;
	public:
		TNodoABB();
		TNodoABB (const TNodoABB &);
		~TNodoABB();
		TNodoABB &operator=(const TNodoABB &);
};

#endif