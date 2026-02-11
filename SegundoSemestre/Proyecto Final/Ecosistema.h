#ifndef ECOSISTEMA_H
#define ECOSISTEMA_H

#include <vector>
#include <iostream>
#include <cstdlib> 
#include "SerVivo.h"
#include "Animal.h"

template <typename T>
class Ecosistema {
private:
    std::vector<SerVivo*> seres;
    int turno = 0;

public:
    void agregarSer(SerVivo* ser) {
        seres.push_back(ser);
    }

    void simularTurno() {
        for (auto ser : seres) {
            if (ser->estaVivo()) {
                ser->accionar();
            }
        }

        std::vector<SerVivo*> nuevos;
        for (size_t i = 0; i < seres.size(); ++i) {
            for (size_t j = i + 1; j < seres.size(); ++j) {
                if (!seres[i]->estaVivo() || !seres[j]->estaVivo()) continue;

                Animal* a1 = dynamic_cast<Animal*>(seres[i]);
                Animal* a2 = dynamic_cast<Animal*>(seres[j]);
                if (a1 && a2 &&
                    a1->getEspecie() == a2->getEspecie() &&
                    a1->getGenero() != a2->getGenero()) {

                    if (rand() % 4 == 0) {
                        SerVivo* hijo = *a1 + *a2;
                        if (hijo) {
                            std::cout << hijo->getNombre() << " ha nacido.\n";
                            nuevos.push_back(hijo);
                        }
                    }
                }
            }
        }

        for (auto hijo : nuevos) {
            seres.push_back(hijo);
        }

        turno++;
    }

    void mostrarEstado() const {
        int vivos = 0;
        for (auto ser : seres) {
            if (ser->estaVivo()) vivos++;
        }
        std::cout << "Turno: " << turno << "   Animales vivos: " << vivos << "\n";
        for (auto ser : seres) {
            if (ser->estaVivo()) {
                Animal* animal = dynamic_cast<Animal*>(ser);
                if (animal) {
                    std::cout << animal->getNombre()
                              << " ---- Hambre: " << animal->getHambre() << "/100"
                              << " ---- Energia: " << animal->getEnergia() << "/"
                              << animal->getEnergiaMaxima() << "\n";
                }
            }
        }
    }

    ~Ecosistema() {
        for (auto ser : seres)
            delete ser;
    }
};

#endif
