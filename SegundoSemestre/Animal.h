#ifndef Animal_H
#define Animal_H
#include <iostream>
#include <string>
using namespace std;
class Animal {
public:
Animal( string sNom, int iANac);
int calculaEdad();
virtual void habla() = 0; //Nota que son
funciones virtual pura.
virtual void muestra() = 0; // ENTONCES la clase
es abstracta.
protected:
string sNombre;
int iAnioNacim;
};
Animal::Animal(string sNom, int iANac) {
sNombre = sNom;
iAnioNacim = iANac;
}
int Animal::calculaEdad() {
return 2025 - iAnioNacim;
}
#endif