
#include <iostream>
#include <stdio.h>
using namespace std;


struct tprod {
	int codp;
	float PU;
	int cantv;
	int stk;
};


void Generararchivo() {
	tprod rprod;
	FILE *aprod;
	aprod = fopen("listaprod.dat", "w+b");

	cout << "Ingrese codigo de producto (0 para cortar)" << endl;
	cin >> rprod.codp;
	while (rprod.codp!=0){
		cout << "Ingrese precio de producto" << endl;
		cin >> rprod.PU;
		cout << "Ingrese stock de producto" << endl;
		cin >> rprod.stk;
		fwrite (&rprod, sizeof(rprod), 1, aprod);
		cout << "Ingrese codigo de producto (0 para cortar)" << endl;
		cin >> rprod.codp;
	};
	fclose (aprod);
};


void Leerarchivo() {
	tprod rprod;
	FILE *aprod;
	aprod = fopen("listaprod.dat","r+b");
	
	fread (&rprod, sizeof(rprod), 1, aprod);
	while (!feof (aprod)) {
		cout << "codigo de producto" << rprod.codp << endl;
		cout << "Precio de producto" << rprod.PU << endl;
		cout << "Stock de producto" << rprod.stk << endl;
		fread (&rprod, sizeof(rprod), 1, aprod);
	}
	fclose (aprod);
};


void Prodvec (tprod VPU[] , int & n) {
    tprod rprod;
    int i =0;
    FILE *ProdV
    ProdV = fopen (" Ventas de productos.dat"; "rb");
    while (fread (&rprod,sizeof(rprod),i , ProdV);
           VPU[i] = rprod;
           i=i+1;
    );
    n=i;
    fclose(ProdV);
};

void Actualizarprod (tprod VP[], int & n) {
    int i;
    FILE *ProdV;
    ProdV = fopen("Ventas productos";"rb");
    tprod rprod;
    
    for (i=0, i<=n , i++) {
        rprod = VP[i]   
    fwrite (&rprod, sizeof(rprod),1,ProdV)    
    }   
    flose = ProdV
}



int main(){
	int N;
	tprod vprod[30];
	int opc=-1;

	cout << "PROGRAMA DE VENTA DE PRODUCTOS" << endl;

	do{
		cout << "Ingrese la operacion que desea realizar" << endl;
		cout << "1)Crear archivo productos" << endl;
		cout << "2)Leer archivo de productos" << endl;
		cout << "3)Ejercicio 78" << endl;
		cout << "0) Salir del programa" << endl;
		cin >> opc;

		switch (opc){
			case 0:
				cout << "Gracias por utilizar nuestro programa" << endl;
			case 1:
				Generararchivo();
			case 2:
				Leerarchivo();
			case 3:

		}
	}


return 0;
}
