#include <iostream>
#include <string>
#include "LinkedList1.h"

using namespace std;

int main() {
    int totalSoldados;
    cout << "Cantidad de soldados: ";
    cin >> totalSoldados;

    if (totalSoldados <= 0) {
        cout << "Debe haber al menos un soldado." << endl;
        return 0;
    }

    LinkedList<string> circulo;

    for (int i = 0; i < totalSoldados; ++i) {
        string nombre;
        cout << "Nombre del soldado " << (i + 1) << ": ";
        cin>>nombre;
        circulo.insertLast(nombre);
    }

    int salto;
    cout << "Numero n (cuenta cada cuantos): ";
    cin >> salto;

    if (salto <= 0) {
        cout << "El numero n debe ser mayor que cero." << endl;
        return 0;
    }

    int inicio;
    cout << "Posicion inicial (1-" << totalSoldados << "): ";
    cin >> inicio;

    if (totalSoldados == 1) {
        cout << "El soldado que buscara ayuda es: " << circulo.getData(0) << endl;
        return 0;
    }

    int indiceActual = (inicio - 1) % totalSoldados;
    if (indiceActual < 0) {
        indiceActual += totalSoldados;
    }

    cout << "\nOrden de eliminacion:" << endl;
    while (circulo.getSize() > 1) {
        indiceActual = (indiceActual + salto - 1) % circulo.getSize();
        string eliminado = circulo.getData(indiceActual);
        cout << "- " << eliminado << endl;
        circulo.deleteAt(indiceActual);
        if (circulo.getSize() == 0) {
            break;
        }
        indiceActual %= circulo.getSize();
    }

    if (!circulo.isEmpty()) {
        cout << "El soldado que buscara ayuda es: " << circulo.getData(0) << endl;
    }

    return 0;
}
