#ifndef LEOPARDO_H
#define LEOPARDO_H

#include "Animal.h"
#include <iostream>

class Leopardo : public Animal {
private:
    static int contadorJR;

public:
    Leopardo(std::string nombre, char genero, int generacion);
    void accionar() override;
    SerVivo* reproducirse(SerVivo* otro) override;

    void explorar();
    void cazar();
    void alimentarse() override;
    void aparearse() override;
    void asechar();
};

#endif