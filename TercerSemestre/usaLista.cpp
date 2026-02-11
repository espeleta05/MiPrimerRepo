//Eugenio Espeleta Alanis, Diego Rodriguez, Adrian Vazquez
#include <iostream>
using namespace std;
#include "LinkedList.h"

int main() {
    LinkedList<int> miLista;
    if (miLista.isEmpty()) cout << "Lista vacia ";
    miLista.addFirst(10);
    miLista.print();
    miLista.addLast(20);
    miLista.addFirst(5);
    miLista.addLast(25);
    miLista.print();
    cout << miLista.getSize() << " ";
    cout << endl;
    cout << miLista.getData(0) << " ";
    cout << endl;
    cout << miLista.getData(3) << " ";
    cout << endl;
    cout << miLista.findData(25) << " ";
    cout << endl;
    cout << miLista.findData(5) << " ";
    cout << endl;
    cout << miLista.findData(35) << " ";
    cout << endl;
    miLista.print();
    cout << endl;

    return 0;
}
