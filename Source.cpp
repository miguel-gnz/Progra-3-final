#include <iostream>
#include <Windows.h>


using namespace std;



void gotoxy(int x, int y)
{
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hcon, dwPos);
}

HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

int b[5][5];

//PROTOTIPOS

void floyds(int b[][5]);
void inicio();
void ingreso();


int main()
{

	
	inicio();

	system("cls");
	
	ingreso();

	system("cls");

	floyds(b);

	gotoxy(20, 22);  system("pause");

	return 0;
}


void floyds(int b[][5])
{
	int i, j, k;
	for (k = 0; k < 5; k++)
	{
		for (i = 0; i < 5; i++)
		{
			for (j = 0; j < 5; j++)
			{
				if ((b[i][k] * b[k][j] != 0) && (i != j))
				{
					if ((b[i][k] + b[k][j] < b[i][j]) || (b[i][j] == 0))
					{
						b[i][j] = b[i][k] + b[k][j];
					}
				}
			}
		}
	}

	system("cls");

	SetConsoleTextAttribute(h, FOREGROUND_BLUE);
	cout << "\t\t\tRESULTADO\n\n\n";


	SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_BLUE);
	for (i = 0; i < 5; i++)
	{
		gotoxy(15, 8 + i);
		cout << "\t";
		for (j = 0; j < 5; j++)
		{
			cout  << b[i][j] << "\t";
		}
	}
}


void inicio()
{
	system("cls");

	SetConsoleTextAttribute(h, FOREGROUND_BLUE);
	gotoxy(20, 2);  cout << "GRAFOS (TERCER PROYECTO PARCIAL)";

	SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_BLUE);
	gotoxy(4, 8);  cout << "-Bienvenido, el siguiente programa le permitira digitar los elementos"; 
	gotoxy(4, 9);  cout << "de una matriz de adyacencia generada por los datos de un grafo de 5 nodos.";
	gotoxy(4, 11);  cout << "-Como resultado sera generada una nueva matriz indicando la ruta mas corta";
	gotoxy(4, 12);  cout << "hacia cada nodo por medio del metodo Floyd Warshall.";

	SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_RED);
	gotoxy(60, 21);  cout << "Miguel Gonzalez";
	gotoxy(60, 22);  cout << "Franklyn Escobar";
	gotoxy(60, 23);  cout << "Bryan Portillo";

	SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_BLUE);
	gotoxy(20, 17);  system("pause");
}

void ingreso()
{
	system("cls");


	SetConsoleTextAttribute(h, FOREGROUND_BLUE);
	cout << "\t\t\tINGRESO DE VALORES PARA LA MATRIZ DE ADYACENCIA\n\n\n";


	SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_BLUE);
	for (int i = 0; i < 5; i++)
	{
		cout << "Fila " << (i + 1) << "\n";
		for (int j = 0; j < 5; j++)
			
		{
			cin >> b[i][j];
			
		}
	}


	system("pause");
}