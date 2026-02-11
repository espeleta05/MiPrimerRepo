#include <iostream>
#include <fstream>
#include <cctype>

using namespace std;

bool esNumeroFlotantePositivo(const string &str)
{
    bool puntoEncontrado = false;

    if (str.empty())
        return false;

    for (size_t i = 0; i < str.length(); i++)
    {
        if (str[i] == '.')
        {
            if (puntoEncontrado)
                return false;
            puntoEncontrado = true;
        }
        else if (!isdigit(str[i]))
        {
            return false;
        }
    }

    return true;
}

int main()
{
    ifstream archivoEntrada("entrada.txt");
    ofstream archivoSalida("salida.txt");

    if (!archivoEntrada)
    {
        cerr << "Error: No se pudo abrir el archivo de entrada." << endl;
        return 1;
    }

    if (!archivoSalida)
    {
        cerr << "Error: No se pudo abrir el archivo de salida." << endl;
        return 1;
    }

    string numero;
    archivoEntrada >> numero;

    if (esNumeroFlotantePositivo(numero))
    {
        archivoSalida << "Es un número flotante positivo válido." << endl;
    }
    else
    {
        archivoSalida << "No es un número flotante positivo válido." << endl;
    }

    archivoEntrada.close();
    archivoSalida.close();

    return 0;
}