
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
	aprod = fopen("Ventas de productos.dat", "wb");

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
	aprod = fopen("Ventas de productos.dat","rb");

	fread (&rprod, sizeof(rprod), 1, aprod);
	while (!feof (aprod)) {
		cout << "Codigo de producto: " << rprod.codp << endl;
		cout << "Precio de producto: " << rprod.PU << endl;
		cout << "Stock de producto:  " << rprod.stk << endl;
		fread (&rprod, sizeof(rprod), 1, aprod);
	}
	fclose (aprod);
};


void ProdVec(tprod VP[], int&n){
    tprod rprod;
    FILE *aprod;
    int i =0;
    aprod=fopen ("Ventas de productos.dat", "rb");

	while (fread (&rprod, sizeof(rprod), 1, aprod)) {
		VP[i] = rprod;
		i=i+1;
	}

    n=i;
    fclose(aprod);
};


void ActualizarProd(tprod VP[], int&n){
    int i;
    FILE *aprod;
    tprod rprod;
    aprod=fopen("Ventas de productos.dat","rb+");

    for (i=0 ; i<=n; i++) {
    	rprod = VP[i];
    	fwrite(&rprod, sizeof(rprod), 1, aprod);
    }
    fclose(aprod);
}



int main(){
	int N;
	int codp,cant;
	tprod VP[30], rprod;
	int opc=-1;

	cout << "PROGRAMA DE VENTA DE PRODUCTOS" << endl;

	do{
		cout << "Ingrese la operacion que desea realizar" << endl;
		cout << "1)Crear archivo productos" << endl;
		cout << "2)Leer archivo de productos" << endl;
		cout << "3)Ejercicio 78" << endl;
		cout << "0)Salir del programa" << endl;
		cin >> opc;

		switch (opc){
			case 0:
				cout << "Gracias por utilizar nuestro programa" << endl;
				break;
			case 1:
				Generararchivo();
				break;
			case 2:
				Leerarchivo();
				break;
			case 3:
				ProdVec(VP,N);
				cout << "Ingrese codigo de producto (0 para cortar): " << endl;
				cin >> rprod.codp;
				while (codp!=0){
					cout << "Ingrese cantidad: " << endl;
					cin >> cant;

					cout << "Ingrese codigo de producto (0 para cortar): " << endl;
					cin >> codp;
				};

				ActualizarProd(VP,N);

				cout << "Los productos quedaron: " << endl;
				Leerarchivo();
				break;
			default:
				cout << "Error! Por favor, ingrese una opcion valida" << endl;
				break;
		}
	}
	while (opc!=0);
	return 0;
}
