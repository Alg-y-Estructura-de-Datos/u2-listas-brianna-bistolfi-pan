#include <iostream>
#include <string>
#include "Lista/CircList.h"
#include <thread>

using namespace std;

void monitorpublictario(CircList<string> &lista) {
    if (lista.esVacia()) {
        cout << "no hay nada que mostrar" << endl;
        return;
    } //si no esta, larga error

    int i = 0;

    while (true) {
        cout << lista.getDato(i) << endl;
        i = (i + 1) % lista.getTamanio(); //vuelve a empezar desde el priper elemento una vez que llego alultimo
    }
}

int main() {
    CircList<string> lista;
    lista.insertarUltimo("hola como estas");
    lista.insertarUltimo("la cena esta lista");
    lista.insertarUltimo("hace frio para salir");
    string frase;
    int op;
    do {
        cout << "que operacion desea realizar? " << endl;
        cout << "1. Agregar Frase " << endl;
        cout << "2. Eliminar Frase " << endl;
        cout << "3. Mosrar frases " << endl;
        cout << "4. salir del programa" << endl;
        cin >> op;


        cin.ignore();

        switch (op) {
            case 1: cout << "ingrese la frase que desea agregar: " << endl;
                getline(cin, frase);
                lista.insertarUltimo(frase);
                break;
            case 2: cout << "ingrese la frase que desea eliminar : " << endl;
                getline(cin, frase);
                lista.eliminarPorValor(frase);
                break;
            case 3: monitorpublictario(lista);
                break;
            case 4: exit(1);
            default: cout << "error en la opcion" << endl;
                break;
        }
    } while (op > 0 && op < 4);

    return 0;
}
