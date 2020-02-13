#include <iostream>
#include <stdlib.h>
#include <math.h>
#include "tcomplejo.h"

using namespace std;

//Constructor por defecto
TComplejo::TComplejo(){
    re=0;
    im=0;
}

//Constructor por parametros (Real)
TComplejo::TComplejo(double x){
    re=x;
    im=0;
}

//Constructor por parametros (Real,Imaginario)
TComplejo::TComplejo(double x, double y){
    re=x;
    im=y;
}

//Constructor copia
TComplejo::TComplejo(const TComplejo &c){
    re=c.re;
    im=c.im;
}

//Destructor
TComplejo::~TComplejo(){
    re=0;
    im=0;
}

//Operador suma (2 complejos)
TComplejo TComplejo::operator+ (TComplejo &c) const{
    TComplejo sum;
    sum.re = re + c.re;
    sum.im = im + c.im;
    return(sum);
}

//Operador suma (Complejo y parte real)
TComplejo TComplejo::operator+ (double x) const{
    TComplejo sum;
    sum.re = re + x;
    sum.im= im;
    return(sum);
}

//Operador resta (2 complejos)
TComplejo TComplejo::operator- (TComplejo &c) const{
    TComplejo res;
    res.re = re - c.re;
    res.im = im - c.im;
    return (res);
}

//Operador resta (Complejo y parte real)
TComplejo TComplejo::operator- (double x)const{
    TComplejo res;
    res.re = re - x;
    return(res);
}

//Operador multiplicacion (2 complejos)
TComplejo TComplejo::operator* (TComplejo &c) const{
    TComplejo mul;
    mul.re = (re * c.re) - (im * c.im);
    mul.im = (re * c.im) + (im * c.re);
    return(mul);
}

//Operador multiplicacion (Complejo y numero)
TComplejo TComplejo::operator* (double x) const{
    TComplejo mul;
    mul.re = re * x;
    mul.im = im * x;
    return(mul);
}

//Operador asignacion
TComplejo& TComplejo::operator= (const TComplejo &c){
    re=c.re;
    im=c.im;
    return(*this);
}

//Operador comparacion
bool TComplejo::operator== (const TComplejo &c)const{
    bool b;
    if((c.re == re)&&(c.im == im))
        b = true;
    else
        b = false;
    return(b);
}

//Operador desigualdad
bool TComplejo::operator!= (const TComplejo &c)const{
    bool b;
    if((c.re == re)&&(c.im == im))
        b = false;
    else
        b = true;
    return(b);
}


//Devuelve la parte real
double TComplejo::Re() const{
    return(re);
}

//Devuelve la parte imaginaria
double TComplejo::Im()const{
    return(im);
}

//Modifica la parte real
void TComplejo::Re(double x){
    re = x;
    return;
}

//Modifica la parte imaginaria
void TComplejo::Im(double x){
    im = x;
    return;
}

//Calcula el argumeno (Radianes)
double TComplejo::Arg(void) const{
    double arg;
    if(re==0 && im==0)
        arg=0;
    else
        arg = atan2(im,re);
    return(arg);
}

//Calcula el modulo
double TComplejo::Mod(void) const{
    double mod;
    mod=sqrt(pow(re,2.0)+pow(im,2.0));
    return(mod);
}

//Operador salida
ostream & operator<<(ostream & salida,const TComplejo & c){
    salida<<"("<<c.re<<" "<<c.im<<")";
    return(salida);
}

//Operador suma (double+Complejo)
TComplejo operator+ (double n,const TComplejo &c){
    TComplejo res;
    res.re=c.re+n;
    res.im=c.im;
    return(res);
}

//Operador resta (double-Complejo)
TComplejo operator- (double n,const TComplejo &c){
    TComplejo res;
    res.re=c.re-n;
    res.im=c.im;
    return(res);
}

//Operador multiplicacion (double*Complejo)
TComplejo operator* (double n,const TComplejo &c){
    TComplejo res;
    res.re=c.re*n;
    res.im=c.im*n;
    return(res);
}

