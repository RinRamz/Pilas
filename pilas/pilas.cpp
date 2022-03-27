//pilas, conocidas como estructura LIFO (Last input, first output)
#include <iostream>
//Nuestra estructura nodo tiene dos partes, el dato a almacenar y el puntero al dato siguiente
struct Nodo
{
	int dato;
	Nodo* siguiente;
};

void push(Nodo*&, int);
void pop(Nodo*&, int&);

int main()
{
	Nodo* pila = NULL; //creamos un puntero pila de tipo nodo, lo igualamos a null pues hasta el momento el nodo esta vacio
}
/*
Insertar datos a una pila consta de 4 pasos:
1.Crear el espacio en memoria para almacenar unn nodo. (new)
2.Cargar el valor dentro del nodo (dato).
3.Cargar el puntero pila dentro del nodo (*siguiente).
4.Asignar el nuevo nodo a pila.
*/
void push(Nodo*& pila, int n)
{
	Nodo *nuevo_nodo = new Nodo(); //creamos el espacio en memoria para almacenar el nuevo nodo
	nuevo_nodo->dato = n; //cargamos el valor del dato dentro del nuevo nodo
	nuevo_nodo->siguiente = pila; // cargamos el puntero dentro del nodo para apuntar al siguiente nodo (en caso de ser el primero apuntara a NULL
	pila = nuevo_nodo; //esto lo hacemos porque el puntero pila siempre tiene que estar señalando la cima
}

/*
Para quitar elementos de una pila tambien se siguen 4 pasos:
1.Crear una variable auxiliar de tipo Nodo que apunte a pila (la cima).
2.Igualamos n a aux->dato, el valor que contiene el dato, el valor a eliminar.
3.Pasar pila al siguiente nodo, pues si eliminamos directamente el nodo, pila no estaria señalando a nada
4.Elimanos el nodo con delete
*/
void pop(Nodo*& pila, int &n)
{
	Nodo* aux = pila; //creamos e igualamos la varible auxiliar a pila para que apunte al nodo que esta en la cima
	n = aux->dato; //igualmos n al valor contenido dentro de dato del nodo señalado por aux
	pila = aux->siguiente; //igualamos pila al nodo siguiente en la pila, dejando a aux como la unica variable que apunta al nodo en la cima
	delete aux;//al solo tener aux señalando la cima, lo podemos eliminar sin problema alguno
}