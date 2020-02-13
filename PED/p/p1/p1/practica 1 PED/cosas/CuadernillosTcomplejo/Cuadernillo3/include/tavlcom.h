#ifndef _TAVLCom_
#define _TAVLCom_

#include "tcomplejo.h"
#include "tvectorcom.h"

class TNodoAVL;
class TAVLCom
{
	friend class TNodoAVL;
	friend ostream &operator<<(ostream &, const TAVLCom &);

	private:
		TNodoAVL *raiz;
		void InordenAux(TVectorCom &,int &) const;
		void PreordenAux(TVectorCom &,int &) const;
		void PostordenAux(TVectorCom &,int &) const;
		void Equilibrio();
		void EquilibrioII();
		void EquilibrioID();
		void EquilibrioDD();
		void EquilibrioDI();
		void ActualizarFE();
	public:
		TAVLCom();
		TAVLCom(const TAVLCom &);
		~TAVLCom();
		TAVLCom &operator=(const TAVLCom &);
		
		bool operator==(const TAVLCom &)const;
		bool operator!=(const TAVLCom &)const;
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
};

class TNodoAVL
{
	friend class TAVLCom;

	private:
		TComplejo item;
		TAVLCom iz, de;
		int fe;
	public:
		TNodoAVL();
		TNodoAVL(const TNodoAVL &);
		~TNodoAVL();
		TNodoAVL &operator=(const TNodoAVL &);
};

#endif