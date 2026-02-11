#include <iostream>
using namespace std;
#include "BST.h"

int main() {
    BST<int> miArbol;

    miArbol.insertData(20);
    miArbol.insertData(30);
    miArbol.insertData(10);
    miArbol.insertData(25);
    miArbol.insertData(27);
    miArbol.insertData(100);

    cout << "\nArbol antes de eliminar:";
    miArbol.print(4);

    cout << "\nEliminando nodo 20\n";
    miArbol.deleteData(20);

    cout << "\nRecorridos:";
    miArbol.print(1);
    miArbol.print(2);
    miArbol.print(3);
    miArbol.print(4);

    cout << "\nAltura del arbol: " << miArbol.height() << endl;

    cout << "\nBorrando todo el arbol\n";
    miArbol.clear();

    if (miArbol.isEmpty())
        cout << "El arbol esta vacio\n";

    return 0;
}
