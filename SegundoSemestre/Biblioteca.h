#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include <iostream>
#include <fstream>
#include "Libro.h"
using namespace std;

class Biblioteca
{
private:
    Libro *libros;
    int capacidad;
    int cantidad;

    void redimensionar(int nuevaCapacidad)
    {
        Libro *temp = new Libro[nuevaCapacidad];
        for (int i = 0; i < cantidad; i++)
        {
            temp[i] = libros[i]; 
        }
        delete[] libros;
        libros = temp;
        capacidad = nuevaCapacidad;
    }

public:
    Biblioteca() : capacidad(10), cantidad(0)
    {
        libros = new Libro[capacidad];
    }

    ~Biblioteca()
    {
        delete[] libros;
    }

    Biblioteca(const Biblioteca &otra) : capacidad(otra.capacidad), cantidad(otra.cantidad)
    {
        libros = new Libro[capacidad];
        for (int i = 0; i < cantidad; i++)
        {
            libros[i] = otra.libros[i];
        }
    }

    Biblioteca &operator=(const Biblioteca &otra)
    {
        if (this != &otra)
        {
            delete[] libros;
            capacidad = otra.capacidad;
            cantidad = otra.cantidad;
            libros = new Libro[capacidad];
            for (int i = 0; i < cantidad; i++)
            {
                libros[i] = otra.libros[i];
            }
        }
        return *this;
    }

    int getCantidad() { return cantidad; }
    Libro *getLibros() { return libros; }

    Biblioteca &operator+=(Libro libro)
    {
        if (cantidad == capacidad)
        {
            redimensionar(capacidad * 2);
        }
        libros[cantidad++] = libro;
        return *this;
    }

    Biblioteca &operator-=(string titulo)
    {
        for (int i = 0; i < cantidad; i++)
        {
            if (libros[i].getTitulo() == titulo)
            {
                for (int j = i; j < cantidad - 1; j++)
                {
                    libros[j] = libros[j + 1];
                }
                cantidad--;
                break;
            }
        }
        return *this;
    }

    friend ostream &operator<<(ostream &os, Biblioteca &bib)
    {
        for (int i = 0; i < bib.cantidad; i++)
        {
            os << bib.libros[i].getTitulo() << ","
               << bib.libros[i].getAnioPublicacion() << ","
               << bib.libros[i].getPrecio() << ","
               << bib.libros[i].getAutor().getId() << "\n";
        }
        return os;
    }

    friend istream &operator>>(istream &is, Biblioteca &bib)
    {
        string linea;
        while (getline(is, linea))
        {
            Libro libro;
            Autor autor;
            libro.cargarDesdeString(linea, &autor, 1);
            bib += libro;
        }
        return is;
    }

    void cargarAutores(string archivo, Autor *&autores, int &numAutores)
    {
        ifstream file(archivo);
        string linea;
        numAutores = 0;

        while (getline(file, linea))
            numAutores++;
        file.clear();
        file.seekg(0);

        autores = new Autor[numAutores];
        int i = 0;
        while (getline(file, linea))
        {
            autores[i].cargarDesdeString(linea);
            i++;
        }
        file.close();
    }

    void cargarLibros(string archivo, Autor *autores, int numAutores)
    {
        ifstream file(archivo);
        string linea;

        while (getline(file, linea))
        {
            Libro libro;
            libro.cargarDesdeString(linea, autores, numAutores);
            *this += libro;
        }
        file.close();
    }

    void guardarLibros(string archivo)
    {
        ofstream file(archivo);
        file << *this;
        file.close();
    }
};

#endif