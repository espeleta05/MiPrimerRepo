#include <iostream>
using namespace std;
#include <fstream>

int main(){
    ofstream archSalida;
    ifstream archEntrada;
    int x;
    archSalida.open("resultados.txt");
    for (int i=0; i<10; i++){
        archSalida<<i<<endl;
    }
    archSalida.close();
    archEntrada.open("resultados.txt");
    while (archEntrada >> x ){
        cout<<"valor: "<<x<<endl;
    }
    archEntrada.close();
    return 0;
}