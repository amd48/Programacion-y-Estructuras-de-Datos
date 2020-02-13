#include <iostream>
#include "tabbcom.h"
#include "tcomplejo.h"
#include "tvectorcom.h"
using namespace std;
/*
		    5
	    3		7
	  1	 4        9
                 8 10
*/

int
main(void){
  TABBCom a;
  TComplejo v [] = {TComplejo(5, 5), TComplejo(3, 3), TComplejo(7, 7), TComplejo(1, 1), 
					TComplejo(4, 4), TComplejo(9, 9), TComplejo(10, 10), TComplejo(8, 8)};

	for(int i = 0; i < 8; i++){
		a.Insertar(v[i]);
	}
	
	cout << "camino mes llarg: " << a.CaminoMasLargo() << endl;

	cout << "nodos con dos hijos: " << a.DosHijos() << endl;

	cout << a.Simetrico(TComplejo(9, 9)) << endl;	
	cout << a.Simetrico(TComplejo(7, 7)) << endl;
	cout << a.Simetrico(TComplejo(3, 2)) << endl;
	
	cout << "preorden: " << a.Preorden() << endl;
	cout << "inorden: " << a.Inorden() << endl;
	cout << "niveles: " << a.Niveles() << endl;  

	cout << "eliminar ultimo nivel" << endl;
	cout << "eliminados: " << a.EliminarUltimoNivel() << endl;
	cout << "niveles: " << a.Niveles() << endl;
/*
	cout << "prueba lista hojas" << endl;
	TVectorCom vc(3);
	vc[1] = TComplejo(1, 1);
	vc[2] = TComplejo(8, 8);
	vc[3] = TComplejo(9, 9);
	cout << "hojas: ";
	cout << a.listaHojas(vc) << endl;
*/

/*
	TListaCom li;
	
	li.InsCabeza(TComplejo(5,5));
	li.InsCabeza(TComplejo(3,3));
	li.InsCabeza(TComplejo(10,12));
	li.InsCabeza(TComplejo(8,8));

	int *jose = a.marcar(li);
	for(int i = 0; i < 4; i++){
		cout << jose[i] << " ";
	}
	cout << endl;
*/
	return 1;
}


