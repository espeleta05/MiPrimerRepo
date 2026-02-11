#ifndef PLANTA_H
#define PLANTA_H

#include "SerVivo.h"

class Planta : public SerVivo {
public:
    Planta(std::string nombre, std::string especie, int generacion);
    virtual void crecer() = 0;
    virtual void soltarSemilla() = 0;
    virtual void germinar() = 0;
    virtual void fotosintesis() = 0;
};

#endif