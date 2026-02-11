#include <iostream>

using namespace std;

int main() {
    float precioCoche; 
    const float porcentajeComision = 0.04;

    cout << "Ingrese el precio del coche vendido: ";
    cin >> precioCoche;
    
    float comision=precioCoche*porcentajeComision;
    float comision_final=comision+precioCoche;
    cout<<"La comision del vendedor es: $"<<comision<<endl;
return 0;
}
