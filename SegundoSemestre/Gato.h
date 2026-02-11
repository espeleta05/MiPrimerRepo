#include <iostream>
#include "Animal.h"
class Gato : public Animal {
public:
Gato(string sNom, int iANac);
void muestra();
void habla();
};
Gato::Gato(string sNom, int iANac) : Animal(sNom, iANac) {}
void Gato::muestra() {
cout << "Soy el gato " << sNombre << " y tengo " << calculaEdad() << " años."
<< endl;
}
void Gato::habla() {
cout << "MIAU" << endl;
}