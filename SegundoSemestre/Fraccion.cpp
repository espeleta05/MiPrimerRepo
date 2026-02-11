#include <iostream>
using namespace std;
#include "Fracciones.h"

int main() {
   
    Fraccion fraccion1; 
    Fraccion fraccion2(3, 4); 

    
    cout << "El valor de la fraccion " << fraccion1.getNumerador() << "/" << fraccion1.getDenominador() << " es " << fraccion1.CalcValorReal() << endl;
    cout << "El valor de la fraccion " << fraccion2.getNumerador() << "/" << fraccion2.getDenominador() << " es " << fraccion2.CalcValorReal() << endl;

    return 0;
}