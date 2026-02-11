#include <iostream>
using namespace std;

int valor = 1; // Variable con alcance SCOPE Global

void saluda(string nombreP)
{
    cout << "Hola " << nombreP << endl;
}

bool menorEdad(int edadP)
{
    int valor = 8; // Variable local
    if (edadP > 17)
    {
        return false;
    }
    else
    {
        return true;
    }
}

int main()
{
    string nombre;
    int edad;
    char continuar;
    int valor = 20; // Variable local
    do
    {
        cout << "Dame tu nombre ";
        cin >> nombre;
        saluda(nombre);
        cout << "Dame tu edad ";
        cin >> edad;
        if (menorEdad(edad))
        {
            cout << "Eres menor de edad, no puedes pasar \n";
        }
        else
        {
            cout << "Bienvenido a la cerveceria \n";
        }
        cout << "Deseas continuar s/n ";
        cin >> continuar;
    } while (continuar == 's');
    return 0;
}