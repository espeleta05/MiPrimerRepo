#include <iostream>

using namespace std;

int main(){
    char letra;
    cout<<"Ingrese una letra y te dire tu calificaccion ";
    cin>>letra;

    switch(letra){
        case 'a':
        cout<<"u calificaccion fue exelente";
        break;
        case 'b':
        cout<<"Tu calificaccion fue buena";
        break;
        case 'c':
        cout<<"Tu calificaccion fue regular";
        break;
        default:
        cout<<"ALM, te fue muy mal";
    }    
    

    return 0;
}