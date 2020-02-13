#include <iostream>
#include <stdlib.h>
#include <math.h>
#include "tvectorcom.h"

using namespace std;


//Constructor por defecto
TVectorCom::TVectorCom (){
    c = NULL;
    tamano = 0;
}

//Constructor por tamaño
TVectorCom::TVectorCom (int n){
    if(n > 0){
        tamano = n;
        c = new TComplejo[tamano];
    }
    else{
        c = NULL;
        tamano= 0;
    }
}

// Constructor de copia
TVectorCom::TVectorCom (const TVectorCom &t){
    if((t.tamano != 0) && (t.c != NULL)){
        tamano = t.tamano;
        c = new TComplejo[tamano];
        for(int i=0;i<t.tamano;i++)
            c[i] = t.c[i];
    }
    else{
        c = NULL;
        tamano = 0;
    }

}

//Destructor
TVectorCom::~TVectorCom (){
    if(c != NULL)
        delete [] c;
    tamano = 0;
    c = NULL;
}

//Sobrecarga del operador asignación
TVectorCom &TVectorCom::operator=(const TVectorCom & t){
    if(this != &t){
        this->~TVectorCom();
        if(t.tamano != 0){
            c = new TComplejo[t.tamano];
            tamano=t.tamano;
            for(int i=0;i<tamano;i++)
                c[i] = t.c[i];

        }
    }
    return(*this);
}

//Sobrecarga del operador igualdad
bool TVectorCom::operator==(const TVectorCom &t) const{
    bool b = true;

    if(this->tamano != t.tamano)
        b = false;
        else{

            for(int i=0;i<tamano;i++){
                if(c[i] != t.c[i])
                    b = false;}

    }
    return(b);
}



//Sobrecarga del operador desigualdad
bool TVectorCom::operator!=(const TVectorCom & t) const{
    bool b = false;
    if(this->tamano != t.tamano)
        b = true;
        else{
            for(int i=0;i<tamano;i++){
                if(c[i] != t.c[i])
                    b = true;}

    }
    return(b);
}

//Sobrecarga del operador corchete (parte IZQUIERDA)
TComplejo &TVectorCom::operator[](int n){
    if((n >= 1) && (n <= tamano) && (c != NULL))
        return c[n - 1];
    else
        return(error);
}

//Sobrecarga del operador corchete (parte DERECHA)
TComplejo TVectorCom::operator[](int n) const{
    if((n >= 1) && (n <= tamano) && (c != NULL))
        return c[n - 1];
    else
        return(error);
}

//Tamaño del vector (posiciones TOTALES)
int TVectorCom::Tamano() const{
    return(tamano);
}

//Cantidad de posiciones OCUPADAS (TComplejo NO VACIO) en el vector
int TVectorCom::Ocupadas() const{
    int n;
    for(int i=0;i<tamano;i++){
        if((c[i].Re() != 0) || (c[i].Im() != 0))
            n++;}
    return(n);
}

//Devuelve TRUE si existe el TComplejo en el vector
bool TVectorCom::ExisteCom(const TComplejo &t)const{
    bool b = false;

    for(int i=0;i++;i<tamano){
        if((c[i].Re() == t.Re()) && (c[i].Im() == t.Im()))
            b = true;}
    return(b);
}

//Mostrar por pantalla los elementos TComplejo del vector con PARTE REAL IGUAL
void TVectorCom::MostrarComplejos(double n) const{
    bool b = true;

    cout << "[";
    for(int i = 0; i < tamano; i++){
        if(c[i].Re() >= n){
            if(b){
                cout << c[i];
                b = false;
            }
            else{
                cout << ", " << c[i];
            }
        }
    }
    cout << "]";
}


//REDIMENSIONAR el vector de TComplejo
bool TVectorCom::Redimensionar(int n){
    bool b = false;
    TComplejo *aux = NULL;

    if((tamano != n) && (n > 0)){
        b = true;
        aux = new TComplejo [n];
        for(int i = 0; i < n && i < tamano; i++){
            aux[i] = c[i];
        }
        if(c != NULL){
            delete []c;
            c = NULL;
        }
        c = aux;
        tamano = n;
    }
    return(b);
}



//Sobrecarga del operador salida
ostream & operator<<(ostream &salida,const TVectorCom &t){
    salida<<"[";
    for(int i=0;i< t.tamano;i++){
        salida << "(" << i + 1 << ") " << t.c[i];
        if(i < (t.tamano - 1))
            salida << ", ";}
    salida<<"]";
    return(salida);
}
