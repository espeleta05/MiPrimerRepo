#include <iostream>

using namespace std;

int main() {
    float metros;
    cout << "Ingrese la cantidad de metros:" ;
    cin >> metros;

    float centimetros = metros*100;
    cout << "La cantidad en centimetros es: " << centimetros << endl;

    return 0;
}
