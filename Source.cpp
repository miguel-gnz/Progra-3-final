#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;


struct nodo
{
	string nombre_arch;
	string usuario;
	int nro;
	struct nodo *sgte;
};

struct cola {
	nodo *delante;
	nodo *atras;
};

void encolar(struct cola &q, int valor, string user, string nombre)
{
	struct nodo *aux = new(struct nodo);

	aux->usuario = user;
	aux->nombre_arch = nombre;
	aux->nro = valor;
	aux->sgte = NULL;

	if (q.delante == NULL)
		q.delante = aux;
	else
		(q.atras)->sgte = aux;

	q.atras = aux;
}


//desencolar elemento
int desencolar(struct cola &q)
{
	int num;
	string user;
	string archivo;
	struct nodo *aux;

	aux = q.delante;
	num = aux->nro;
	user = aux->usuario;
	archivo = aux->nombre_arch;

	q.delante = (q.delante)->sgte;
	delete(aux);

	return num;

}
//mostrar cola
void muestraCola(struct cola q)
{
	struct nodo *aux;
	aux = q.delante;

	while (aux != NULL)
	{
		cout << "\n------------------------------------------------------------------------------------------------\n";
		cout << "Usuario: " << aux->usuario << "\t Direccion de memoria-> " << &aux->usuario;
		cout << "\nNombre de archivo: " << aux->nombre_arch << "\t Direccion de memoria-> " << &aux->usuario;
		cout << "\nNumero de Hojas: " << aux->nro << "\t Direccion de memoria-> " << &aux->usuario;

		aux = aux->sgte;
	}
}

// Eliminar todos los elementos de la cola
void vaciaCola(struct cola &q)
{
	struct nodo *aux;
	while (q.delante != NULL)
	{
		aux = q.delante;
		q.delante = aux->sgte;
		delete(aux);
	}
	q.delante = NULL;
	q.atras = NULL;
}
// menu de opciones
void menu()
{
	cout << "\n\t SIMULADOR DE COLA DE IMPRESIONES\n\n";
	cout << "1. ENCOLAR          " << endl;
	cout << "2. DESENCOLAR       " << endl;
	cout << "3. MOSTRAR COLA       " << endl;
	cout << "4. VACIAR COLA         " << endl;
	cout << "5. SALIR                " << endl;

	cout << " \n INGRESE OPCION:     ";
}


int main()
{
	struct cola q;
	q.delante = NULL;
	q.atras = NULL;

	int dato;
	int op;
	int x;

	string nombre;
	string usuario;

	system("color 0b");
	do {
		menu(); cin >> op;
		switch (op)
		{
		case 1:
			cout << "\n Usuario: "; cin >> usuario;
			cout << "\n Nombre de archivo: "; cin >> nombre;
			cout << "\n Numero de Hojas: "; cin >> dato;
			encolar(q, dato, usuario, nombre);
			cout << "\n\n\t\tDatos  " << "  ingresados...\n\n";
			break;
		case 2:
			x = desencolar(q);
			cout << "\n\n\t\tDatos  " << x << "  eliminados...\n\n";
			break;
		case 3:
			cout << "\n\n MOSTRANDO COLA DE IMPRESION \n\n";
			if (q.delante != NULL) muestraCola(q);
			else cout << " \n\n\t Cola vacia...!" << endl;
			break;
		case 4:
			vaciaCola(q);
			cout << "\n\n\t\t Hecho....\n\n";
			break;
		}
		cout << endl << endl;
		system("pause"); system("cls");

	} while (op != 5);
}