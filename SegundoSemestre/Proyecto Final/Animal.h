#ifndef ANIMAL_H
#define ANIMAL_H

#include "SerVivo.h"
#include <iostream>

class Animal : public SerVivo {
protected:
    char genero;
    int hambre;
    int energia;
    int energiaMaxima;

public:
    Animal(std::string nombre, std::string especie, char genero, int generacion);
    virtual void alimentarse() = 0;
    virtual void aparearse() = 0;
    void dormir();
    SerVivo* operator+(const Animal& otro);

    void setHambre(int h);
    void setEnergia(int e);
    int getHambre() const;
    int getEnergia() const;
    int getEnergiaMaxima() const;
    char getGenero() const;
};

#endif
