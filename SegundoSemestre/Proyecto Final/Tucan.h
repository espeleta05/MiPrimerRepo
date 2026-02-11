#ifndef TUCAN_H
#define TUCAN_H

#include "Animal.h"
#include <iostream>

class Tucan : public Animal {
private:
    static int contadorJR;

public:
    Tucan(std::string nombre, char genero, int generacion);
    void accionar() override;
    SerVivo* reproducirse(SerVivo* otro) override;

    void volar();
    void buscarAlimento();
    void ponerHuevos();
    void huir();
    void explorar();
    void alimentarse() override;
    void aparearse() override;
};

#endif
