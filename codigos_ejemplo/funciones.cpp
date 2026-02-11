#include <iostream>

using namespace std;

int suma(int numero1, int numero2);

int main(){
    int n1,n2;
    int sumaMain;

    cout<<"Escribe el numero 1: ";
    cin>>n1;
    cout<<"Escribe el numero 2: ";
    cin>>n2;

    sumaMain = suma(n1,n2);
    cout<<"El resultado de la suma de "<<n1<<" + "<<n2<<" = "<<sumaMain;
}

int main(){
    
    return 0;    
}
