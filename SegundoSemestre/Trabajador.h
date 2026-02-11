#include <iostream>
using namespace std;

class Trabajador {
private:
    int id;
    double sueldoFijo;
    double sueldoPorHora;
    int horasTrabajadas;

public:
    // Constructor por defecto
    Trabajador();
    
    // Métodos de acceso y modificación
    int getId() { return id; }
    double getSueldoFijo() { return sueldoFijo; }
    double getSueldoPorHora() { return sueldoPorHora; }
    int getHorasTrabajadas() { return horasTrabajadas; }
    
    void setId(int idP) { id = idP; }
    void setSueldoFijo(double sueldoFijoP) { sueldoFijo = sueldoFijoP; }
    void setSueldoPorHora(double sueldoPorHoraP) { sueldoPorHora = sueldoPorHoraP; }
    void setHorasTrabajadas(int horas) { horasTrabajadas = horas; }
    
    // Método para registrar horas trabajadas (acumula las horas)
    void registrarHoras(int horas) {
        if (horas > 0) {
            horasTrabajadas += horas;
        } else {
            cout << "Error: Las horas trabajadas deben ser un valor positivo." << endl;
        }
    }
    
    // Método para calcular el pago total
    double calcularPago() {
        return sueldoFijo + (horasTrabajadas * sueldoPorHora);
    }
};

// Implementación del constructor por defecto
Trabajador::Trabajador() {
    id = 0;
    sueldoFijo = 0.0;
    sueldoPorHora = 0.0;
    horasTrabajadas = 0;
}