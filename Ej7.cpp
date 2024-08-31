/*
Utiliza la clase ListaDoble para gestionar una lista de estudiantes, donde cada estudiante
tiene un nombre (cadena de caracteres) y una edad (entero). Implementa las siguientes
funcionalidades:
1. Agregar Estudiantes:
○ Usa los métodos de ListaDoble para agregar varios estudiantes a la lista.
Debes insertar al menos cinco estudiantes con nombres y edades diferentes.
2. Mostrar Estudiantes:
○ Implementa una función que recorra la lista y muestre todos los estudiantes en
orden. Utiliza el metodo imprimir() de ListaDoble.
3. Buscar un Estudiante por Nombre:
○ Implementa una función que busque un estudiante por su nombre. Utiliza el
metodo getDato(int pos) para acceder a los datos de los nodos y busca al
estudiante en la lista.
4. Eliminar un Estudiante por Nombre:
○ Implementa una función que elimine un estudiante por su nombre. Utiliza los
métodos getDato(int pos) y remover(int pos) para encontrar y
eliminar al estudiante de la lista.
5. Contar Estudiantes:
○ Usa el metodo getTamanio() para contar el número de estudiantes en la lista
y muestra el resultado
 */


#include <iostream>
#include <string>
#include "Lista/ListaDoble.h"
using namespace std;

class estudiantes {
public:
    string nombre;
    int edad;

    estudiantes(): nombre(""), edad(0) {
    }

    estudiantes(const string &nom, const int &ed): nombre(nom), edad(ed) {
    }

    friend ostream &operator<<(ostream &os, const estudiantes &est) {
        os << "nombre: " << est.nombre << " , edad: " << est.edad;
        return os;
    }
};

void agregarestudiante(ListaDoble<estudiantes> &lista) {
    string nombre;
    int edad;
    cout << "ingrese nombre de estudiante: " << endl;
    cin.ignore();
    getline(cin, nombre);
    cout << "ingrese edad del estudiante: " << endl;
    cin >> edad;

    lista.insertarUltimo(estudiantes(nombre, edad));
}

void mostrarestudiantes(ListaDoble<estudiantes> &lista) {
    if (lista.esVacia()) {
        cout << "La lista esta vacia, no hay nada que mostrar" << endl;
    }
    lista.imprimir();
}

bool buscarestudiante(ListaDoble<estudiantes> &lista, const string &nombre) {
    for (int i = 0; i < lista.getTamanio(); i++) {
        estudiantes est = lista.getDato(i);
        if (nombre == est.nombre) {
            cout << "Se encontro al estudiante" << endl;
            return true;
        }
    }
    cout << "no se encontro al estudiante" << endl;
    return false;
}

void eliminarestudiante(ListaDoble<estudiantes> &lista,const string& nombre) {
    for (int i = 0; i < lista.getTamanio(); i++) {
        estudiantes est = lista.getDato(i);
        if (nombre == est.nombre) {
            lista.remover(i);
            cout << " se elimino al estudiante..." << endl;
            return;
        }
    }
    cout << "no se econtro al estudiante" << endl;
}

int main() {
    ListaDoble<estudiantes> lista;

    //dejar cinco estudiantes en lista
    lista.insertarUltimo(estudiantes("pau", 20));
    lista.insertarUltimo(estudiantes("jaz", 19));
    lista.insertarUltimo(estudiantes("luz", 21));
    lista.insertarUltimo(estudiantes("Ro", 19));
    lista.insertarUltimo(estudiantes("Marian", 18));

    //menu
    int op;
    string nombre;

    while (op < 6) {
        cout << "que desea realizar: \t";
        cout << "\n 1. agregar estudiante \t";
        cout << "\n 2. eliminar estudiante \t";
        cout << "\n 3. buscar estudiante \t";
        cout << "\n 4. mostrar lista estudiantes \t";
        cout << "\n 5. contar contactos en la lista de estudiantes \t";
        cout << "\n 6. salir del programa \t";
        cin >> op;

        switch (op) {
            case 1:
                agregarestudiante(lista);
                break;
            case 2:
                cout << "ingrese nombre que desea eliminar: " << endl;
                cin.ignore();
                getline(cin, nombre);
                eliminarestudiante(lista, nombre);
                break;
            case 3:
                cout << "ingrese nombre que desea buscar: " << endl;
                cin.ignore();
                getline(cin, nombre);
                buscarestudiante(lista, nombre);
                break;
            case 4:
                cout << "la lista de contactos es: " << endl;
                mostrarestudiantes(lista);
                break;
            case 5:
                cout << "Numero de contactos en la lista: " << lista.getTamanio() << endl;
                break;
            case 6:
                cout << "saliendo del programa..." << endl;
                exit(-1);
            default: cout << " numero invalido" << endl;
                break;
        }
    }
    return 0;
}
