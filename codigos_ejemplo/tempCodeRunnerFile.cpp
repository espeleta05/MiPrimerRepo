#include <iostream>

using namespace std;

int main(){
    int numero;
    cout<<"Escribe un numero: ";
    cin>>numero;
    if(numero%2 == 0 && numero>0){
        cout<<"Tu numero "<<numero<<" es un par"<<endl;
}
    else if(numero%2 ==0 && numero<0){
        cout<<"Tu numero es negativo"<<endl;
    }
    else{
        cout<<"Tu numero es impar";
}
 
    return 0;
}