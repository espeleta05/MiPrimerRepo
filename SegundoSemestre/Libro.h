#ifndef LIBRO_H
#define LIBRO_H

#include <iostream>
#include <string>
#include "Author.h" 
using namespace std;

class Libro {
private:
    string titulo;
    int anioPublicacion;
    double precio;
    Autor autor;

public:
    Libro() : titulo(""), anioPublicacion(0), precio(0.0), autor() {}
    Libro(string t, int anio, double p, Autor a) : titulo(t), anioPublicacion(anio), precio(p), autor(a) {}

    void setTitulo(string t) { titulo = t; }
    string getTitulo() { return titulo; }
    void setAnioPublicacion(int anio) { anioPublicacion = anio; }
    int getAnioPublicacion() { return anioPublicacion; }
    void setPrecio(double p) { precio = p; }
    double getPrecio() { return precio; }
    void setAutor(Autor a) { autor = a; }
    Autor getAutor() { return autor; }

    bool operator==(Libro otro) {
        return (titulo == otro.titulo) && (autor.getId() == otro.autor.getId());
    }

    void cargarDesdeString(string linea, Autor* autores, int numAutores) {
        size_t pos = linea.find(',');
        titulo = linea.substr(0, pos);
        linea.erase(0, pos + 1);

        pos = linea.find(',');
        anioPublicacion = stoi(linea.substr(0, pos));
        linea.erase(0, pos + 1);

        pos = linea.find(',');
        precio = stod(linea.substr(0, pos));
        linea.erase(0, pos + 1);

        int idAutor = stoi(linea);
        for (int i = 0; i < numAutores; i++) {
            if (autores[i].getId() == idAutor) {
                autor = autores[i];
                break;
            }
        }
    }
};

#endif