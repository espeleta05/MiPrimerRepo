#include <iostream>

using namespace std;

int main(){
    int numero=100;
    while (numero<=500){
        if (numero%3==0 && numero%5==0){
            cout<<"El numero es: "<<numero<<endl;
        }
        numero++;
    }


    return 0;    
}