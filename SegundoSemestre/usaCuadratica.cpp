#include <iostream>
#include <cmath>
using namespace std;
#include "Cuadratica.h"
int main()
{
int iA, iB, iC;
Cuadratica ec1(5,3,2), ecRes;
Cuadratica ec3 = ec1; // ec1 y ec3 tienen los mismos valores.
cout << "Teclea los coeficientes para la segunda ecuacion" << endl;
cin >> iA >> iB >> iC;
Cuadratica ec2(iA, iB, iC);
/***********/
cout << endl;
cout << "Suma de Ecuaciones 1 y 2" << endl;
cout << "Ecuacion 1 :" ;
ec1.muestra();
cout << "Ecuacion 2 :";
ec2.muestra();
// Usa la sobrecarga para hacer la suma
ecRes = ec1+ec2;
cout << "Resultado :";
ecRes.muestra();
cout << "Ecuacion 1 :" ;
ec1.muestra();
cout << "Ecuacion 2 :";
ec2.muestra();
cout << endl;
/***********/
cout << endl;
cout << "Resta de Ecuaciones 1 y 2" << endl;
cout << "Ecuacion 1 :" ;
ec1.muestra();
cout << "Ecuacion 2 :" ;
ec2.muestra();
// Usa la sobrecarga para hacer la resta
ecRes = ec1-ec2;
cout << "Resultado :";
ecRes.muestra();
cout << "Ecuacion 1 :" ;
ec1.muestra();
cout << "Ecuacion 2 :";
ec2.muestra();
cout << endl;
/***********/
cout << endl;
cout << "Multiplica Ecuacion 1 por valor entero 2" << endl;
cout << "Ecuacion 1 :" ;
ec1.muestra();
// Usa la sobrecarga para hacer la multiplicación
ecRes = ec1*2;
cout << "Resultado :";
ecRes.muestra();
cout << "Ecuacion 1 :" ;
ec1.muestra();
cout << endl;
/***********/
cout << endl;
cout << "Compara con ecuacion 1 y ecuacion 2, deben ser diferentes" << endl;
cout << "Ecuacion 1 :" ;
ec1.muestra();
cout << "Ecuacion 2 :" ;
ec2.muestra();
if ( ec1==ec2){
cout << "Son iguales" << endl;
}
else {
cout << "Son diferentes " << endl;
}
/***********/
cout << endl;
cout << "=== Compara con == ecuacion 1 y ecuacion 3, deben ser iguales"<< endl;
cout << "Ecuacion 1 :" ;
ec1.muestra();
cout << "Ecuacion 3 :" ;
ec3.muestra();
if (ec1 ==ec3){
cout<<"Son iguales" << endl;
}else {
cout << "Son diferentes " << endl;
}
/***********/
cout << endl;
cout << "=== Aplica += para sumar Ecuaciones 1 y 2" << endl;
cout << "Ecuacion 1 :" ;
ec1.muestra();
cout << "Ecuacion 2 :";
ec2.muestra();
// Usa la sobrecarga para hacer el +=
ec1+=ec2;
cout << "Ecuacion 1 :" ;
ec1.muestra();
cout << "Ecuacion 2 :";
ec2.muestra();
cout << endl;
/***********/
cout << endl;
cout << "=== Aplica ++ a Ecuacion 1 " << endl;
cout << "Ecuacion 1 :" ;
ec1.muestra();
// Usa la sobrecarga para hacer el incremento
++ec1;
cout << "Ecuacion 1 :" ;
ec1.muestra();
return 0;
}