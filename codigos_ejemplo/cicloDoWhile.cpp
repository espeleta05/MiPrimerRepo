#include <iostream>

using namespace std;

int main(){
    int contra = 1234;
    int contador = 0;
    int contraUsuario;
    const int intentosMaximos = 5;
    
    do{
        cout<<"Ingresa tu contrasena: ";
        cin>>contraUsuario;
        contador++;
    if(contraUsuario == contra){
        cout<<"Acceso concedido.";
        break;
    }
    else{
        cout<<"Acceso denegado. Intenta de nuevo, Intento "<<contador<<" de "<<intentosMaximos<<endl;
    }
    while (contador<intentosMaximos);
    }
    if(contador>=intentosMaximos){
      cout<<"Has sido bloqueado del sistema"<<endl;   
       }
    
    return 0;    
    
}