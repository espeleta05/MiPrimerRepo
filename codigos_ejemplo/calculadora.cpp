#include <iostream>

using namespace std;

double suma(double n1, double n2);
double resta(double n1, double n2);
double multi(double n1, double n2);
double div(double n1, double n2);



int main(){
    char operador;
    double numero1, numero2;

    cout<<"Bienvenido a la calculadora"<<endl;
    cout<<"Ingresa el primer numero: ";
    cin>>numero1;
    cout<<"Ingresa una de las siguientes operaciones (+,-,*,/)";
    cin>>operador;
    cout<<"Ingrese el segundo numero: ";
    cin>>numero2;
    switch(operador){
        case '+':
        cout<<"El resultado de la suma es: "<<suma(numero1,numero2);
        break;
        case '-':
        cout<<"El resultado de la resta es: "<<resta(numero1,numero2);
        break;
        case '*':
        cout<<"El resultado de la multplicaccion es:"<<multi(numero1,numero2);
        break;
        case '/':
        cout<<"El resultado de la division es:"<<div(numero1,numero2);
        break;
        default:
        cout<<"Ingrese un operador valido";
    }
    
    return 0;    
}




double suma(double n1, double n2){
    return n1+n2;
}
double resta(double n1, double n2){
    return n1-n2;
}
double multi(double n1, double n2){
    return n1*n2;
}
double div(double n1, double n2){
    if(n2!=0){
        return n1/n2;
    }
    else{}
}