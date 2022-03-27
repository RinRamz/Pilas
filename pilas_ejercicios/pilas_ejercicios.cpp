//Ejercicios de pilas
#include <iostream>

struct Nodo 
{
	int dato;
	Nodo* siguiente;
};

void push(Nodo*&, int);
void pop(Nodo*&, int&);
void menu(Nodo*&);
void mostrarPila(Nodo*&, int);

int main()
{
	Nodo* pila = NULL;
	menu(pila);
}

void menu(Nodo*& pila)
{
	int opc = 0;
	int dato = 0;
	do
	{
		std::cout << "\t.Menu.\n";
		std::cout << "Que desea hacer?: \n"; std::cout << "1. Agregar elementos a la pila.\n" << "2.Quitar elementos de la pila.\n" << "3.Mostrar la pila.\n" << "4.Salir.\n";
		std::cin >> opc;
		switch (opc)
		{
		case 1:
			std::cout << "Digite el numero que quiere agregar a la pila: \n";
			std::cin >> dato;
			push(pila, dato);
			system("pause");
			break;
		case 2:
			if (pila == NULL)
			{
				std::cout << "La pila esta vacia, primero agrega algunos datos.\n";
			}
			else
			{
				pop(pila, dato);
			}
			system("pause");
			break;
		case 3:
			if (pila == NULL)
			{
				std::cout << "La pila esta vacia, primero agrega algunos datos.\n";
			}
			else
			{
				mostrarPila(pila, dato);
			}
			system("pause");
			break;
		}
		system("cls");
	} while (opc!=4);
	
}

void push(Nodo*& pila, int n)
{
	Nodo* nuevo_nodo = new Nodo();
	nuevo_nodo->dato = n;
	nuevo_nodo->siguiente = pila;
	pila = nuevo_nodo;

	
}

void pop(Nodo*& pila, int& n)
{
	Nodo* aux = pila;
	n = aux->dato;
	pila = aux->siguiente;
	delete aux;
}

void mostrarPila(Nodo*& pila, int n)
{
	while (pila != NULL)
	{
		pop(pila, n);
		if (pila != NULL)
		{
			std::cout << n << ",";
		}
		else
		{
			std::cout << n << ".\n";
		}
	}
}