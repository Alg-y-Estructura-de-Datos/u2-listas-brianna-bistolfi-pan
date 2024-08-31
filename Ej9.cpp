#include <iostream>
#include <string>
#include "Lista/ListaDoble.h"
using namespace std;


void añadirpagina(ListaDoble<string> &lista, int &posicionactual) {
    string pagina;
    cout << "ingrese la pagina que desea agregar: " << endl;
    getline(cin, pagina);
    lista.insertarUltimo(pagina);
    posicionactual++;
}

void mostrarhistorial(ListaDoble<string> &lista) {
    lista.imprimir();
}

void retroceder(ListaDoble<string> &lista, int &posicionactual) {
    if (posicionactual >= 1) {
        cout << lista.getDato(posicionactual - 1) << endl;
        posicionactual = posicionactual - 1;
    }
}

void avanzar(ListaDoble<string> &lista, int &posicionactual) {
    if (posicionactual < lista.getTamanio()) {
        cout << lista.getDato(posicionactual + 1);
        posicionactual++;
    }
}

int main() {
    ListaDoble<string> lista;
    string url;
    int posicionactual = -1;
    int op;
    do {
        cout << endl;
        cout << "que desea realizar? " << endl;
        cout << "1. Añadir pagina " << endl;
        cout << "2. Mostrar el historial " << endl;
        cout << "3. Retroceder " << endl;
        cout << "4. Avanzar " << endl;
        cout << "5. Salir del programa " << endl;
        cin >> op;


        cin.ignore();

        switch (op) {
            case 1: añadirpagina(lista, posicionactual);
                break;
            case 2: mostrarhistorial(lista);
                break;
            case 3: retroceder(lista, posicionactual);
                break;
            case 4: avanzar(lista, posicionactual);
                break;
            case 5: exit(1);
            default: cout << "error en la opcion" << endl;
                break;
        }
    } while (op > 0 && op < 5);

    return 0;
}
