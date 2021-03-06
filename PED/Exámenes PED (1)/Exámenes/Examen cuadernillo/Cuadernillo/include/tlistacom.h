#ifndef _Lista_
#define _Lista_

#include "tcomplejo.h"
class TListaCom;
class TListaPos;
class TListaNodo
{
	friend class TListaCom;
	friend class TListaPos;

	private:
		TComplejo e;
		TListaNodo *anterior;
		TListaNodo *siguiente;
	public:
		TListaNodo();
		TListaNodo(const TListaNodo &);
		~TListaNodo();
		TListaNodo &operator=(const TListaNodo &);
		friend ostream& operator<<(ostream &, const TListaCom &);
};

class TListaPos
{
	friend class TListaCom;
	
	private:
		TListaNodo *pos;
	public:
		TListaPos();
		TListaPos(const TListaPos &);
		~TListaPos();
		TListaPos &operator=(const TListaPos &);

		bool operator==(const TListaPos &) const;
		bool operator!=(const TListaPos &) const;
		TListaPos Anterior() const;
		TListaPos Siguiente() const;
		bool EsVacia() const;
};

class TListaCom
{
	friend class TListaNodo;
	friend ostream &operator<<(ostream &, const TListaCom &);

	private:
		TListaNodo *primero;
		TListaNodo *ultimo;
	public:
		TListaCom();
		TListaCom(const TListaCom &);
		~TListaCom();
		TListaCom &operator=(const TListaCom &);

		bool operator==(const TListaCom &) const;
		bool operator!=(const TListaCom &) const;
		TListaCom operator+(const TListaCom &) const;
		TListaCom operator-(const TListaCom &) const;
		bool EsVacia() const;
		bool InsCabeza(const TComplejo &);
		bool InsertarI(const TComplejo &, const TListaPos &);
		bool InsertarD(const TComplejo &, const TListaPos &);
		bool Borrar(const TComplejo &);
		bool BorrarTodos(const TComplejo &);
		bool Borrar(TListaPos &);
		TComplejo Obtener(const TListaPos &) const;
		bool Buscar(const TComplejo &) const;
		int Longitud() const;
		TListaPos Primera() const;
		TListaPos Ultima() const;
};

#endif
