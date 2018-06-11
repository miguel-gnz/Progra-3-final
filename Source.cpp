#include <iostream>
#include <stdlib.h>

using namespace std;


struct Nodo {
	
	int dato;
	Nodo *der;
	Nodo *izq;

};

  
Nodo *crearNodo(int);
void insertarNodo(Nodo *&, int);


Nodo *arbol = NULL;

void main()
{

	int opcion;
	int dato;

	do
	{
		system("cls");
		cout << "\t\t ARBOLES BINARIOS\n\n\n";
		cout << "1. Insertar nodos\n";
		cout << "2. Eliminar nodos\n";
		cout << "3. Mostrar arbol\n";
		cout << "4. SALIR\n";
		cout << "Digite la opcion deseada: ";
		cin >> opcion;

		switch (opcion)
		{
		case 1:
			cout << "Digite un numero a insertar al arbol: ";
			cin >> dato;
			insertarNodo(arbol, dato);
			cout << "\n";
			system("pause");
			break;

		case 2:

			break;

		case 3:

			break;

		default:
			break;
		}
	} while (opcion != 4);

}


//Funcion para crear un nuevo nuevo
Nodo *crearNodo(int n)
{
	Nodo *nuevo_nodo = new Nodo();

	nuevo_nodo->dato = n;
	nuevo_nodo->der = NULL;
	nuevo_nodo->izq = NULL;

	return nuevo_nodo;
}


//Funcion para insertar Nodos en el arbol

void insertarNodo(Nodo *&arbol, int n)
{

	if (arbol == NULL)
	{
		Nodo *nuevo_nodo = crearNodo(n);
		arbol = nuevo_nodo;
	}
	else//si el arbol tiene un nodo o mas 
	{
		int valor_raiz = arbol->dato;
		if (n < valor_raiz)
		{
			insertarNodo(arbol->izq, n);
		}
		else
		{
			insertarNodo(arbol->der, n);
		}
	}

}


