#include <iostream>
using namespace std;

#include "Lista.h"

int main(){
    Lista<int> miListaInt;
    Lista<double> miListaDob;

    miListaInt.agrega(3);
    miListaInt.agrega(4);
    miListaInt.agrega(5);

    miListaDob.agrega(1.2);
    miListaDob.agrega(3.3);
    miListaDob.agrega(4.1);

    for(int i=0; i<miListaInt.getSize(); i++){
        cout<<miListaInt.getElement(i)<<endl;
    }
    for(int i=0; i<miListaDob.getSize(); i++){
        cout<<miListaDob.getElement(i)<<endl;
    }
    return 0;

}