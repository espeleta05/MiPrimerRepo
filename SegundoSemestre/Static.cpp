#include <iostream>
using namespace std;
#include "Persona.h"
int main() { 
    cout<<"Antes de crear objetos Persona "<<Persona::getContPer()<<endl;
    Persona p1("Juan", "918921792");
    cout<<"Al crear 1 objeto Persona "<<p1.getNombre()<<" "<<p1.getContPer()<<endl;
    Persona p2("Elsa", "911271872");
    cout<<"Al crear el segundo objeto Persona "<<p2.getNombre()<<" "<<p2.getContPer()<<endl;
    Persona arr[5];
    cout<<"Despues de crear el arreglo de 5 objetos Persona "<<Persona::getContPer()<<endl;
    return 0;
}