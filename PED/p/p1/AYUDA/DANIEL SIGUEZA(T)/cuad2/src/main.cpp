//============================================================================
// Name        : main.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include "tcalendario.h"
#include "tvectorcalendario.h"
#include <iostream>

using namespace std;

int main() {

	char c[] = "jelouuu";
	TCalendario TCal(14,5,1992,c);


	TCalendario Tcalp(TCal);
	Tcalp = TCal;

	cout << Tcalp <<endl;
	cout << TCal << endl;

	TCal + 500;
	cout << TCal<<endl;

	//TCal = Tcalp - 500;
	//cout << TCal<<endl;

	TCal++;
	cout << TCal <<endl;

	TCalendario def;

	cout << "RESTAR CALENDARIO "<< def << endl;
	def = def - 500;
	--def;
	cout << def <<endl;
	cout << "----------------"<<endl;
	cout << TCal <<endl;
	TCalendario TCal2(14,5,1992,c);
	cout << TCal2<<endl;
	TCal2 - 500;
	cout << TCal2<<endl;
	cout << "----------------"<<endl;
	TCalendario mayor;
	mayor +500;
	TCalendario menor;
	cout << "-----------------"<<endl;
	cout << "Resta "<< endl;
	
	TCalendario cal(2,6,2015,"");
	cout << cal << " " << cal-14418 <<endl;
	
	
	cout << "Suma" << cal+14418 << " 2/6/2015" <<endl;
	cout <<"-------------------"<<endl;
	cout << (mayor>menor) << " mayor menor"<<endl;
	cout << (menor>mayor) << " mayor menor"<<endl;
	cout << (menor<mayor) << " menor mayor"<<endl;
	cout << (mayor<menor) << " menor mayor"<<endl;
	cout << "----------------"<<endl;
	TVectorCalendario TV(4);
	TV[0] =TCal;
	TV[1] =TCal;
	TV[2] =TCal;
	TV[3] =TCal;


	TVectorCalendario TV2(4);
	TV2[1] =TCal;
	TV2[2] =TCal;
	TV2[3] =Tcalp;

	cout << TV.Tamano()<<endl;

	TV.ExisteCal(Tcalp);

	TV.MostrarMensajes(14,3,1992);
	cout << "----------------"<<endl;
	cout<<TV<<endl;

	TV.Redimensionar(3);

	cout<<TV<<endl;


	return 0;
}

