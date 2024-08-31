/*Implementar una función llamada “printLista” que reciba una lista y una posición “p” e imprima
los elementos de esa lista a partir de la posición “p”. No debe modificarse la lista original.
Ej: listaOriginal: 1->2->3->4->5->6->7->8->9->10 con p=5 Por pantalla se verá: 6->7->8->9->10*/

#include <iostream>
#include "Lista/Lista.h"

using namespace std;

void printLista(Lista<int> &lista, int p) {
    int tamanio = lista.getTamanio();//obtener el tamano de la lista

    //CONTROL: el usuario podria mandar otra posicion fuera de los limites de la lista (mayor, menor, igual)
    if (p >= tamanio || p < 0) {
        cout << "La posición " << p << " está fuera de los límites de la lista." << endl;
        return; //aborto la funcion (se puede abortar con un return)
    }

    for (int i = p; i < tamanio; i++) { //i=p desde la posicion que mando el usuario
        cout << lista.getDato(i) << "->";//get dato es una funcion que me pide que le pase una posicion entera, y le paso i.
        //me da el dato del nodo q esta en dicha posicion
    }  //flechita es un decorado. simbolo de puntero (apunta al siguiente nodo)
    cout << "NULL" << endl; //particularidad de nuestra lista
}

int main() {
Lista<int> lista1; //lista de tipo entero, la llamo lista1 //construi lista vacia, objeto lista
    int n, d, p;


    cout << "ingrese el tamanio de la lista" << endl;
    cin>>n;


    for(int i=0; i<n; ++i) {
        cout << "ingrese el valor de la lista en la posicion: "<<i+1<< endl; //lleno la lista, deja de ser vacia
        cin >> d;
        lista1.insertarUltimo(d);
    }

    cout << "ingrese desde que posicion desea imprimir la lista: " << endl;
    cin>>p;

    printLista(lista1, p);
    return 0;
}

//la lista NO sabe Su tamaño!