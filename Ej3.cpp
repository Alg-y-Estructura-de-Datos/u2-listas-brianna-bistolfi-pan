/*Implementar una función que intercambie los elementos entre 2 listas de números enteros que
recibe como parámetros. Si los tamaños de las listas son distintos, igual debe cambiar los datos
y cambiarían los tamaños de cada lista. Ejemplo sea lista1= 15->1->8->35->40->25->12 y lista2=
3->4->912->45->66 al ejecutar la función quedarían lista1= 3->4->912->45->66 y lista2=15->1->8-
>35->40->25->12.*/
#include <iostream>
#include "Lista/Lista.h"
using namespace std;

void intercambio(Lista<int> &lista1, Lista<int> &lista2) {
    Lista<int> aux;
    int tamanio = lista1.getTamanio();

    for (int i = 0; i < lista1.getTamanio(); i++) {
        aux.insertarUltimo(lista1.getDato(i));
    }
    lista1.vaciar();
    for (int i = 0; i < lista2.getTamanio(); i++) {
        lista1.insertarUltimo(lista2.getDato(i));
    }
    lista2.vaciar();
    for (int i = 0; i < tamanio; i++) {
        lista2.insertarUltimo(aux.getDato(i));
    }
    aux.vaciar();
}


int main() {
    Lista<int> lista1;
    Lista<int> lista2;

    int t1, t2;
    int d1, d2;

    cout << "ingrese tamanio de lista uno " << endl;
    cin >> t1;
    cout << "ingrese tamanio de lista dos " << endl;
    cin >> t2;

    for (int i = 0; i < t1; i++) {
        cout << "ingrese elemento " << i + 1 << " de lista 1: " << endl;
        cin >> d1;
        lista1.insertarUltimo(d1);
    }

    for (int i = 0; i < t2; i++) {
        cout << "ingrese elemento " << i + 1 << " de lista 2: " << endl;
        cin >> d2;
        lista2.insertarUltimo(d2);
    }

    cout << "Listas Originales: " << endl;
    cout << "Lista 1: " << endl;
    lista1.print();
    cout << "Lista 2: " << endl;
    lista2.print();

    intercambio(lista1, lista2);

    cout << "Listas Intercambiadas: " << endl;
    cout << "Lista 1: " << endl;
    lista1.print();
    cout << "Lista 2: " << endl;
    lista2.print();

    return 0;
}
