#ifndef ARBOL_H
#define ARBOL_H

#include "Planta.h"
#include <iostream>

class Arbol : public Planta {
private:
    static int contadorJR;

public:
    Arbol(std::string nombre, int generacion);
    void accionar() override;
    SerVivo* reproducirse(SerVivo* otro) override;

    void crecer() override;
    void soltarSemilla() override;
    void germinar() override;
    void fotosintesis() override;
};

#endif