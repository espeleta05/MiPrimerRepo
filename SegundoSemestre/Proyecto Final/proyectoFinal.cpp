#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "SerVivo.h"
#include "Animal.h"
#include "Leopardo.h"
#include "Chango.h"
#include "Tucan.h"
#include "Arbol.h"
#include "Ecosistema.h"


Animal::Animal(std::string nombre, std::string especie, char genero, int generacion)
    : SerVivo(nombre, especie, generacion), genero(genero), hambre(0), energia(0), energiaMaxima(100) {}

void Animal::setHambre(int h) { hambre = h; }
void Animal::setEnergia(int e) { energia = e; }
int Animal::getHambre() const { return hambre; }
int Animal::getEnergia() const { return energia; }
int Animal::getEnergiaMaxima() const { return energiaMaxima; }
char Animal::getGenero() const { return genero; }

void Animal::dormir() {
    energia += 20;
    if (energia > energiaMaxima) energia = energiaMaxima;
    hambre += 10;
}

SerVivo* Animal::operator+(const Animal& otro) {
    if (this->especie == otro.especie && this->genero != otro.genero) {
        std::string nuevoNombre = this->nombre + "_JR";
        char nuevoGenero = (rand() % 2 == 0) ? 'M' : 'H';
        if (especie == "Leopardo")
            return new Leopardo(nuevoNombre, nuevoGenero, generacion + 1);
        else if (especie == "Chango")
            return new Chango(nuevoNombre, nuevoGenero, generacion + 1);
        else if (especie == "Tucan")
            return new Tucan(nuevoNombre, nuevoGenero, generacion + 1);
    }
    return nullptr;
}

SerVivo::SerVivo(std::string nombre, std::string especie, int generacion)
    : nombre(nombre), especie(especie), edad(0), edadMaxima(20), generacion(generacion), vivo(true) {}

void SerVivo::envejecer() { edad++; if (edad > edadMaxima) morir(); }
bool SerVivo::estaVivo() const { return vivo; }
void SerVivo::morir() { vivo = false; }
std::string SerVivo::getNombre() const { return nombre; }
std::string SerVivo::getEspecie() const { return especie; }
int SerVivo::getGeneracion() const { return generacion; }
bool SerVivo::operator==(const SerVivo& otro) const {
    return especie == otro.especie && generacion == otro.generacion;
}

int Leopardo::contadorJR = 1;
Leopardo::Leopardo(std::string nombre, char genero, int generacion)
    : Animal(nombre, "Leopardo", genero, generacion) {
    energia = 100;
    energiaMaxima = 120;
    edadMaxima = 15;
}

void Leopardo::accionar() {
    if (!estaVivo()) return;
    envejecer();
    hambre += 15;
    energia -= 10;
    if (hambre >= 100 || energia <= 0) { morir(); return; }

    int accion = rand() % 5;
    switch (accion) {
        case 0: std::cout << nombre << " explora.\n"; energia -= 5; break;
        case 1: std::cout << nombre << " caza.\n"; hambre -= 30; energia += 10; break;
        case 2: alimentarse(); std::cout << nombre << " se alimenta.\n"; break;
        case 3: aparearse(); break;
        case 4: dormir(); std::cout << nombre << " duerme.\n"; break;
    }
}

void Leopardo::alimentarse() { hambre -= 25; energia += 15; }
void Leopardo::aparearse() { std::cout << nombre << " se apareo.\n"; }

SerVivo* Leopardo::reproducirse(SerVivo* otro) {
    Leopardo* pareja = dynamic_cast<Leopardo*>(otro);
    if (pareja && genero != pareja->genero) {
        std::string nombreHijo = nombre + "_JR" + std::to_string(contadorJR++);
        return new Leopardo(nombreHijo, (rand() % 2 == 0) ? 'M' : 'H', generacion + 1);
    }
    return nullptr;
}

int Chango::contadorJR = 1;
Chango::Chango(std::string nombre, char genero, int generacion)
    : Animal(nombre, "Chango", genero, generacion) {
    energia = 80;
    energiaMaxima = 100;
    edadMaxima = 12;
}

void Chango::accionar() {
    if (!estaVivo()) return;
    envejecer();
    hambre += 10;
    energia -= 8;
    if (hambre >= 100 || energia <= 0) { morir(); return; }

    int accion = rand() % 6;
    switch (accion) {
        case 0: std::cout << nombre << " explora.\n"; energia -= 5; break;
        case 1: std::cout << nombre << " busca alimento.\n"; hambre -= 20; break;
        case 2: std::cout << nombre << " se columpia.\n"; energia -= 5; break;
        case 3: std::cout << nombre << " huye de un depredador.\n"; energia -= 10; break;
        case 4: alimentarse(); std::cout << nombre << " se alimenta.\n"; break;
        case 5: dormir(); std::cout << nombre << " duerme.\n"; break;
    }
}

void Chango::alimentarse() { hambre -= 20; energia += 10; }
void Chango::aparearse() { std::cout << nombre << " se apareo.\n"; }

SerVivo* Chango::reproducirse(SerVivo* otro) {
    Chango* pareja = dynamic_cast<Chango*>(otro);
    if (pareja && genero != pareja->genero) {
        std::string nombreHijo = nombre + "_JR" + std::to_string(contadorJR++);
        return new Chango(nombreHijo, (rand() % 2 == 0) ? 'M' : 'H', generacion + 1);
    }
    return nullptr;
}

int Tucan::contadorJR = 1;
Tucan::Tucan(std::string nombre, char genero, int generacion)
    : Animal(nombre, "Tucan", genero, generacion) {
    energia = 60;
    energiaMaxima = 80;
    edadMaxima = 10;
}

void Tucan::accionar() {
    if (!estaVivo()) return;
    envejecer();
    hambre += 8;
    energia -= 10;
    if (hambre >= 100 || energia <= 0) { morir(); return; }

    int accion = rand() % 6;
    switch (accion) {
        case 0: std::cout << nombre << " explora.\n"; energia -= 4; break;
        case 1: std::cout << nombre << " busca alimento.\n"; hambre -= 15; break;
        case 2: std::cout << nombre << " huye de un depredador.\n"; energia -= 8; break;
        case 3: std::cout << nombre << " pone huevos.\n"; energia -= 5; break;
        case 4: alimentarse(); std::cout << nombre << " se alimenta.\n"; break;
        case 5: dormir(); std::cout << nombre << " duerme.\n"; break;
    }
}

void Tucan::alimentarse() { hambre -= 15; energia += 10; }
void Tucan::aparearse() { std::cout << nombre << " se apareo.\n"; }

SerVivo* Tucan::reproducirse(SerVivo* otro) {
    Tucan* pareja = dynamic_cast<Tucan*>(otro);
    if (pareja && genero != pareja->genero) {
        std::string nombreHijo = nombre + "_JR" + std::to_string(contadorJR++);
        return new Tucan(nombreHijo, (rand() % 2 == 0) ? 'M' : 'H', generacion + 1);
    }
    return nullptr;
}



int main() {
    srand(time(NULL));
    Ecosistema<SerVivo> ecosistema;

    ecosistema.agregarSer(new Leopardo("LeopardoM", 'M', 0));
    ecosistema.agregarSer(new Leopardo("LeopardoH", 'H', 0));
    ecosistema.agregarSer(new Chango("ChangoM", 'M', 0));
    ecosistema.agregarSer(new Chango("ChangoH", 'H', 0));
    ecosistema.agregarSer(new Tucan("TucanM", 'M', 0));
    ecosistema.agregarSer(new Tucan("TucanH", 'H', 0));

    int turno = 0;
    while (true) {
        std::cout << "\n-------Estatus-------\nTurno: " << turno << "\n";
        ecosistema.mostrarEstado();
        std::cout << "\n------Acciones------\n";
        ecosistema.simularTurno();
        std::cout << "\nPresiona ENTER para continuar...";
        std::cin.ignore();
        turno++;
    }

    return 0;
}
