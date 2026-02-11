#include <iostream>

using namespace std;

int main(){
    float x, y;
    int x;
    cout<<"Enter a value for X";
    cin>>x;
    int y;
    cout<<"Enter a value foy Y";
    cin>>y;
    int residuo1, residuo2;
    residuo1 = 20;
    residuo2 = 40;
    float suma, resta, div, multi, residuo;

    suma = x+y;
    resta = x-y;
    multi = x*y;
    div = x/y;
    residuo = residuo1%residuo2;

    cout<<"El resultado de la suma es: "<<suma<<endl;
    cout<<"El resultado de la resta es: "<<resta<<endl;
    cout<<"El resultado de la multiplicaccion es: "<<multi<<endl;
    cout<<"El resultado de la division es: "<<div<<endl;
    cout<<"El resultado es: "<<residuo<<endl;

    return 0;
}