#include <iostream>
using namespace std;
#include "ListaEjercicio.h"

int main(){
    ListaEjercicio<int> miListaEnt;
    ListaEjercicio<double> miListaDob;
    ListaEjercicio<string> miListaStr;

    for (int i=0; i < 5; i++){
        miListaEnt.agrega(i);
        miListaDob.agrega(i * 0.1);
}
miListaStr.agrega("Hola");
    miListaStr.agrega("Lola");

    for (int i=0; i < 5; i++){
        cout << miListaEnt.getElemen(i) << endl;
        cout << miListaDob.getElemen(i) << endl;
    }

    {
cout << miListaStr.getElemen(1);
    }

    return 0;
}