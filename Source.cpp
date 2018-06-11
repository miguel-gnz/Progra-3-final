#include <iostream>
#include <stdlib.h>
#include <Windows.h>
#include <conio.h>
#include <time.h>

using namespace std;

int pila[20];
/*VARIABLES A UTILIZAR PARA ELIMINACION EN FORMA DE PILA*/
int inicio, tope, final;
int num;
int ext, cabeza;

/*VARIABLES A UTILIZAR PARA ELIMINACION EN FORMA DE COLA*/
int punta = 1;
int finalCola;

void llenado() {

	system("cls");
	srand(time(NULL));
	for (int i = 0; i < 20; i++) {
		num = 97 + rand() % (20);

		int aux = 0;

		while (aux < i) {
			if (num != pila[aux]) {
				aux++;
			}
			else {
				num = 97 + rand() % (20);
				aux = 0;
			}
		}
		final++;
		pila[i] = num;
		pila[final] = num;
		cout << " "; cout << (char)pila[i];

	}
	cout << "\n";
	system("PAUSE");
}


void EliminarPila() {
	system("cls");
	if (final == 0) {
		cout << "Pila vacia";
	}
	else {
		cout << "Eliminando de la pila el valor: ";
		cout << (char)pila[final] << "\n\n";
		pila[final] = 0;
		final--;
	}
	system("pause");
}

void EliminarCola() {


	system("cls");
	int g = 0;


	if (pila[punta] == 0)
	{
		cout << "El vector se encuentra vacio, no procede...\n\n";
	}
	else
	{
		cout << "Eliminando del vector el valor: ";
		cout << (char)pila[punta] << "\n\n";
		pila[punta] = 0;
		punta++;
	}

	system("PAUSE");
}

void Recorrer() {
	system("cls");
	if (final == 0) {
		cout << "Vector vacio...\n\n\n";
	}
	else {
		for (int r = 1; r <= final; r++) {
			cout << "Posicion en el vector: ";
			cout << r;
			cout << ", Valor en posicion: ";
			cout << (char)pila[r];
			cout << "\n";
		}
	}
	system("PAUSE");
}


void main() {

	int opcion = 0;
	system("color F9");
	do
	{

		system("cls");
		cout << "\t\t....::::MANEJO DE PILAS Y COLAS CON MEMORIA ESTATICA::::....\n\n\n\n";
		cout << "1. Llenar vector" << endl;
		cout << "2. Mostrar datos en vector" << endl;
		cout << "3. Eliminar datos en forma de pila" << endl;
		cout << "4. Eliminar datos en forma de cola" << endl;
		cout << "5. SALIR\n\n";
		cout << "Digite la opcion deseada..." << endl;
		cin >> opcion;

		switch (opcion)
		{
		case 1:
			llenado();
			break;
		case 2: 
			Recorrer();
			break;
		case 3:
			EliminarPila();
			break;
		case 4:
			EliminarCola();
			break;
		default:
			cout << "Opcion no valida..." << endl;
			system("pause");
			break;
		}

	} while (opcion != 5);

}