
#include <iostream>
#include <stdio.h>
using namespace std;


struct tprod {
	int codp;
	float PU;
	int cantv;
	int stk;
};

//este metodo sirve para crear el archivo que se leera durante el ejercicio
void Generararchivo() {
	tprod rprod;
	FILE *aprod;
	int i = 0;
	aprod = fopen("listaprod.dat", "w+b"); //fopen genera el archivo, el modo w+b hace que se genere un archivo del tipo binario
	cout << "Ingrese codigo de producto (0 para cortar)" << endl;
	cin >> rprod.codp;
	while (rprod.codp!=0 && i > 30){
		cout << "Ingrese precio de producto" << endl;
		cin >> rprod.PU;
		cout << "Ingrese stock de producto" << endl;
		cin >> rprod.stk;
		fwrite (&rprod, sizeof(rprod), 1, aprod);
		i++;
		cout << "Ingrese codigo de producto (0 para cortar)" << endl;
		cin >> rprod.codp;
	};
	if(i>=29){
		cout<<"se supero el limite de productos";
	}
	fclose (aprod);
};

//se lee el archivo, y se guarda en el array VP para despues usarlo y tambien el int N
void LeerArchivo (tprod VP[30], int &N) {
   FILE *aprod = fopen ("listaprod.dat", "r+b");//r+b es para lectura del archivo
   tprod rprod;
   if (aprod == NULL) {
      cout << "ERROR! No existe el archivo" << endl;
      return;
   }
      fread (&rprod, sizeof (rprod), 1, aprod);
      while (!feof (aprod)){   // feof se da cuenta que lleg al final del archivo slo cuando intenta leer y la operacion falla
     	cout << "Codigo de producto: " << rprod.codp<<endl;
        cout << "Precio de producto" << rprod.PU << endl;
		cout << "Stock de producto" << rprod.stk << endl;
		VP[N] = rprod;
		N++;
        fread (&rprod, sizeof (rprod), 1, aprod);
};
		fclose (aprod);
};

void Pedidos(tprod VP[30]){
	int codp,cant;
	cout<<"Ingrese codigo de producto (0 para cortar): "<<endl;
	cin>>codp;
	int size = sizeof(VP);
	while (codp!=0){
		cout<<"Ingrese cantidad: "<<endl;
		cin>>cant;
		//busca dentro del array el producto con el codigo
		for (int i = 0; i < size; ++i) {
        		if(VP[i].codp==codp){
					if(VP[i].stk>=cant){
						VP[i].stk=VP[i].stk-cant;
					}else{
						cout<<"No hay stock";
					}
					
				} else {
					cout << "no existe el producto"
				}
		}
		cout<<"Ingrese codigo de producto (0 para cortar): "<<endl;
		cin>>codp;
		}
	
}

int main () {
   int opc = -1;
   int N = 0;
   tprod VP[30];
   do {
      cout<<"Ingrese la opcion deseada"<<endl;
      cout<<"1) Generar archivo"<<endl;
	  cout<<"2) Ejercicio 78"<<endl;
      cout<<"0) Salir"<<endl;
      cin >> opc;

      switch (opc) {
         case 0:
            cout<<"Muchas gracias por utilizar el programa"<<endl;
            break;
         case 1:
            Generararchivo();//generamos el archivo
            break;
         case 2:
            LeerArchivo(VP, N);//leemos el archivo y cargamos todo a VP, tambien obtenemos N
			Pedidos(VP);
			break;
		case 3:
            break;
            cout <<"ERROR! La opcion seleccionada es invalida"<<endl;
            break;
      }
   }
   while (opc != 0);
   return 0;
}