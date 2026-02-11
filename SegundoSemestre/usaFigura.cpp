#include <iostream>
using namespace std;

#include "Cuadrado.h"
#include "Triangulo.h"

int main(){
    Figura *arrF[4];
    arrF[0] = new Triangulo();
    arrF[1] = new Cuadrado();
    arrF[2] = new Triangulo();
    arrF[3] = new Cuadrado();
    for (int i=0; i<4; i++){
        arrF[i]->dibuja();
    }
    return 0;
}