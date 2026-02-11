#ifndef CHANGO_H
#define CHANGO_H

#include "Animal.h"
#include <iostream>

class Chango : public Animal {
private:
    static int contadorJR;

public:
    Chango(std::string nombre, char genero, int generacion);
    void accionar() override;
    SerVivo* reproducirse(SerVivo* otro) override;

    void explorar();
    void buscarAlimento();
    void columpiarse();
    void huir();
    void alimentarse() override;
    void aparearse() override;
};

#endif