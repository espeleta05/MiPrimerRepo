#include <iostream>
using namespace std;
#include "FraccionS.h"
int main()
{
FraccionS f1(1,3), f2(3,4), f3(1,5), f4;
// la suma de las fracciones 1/3 y 3/4
cout << endl;
cout << "La suma de las fracciones 1 y 2 " << endl;
f4 = f1 + f2;
f4.muestra();
// el valor en decimal de la fracción 1/3
cout << endl;
cout << "El valor decimal de la fraccion 1 "<< endl;
cout << !f1;
// Multiplicación de f1 * f2
cout << endl;
cout << "Multiplicacion de f1 y f2: ";
(f1 * f2).muestra();
// Comparación f2 > f3
cout << endl;
if (f2 > f3) {
cout << "Comparacion: f2 es mayor que f3 (";
f2.muestra();
cout << " > ";
f3.muestra();
cout << ")" << endl;
} else if (f3 > f2) {
cout << "Comparacion: f3 es mayor que f2 (";
f3.muestra();
cout << " > ";
f2.muestra();
cout << ")" << endl;
} else {
cout << "Comparacion: f2 y f3 son iguales (";
f2.muestra();
cout << " = ";
f3.muestra();
cout << ")" << endl;
}
// Incremento ++f4
cout << endl;
cout << "Incremento de f4 (++f4): ";
f4 = ++f4;
f4.muestra();
// Negativo unario --f1
cout << endl;
cout << "Negativo unario de f1 (--f1): ";
f1 = --f1;
f1.muestra();
// Resta f3 - f4
cout << endl;
cout << "Resta de f3 - f4: ";
(f3 - f4).muestra();
return 0;
}