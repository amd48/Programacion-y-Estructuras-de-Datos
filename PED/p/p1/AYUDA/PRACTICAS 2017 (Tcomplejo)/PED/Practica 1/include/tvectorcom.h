#ifndef TVECTORCOM_H
#define TVECTORCOM_H

#include <iostream>
#include <cmath>
#include "tcomplejo.h"

using namespace std;

class TVectorCom{
private:
    TComplejo *c;
    int tamano;
    TComplejo error;

public:
    //Constructores
    TVectorCom();
    TVectorCom(int);
    TVectorCom(const TVectorCom &);
    ~TVectorCom();

    //Operadores
    TVectorCom & operator=(const TVectorCom &);
    bool operator==(const TVectorCom &)const;
    bool operator!=(const TVectorCom &)const;
    TComplejo & operator[](int);
    TComplejo operator[](int) const;

    //Otros metodos
    int Tamano() const;
    int Cantidad() const;
    bool ExisteCom(const TComplejo &) const;
    void MostrarComplejos(double re)const;
    bool Redimensionar(int tam);
    int Ocupadas() const;

    //Operador salida
    friend ostream & operator<<(ostream &,const  TVectorCom &);

};

#endif // TVECTORCOM_H
