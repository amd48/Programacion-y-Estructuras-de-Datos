#ifndef TCOMPLEJO_H
#define TCOMPLEJO_H

#include <iostream>
#include <cmath>

using namespace std;

class TComplejo{
private:
    double re,im;

public:
    //Constructores y destructor
    TComplejo();
    TComplejo(double);
    TComplejo(double,double);
    TComplejo(const TComplejo &);
   ~TComplejo();

   //Operadores
    TComplejo operator+(TComplejo &) const;
    TComplejo operator+(double)const;
    TComplejo operator-(TComplejo &) const;
    TComplejo operator-(double)const;
    TComplejo operator*(TComplejo &) const;
    TComplejo operator*(double)const;
    TComplejo& operator=(const TComplejo &);
    bool operator==(const TComplejo &) const;
    bool operator!=(const TComplejo &) const;
    bool operator>(const TComplejo &) const;
    bool operator<(const TComplejo &) const;
    friend TComplejo operator+(double,const TComplejo &);
    friend TComplejo operator-(double,const TComplejo &);
    friend TComplejo operator*(double,const TComplejo &);


    //Otros metodos
    double Re() const;
    void Re(double);
    double Im() const;
    void Im(double);
    double Mod(void) const;
    double Arg(void) const;

    //Operador salida
    friend ostream& operator<<(ostream &,const TComplejo &);

};


#endif // TCOMPLEJO_H
