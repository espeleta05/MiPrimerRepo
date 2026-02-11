// SerVivo.h
#ifndef SERVIVO_H
#define SERVIVO_H

#include <string>

class SerVivo {
protected:
    std::string nombre;
    std::string especie;
    int edad;
    int edadMaxima;
    int generacion;
    bool vivo;

public:
    SerVivo(std::string nombre, std::string especie, int generacion);
    virtual ~SerVivo() = default;

    virtual void accionar() = 0;
    virtual SerVivo* reproducirse(SerVivo* otro) = 0;

    void envejecer();
    bool estaVivo() const;
    void morir();

    std::string getNombre() const;
    std::string getEspecie() const;
    int getGeneracion() const;

    bool operator==(const SerVivo& otro) const; 
};

#endif
