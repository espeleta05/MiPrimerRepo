#include <iostream>
using namespace std;
#include "Rectangulo.h"

int main(){
    Rectangulo rect1, rect2(3,6);
    cout<<"El area del rectangulo es:"<<rect1.calculaArea()<<endl;
    rect1.setAncho(5);
    rect1.setLargo(10);
    cout<<"El area del rectangulo es:"<<rect1.calculaArea()<<endl;
    cout<<"El area del rectangulo es: "<<rect2.calculaArea()<<endl;
    cout<<"El ancho del rectangulo 2 es "<<rect2.getAncho()<<" el largo es "<<rect2.getLargo()<<endl;
    return 0;
}