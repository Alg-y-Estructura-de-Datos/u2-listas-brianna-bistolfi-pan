/*Crear un programa que pida al usuario dar elementos a una Lista de números enteros. Luego
cree una función que reciba una lista int L1 y devuelva otra lista int L2 conteniendo los elementos
repetidos de L1. Por ejemplo, si L1 almacena los valores 5->2->7-> 2->5->5->1, debe construirse
una lista L2 con los valores 5->2. Si en L1 no hay elementos repetidos se debe indicar al usuario
que no hay elementos repetidos en L1, de lo contrario imprimir ambas listas.
*/

#include <iostream>
#include "Lista/Lista.h"
using namespace std;

void nuevalistarepetida(Lista<int> &lista, Lista<int> &copia) {
    for (int i = 0; i < lista.getTamanio(); ++i) {
        for (int j = i + 1; j < lista.getTamanio(); ++j) {
            if (lista.getDato(i) == lista.getDato(j)) {
                // Verificar si el valor ya está en la lista de copias
                bool encontrado = false;
                for (int k = 0; k < copia.getTamanio(); ++k) {
                    if (copia.getDato(k) == lista.getDato(i)) {
                        encontrado = true;
                        break;
                    }
                }
                if (!encontrado) {
                    copia.insertarUltimo(lista.getDato(i));
                }
                break; // No es necesario seguir comparando con otros elementos
            }
        }
    }
}

int main() {
    Lista<int> lista;
    Lista<int> copia;
    int n;
    int tam;

    cout << "ingrese cantidad de numeros a dictar: " << endl;
    cin >> tam;

    for (int i = 0; i < tam; ++i) {
        cout << "ingrese numero " << i + 1 << endl;
        cin >> n;
        lista.insertarPrimero(n);
    }

    nuevalistarepetida(lista, copia);


    if (copia.esVacia()) {
        cout << "No hay numero repetido" << endl;
    } else {
        cout << "Lista de numeros repetidos: " << endl;
        copia.print();
    }
}
