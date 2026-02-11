#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

string eliminarEspaciosSobrantes(const string &frase)
{
    stringstream ss(frase);
    string palabra;
    string resultado;

    while (ss >> palabra)
    {
        if (!resultado.empty())
        {
            resultado += " ";
        }
        resultado += palabra;
    }

    return resultado;
}

int main()
{
    ifstream archivoEntrada("entrada.txt");

    if (!archivoEntrada)
    {
        cerr << "Error: No se pudo abrir el archivo de entrada." << endl;
        return 1;
    }

    string frase;
    while (getline(archivoEntrada, frase))
    {
        string fraseLimpia = eliminarEspaciosSobrantes(frase);
        cout << fraseLimpia << endl;
    }

    archivoEntrada.close();
    return 0;
}