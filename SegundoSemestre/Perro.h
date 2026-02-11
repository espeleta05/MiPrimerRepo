#include <iostream>
#include "Animal.h"
class Perro : public Animal {
public:
Perro(string sNom, int iANac);
void muestra();
void habla();
};
Perro::Perro(string sNom, int iANac) : Animal(sNom, iANac) {}
void Perro::muestra() {
cout << "Soy el perro " << sNombre << " y tengo " << calculaEdad() << " años."
<< endl;
}
void Perro::habla() {
cout << "GUAU" << endl;
}