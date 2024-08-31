/*Utilizando la estructura lista, crear un programa que gestione una lista circular de contactos.
Cada contacto contiene un nombre (cadena de caracteres) y un número de teléfono (cadena
de caracteres).
Tareas
1. Agregar Contactos:
○ Usa los métodos de CircList para agregar varios contactos a la lista. Deberás
insertar al menos cinco contactos con nombres y números de teléfono distintos.
2. Mostrar Contactos:
○ Implementa una función que recorra la lista circular y muestre todos los
contactos en orden. Usa el metodo imprimir() de CircList.
3. Buscar un Contacto por Nombre:
○ Implementa una función que busque un contacto por su nombre. Usa el metodo
getDato(int pos) para acceder a los datos de los nodos y busca el
contacto en la lista.
4. Eliminar un Contacto por Nombre:
○ Implementa una función que elimine un contacto por su nombre. Deberás usar
los métodos getDato(int pos) y eliminarPorValor(T valor) (supón
que eliminarPorValor está implementado, aunque no esté explícito en el
código proporcionado).
5. Contar Contactos:
○ Usa el metodo getTamanio() para contar el número de contactos en la lista y
muestra el resultado.*/


#include <iostream>
#include <string>
#include "Lista/CircList.h"


using namespace std;

class contacto {
public:
    string nombre;
    string telefono;

    contacto() : nombre(""), telefono("") {
    }

    contacto(const string &nom, const string &telef): nombre(nom), telefono(telef) {
    }

    // Sobrecarga del operador <<
    friend ostream &operator<<(ostream &os, const contacto &c) {
        os << "Nombre: " << c.nombre << ", Telefono: " << c.telefono;
        return os;
    }

    //friend permite que el operador << acceda a los datos de la clase
    //ostream es el tipo de objeto de flujo de salida (cout) - la funcion toma y devuelve una referencia a este flujo
    //se crea un objeto de tipo contacto y luego se imprimen sus datos

    bool operator==(const contacto &other) const {
        return nombre == other.nombre;
    }

    //operador de sobrecarga de ==
    //referencia a un objeto de la clase y compara si el objeto actual es igual a otro objeto
};


void insertarcontactos(CircList<contacto> &lista) {
    string nombre;
    string telefono;

    cout << "Ingrese nombre: " << endl;
    cin.ignore();
    getline(cin, nombre);
    cout << "ingrese numero telefono: " << endl;
    getline(cin, telefono);

    contacto C(nombre, telefono);
    lista.insertarUltimo(C);
}

void mostrarcontactos(CircList<contacto> &lista) {
    if (lista.esVacia()) {
        cout << "la lista esta vacia, no hay nada que mostrar" << endl;
        return;
    }
    lista.imprimir();
}

void buscarpornombre(CircList<contacto> &lista, const string &nombre) {
    for (int i = 0; i < lista.getTamanio(); i++) {
        contacto C = lista.getDato(i);
        if (C.nombre == nombre) {
            cout << "se encontro al contacto: " << C << endl;
            return;
        }
        cout << "No se encontro al contacto" << endl;
    }
}

void eliminarcontacto(CircList<contacto> &lista, const string &nombre) {
    for (int i = 0; i < lista.getTamanio(); i++) {
        contacto C = lista.getDato(i);
        if (nombre == C.nombre) {
            lista.eliminarPorValor(C);
            cout << "Se elimino el contacto" << endl;
            return;
        }
        cout << "no se encontro contacto en la lista" << endl;
    }
}

int main() {
    CircList<contacto> lista;
    lista.insertarUltimo(contacto("lola", "2997007"));
    lista.insertarUltimo(contacto("juan", "29455321"));
    lista.insertarUltimo(contacto("pedro", "29172004"));
    lista.insertarUltimo(contacto("cami", "23345676"));

    string nombre;
    int op;

    while (op < 6) {
        cout << "que desea realizar: \t";
        cout << "\n 1. agregar contacto \t";
        cout << "\n 2. eliminar contacto \t";
        cout << "\n 3. buscar contacto \t";
        cout << "\n 4. mostrar lista contactos \t";
        cout << "\n 5. contar contactos en la lista \t";
        cout << "\n 6. salir del programa \t";
        cin >> op;

        switch (op) {
            case 1:
                insertarcontactos(lista);
                break;
            case 2:
                cout << "ingrese nombre que desea eliminar: " << endl;
                cin.ignore();
                getline(cin, nombre);
                eliminarcontacto(lista, nombre);
                break;
            case 3:
                cout << "ingrese nombre que desea buscar: " << endl;
                cin.ignore();
                getline(cin, nombre);
                buscarpornombre(lista, nombre);
                break;
            case 4:
                cout << "la lista de contactos es: " << endl;
                mostrarcontactos(lista);
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
