#ifndef MateriaDeLectura_H
#define MateriaDeLectura_H
#include <iostream>
#include <string>

class MateriaDeLectura
{
protected:
    string titulo;
    string autor;

public:
    MateriaDeLectura();
    MateriaDeLectura(string t, string a);
    void setTitulo(string t) { titulo = t; };
    string getTitulo() { return titulo; };
    void setAutor(string a) { autor = a; };
    string getAutor() { return autor; };
    virtual void muestra() = 0;
};
MateriaDeLectura::MateriaDeLectura(string t, string a)
{
    titulo = t;
    autor = a;
}
MateriaDeLectura::MateriaDeLectura()
{
    titulo = " ";
    autor = " ";
}

#endif
