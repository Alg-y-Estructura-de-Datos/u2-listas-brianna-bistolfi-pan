/*
Escribir un programa que pida al usuario una palabra o frase y la almacene en una Lista
separando letra por letra, luego pedirá al usuario una vocal que desee contar y, por último, se
debe imprimir por pantalla la lista y el número de veces que aparece la vocal en la palabra o
frase. Validar que la Lista no esté vacía y que la letra a contar que introduzca el usuario sea una
vocal.
*/

#include <iostream>
#include <string>
#include "Lista/Lista.h"

using namespace std;

int listavocal(const string &palabra, Lista<char> &lista, char vocal) {
    int contador = 0;

    for (char c: palabra) {
        lista.insertarUltimo(c);
        if (c == vocal) {
            contador++;
        }
    }

    if (lista.esVacia()) {
        cout << "La lista está vacía. No hay nada que contar." << endl;
        return 0;
    }

    return contador;
}

int main() {
    Lista<char> lista;
    string palabra;
    char vocal;

    cout << "ingrese palabra o frase en minuscula: " << endl;
    getline(cin, palabra);

    cout << "ingrese vocal que desea buscar: " << endl;
    cin >> vocal;


    int respuesta = listavocal(palabra, lista, vocal);
    cout << "la cantidad de vocales en la palabra es: " << respuesta;
    cout << endl;

    cout << "Lista: ";
    lista.print();
}
