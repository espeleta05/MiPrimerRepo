#ifndef AUTOR_H
#define AUTOR_H

#include <iostream>
#include <string>
using namespace std;

class Autor {
private:
    int id;
    string nombre;
    string nacionalidad;
    int numLibrosPublicados;

public:
    Autor() : id(0), nombre(""), nacionalidad(""), numLibrosPublicados(0) {}
    Autor(int i, string n, string nac, int num) : id(i), nombre(n), nacionalidad(nac), numLibrosPublicados(num) {}

    void setId(int i) { id = i; }
    int getId() { return id; }
    void setNombre(string n) { nombre = n; }
    string getNombre() { return nombre; }
    void setNacionalidad(string nac) { nacionalidad = nac; }
    string getNacionalidad() { return nacionalidad; }
    void setNumLibrosPublicados(int num) { numLibrosPublicados = num; }
    int getNumLibrosPublicados() { return numLibrosPublicados; }

    void cargarDesdeString(string linea) {
        size_t pos = linea.find(',');
        id = stoi(linea.substr(0, pos));
        linea.erase(0, pos + 1); 

        pos = linea.find(',');
        nombre = linea.substr(0, pos);
        if (!nombre.empty() && nombre[0] == ' ') nombre.erase(0, 1);
        linea.erase(0, pos + 1);

        pos = linea.find(',');
        nacionalidad = linea.substr(0, pos);
        if (!nacionalidad.empty() && nacionalidad[0] == ' ') nacionalidad.erase(0, 1);
        linea.erase(0, pos + 1);

        numLibrosPublicados = stoi(linea);
    }
};

#endif