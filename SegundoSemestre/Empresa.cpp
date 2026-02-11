#include <iostream>
#include <fstream>
#include "Trabajador.h"

using namespace std;

const int MAX_EMPLEADOS = 20;

// Función para buscar un empleado por ID
int buscarEmpleado(Trabajador empleados[], int cantidad, int id) {
    for (int i = 0; i < cantidad; i++) {
        if (empleados[i].getId() == id) {
            return i;
        }
    }
    return -1;
}

int main() {
    Trabajador empleados[MAX_EMPLEADOS];
    int cantidadEmpleados = 0;
    ifstream archivo("datosEntrada.txt");
    
    if (archivo) {
        int id, horas;
        double sueldoFijo, sueldoPorHora;
        while (archivo >> id >> sueldoFijo >> sueldoPorHora >> horas) {
            if (cantidadEmpleados < MAX_EMPLEADOS) {
                empleados[cantidadEmpleados].setId(id);
                empleados[cantidadEmpleados].setSueldoFijo(sueldoFijo);
                empleados[cantidadEmpleados].setSueldoPorHora(sueldoPorHora);
                empleados[cantidadEmpleados].setHorasTrabajadas(horas);
                cantidadEmpleados++;
            }
        }
        archivo.close();
    } else {
        cout << "Error al abrir el archivo de datos." << endl;
        return 1;
    }
    
    char opcion;
    do {
        cout << "\nMenu:\n";
        cout << "A. Modificar sueldo fijo\n";
        cout << "B. Modificar sueldo por horas\n";
        cout << "C. Registrar horas trabajadas\n";
        cout << "D. Calcular pago del empleado\n";
        cout << "E. Ver lista empleados\n";
        cout << "F. Terminar\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        
        int id, indice;
        double nuevoSueldo;
        int horas;
        
        switch (opcion) {
            case 'A':
                cout << "Ingrese ID del empleado: ";
                cin >> id;
                while ((indice = buscarEmpleado(empleados, cantidadEmpleados, id)) == -1) {
                    cout << "ID no encontrado. Intente nuevamente: ";
                    cin >> id;
                }
                cout << "Ingrese nuevo sueldo fijo: ";
                cin >> nuevoSueldo;
                if (nuevoSueldo > 0) {
                    empleados[indice].setSueldoFijo(nuevoSueldo);
                } else {
                    cout << "El sueldo debe ser positivo." << endl;
                }
                break;
            
            case 'B':
                cout << "Ingrese ID del empleado: ";
                cin >> id;
                while ((indice = buscarEmpleado(empleados, cantidadEmpleados, id)) == -1) {
                    cout << "ID no encontrado. Intente nuevamente: ";
                    cin >> id;
                }
                cout << "Ingrese nuevo sueldo por hora: ";
                cin >> nuevoSueldo;
                if (nuevoSueldo > 0) {
                    empleados[indice].setSueldoPorHora(nuevoSueldo);
                } else {
                    cout << "El sueldo debe ser positivo." << endl;
                }
                break;
            
            case 'C':
                cout << "Ingrese ID del empleado: ";
                cin >> id;
                while ((indice = buscarEmpleado(empleados, cantidadEmpleados, id)) == -1) {
                    cout << "ID no encontrado. Intente nuevamente: ";
                    cin >> id;
                }
                cout << "Ingrese horas a registrar: ";
                cin >> horas;
                if (horas > 0) {
                    empleados[indice].registrarHoras(horas);
                } else {
                    cout << "Las horas deben ser un valor positivo." << endl;
                }
                break;
            
            case 'D':
                cout << "Ingrese ID del empleado: ";
                cin >> id;
                while ((indice = buscarEmpleado(empleados, cantidadEmpleados, id)) == -1) {
                    cout << "ID no encontrado. Intente nuevamente: ";
                    cin >> id;
                }
                cout << "El pago del empleado es: $" << empleados[indice].calcularPago() << endl;
                break;
            
            case 'E':
                cout << "\nLista de empleados:\n";
                for (int i = 0; i < cantidadEmpleados; i++) {
                    cout << "ID: " << empleados[i].getId() << " - Sueldo fijo: $" << empleados[i].getSueldoFijo()
                         << " - Sueldo por hora: $" << empleados[i].getSueldoPorHora()
                         << " - Horas trabajadas: " << empleados[i].getHorasTrabajadas()
                         << " - Pago total: $" << empleados[i].calcularPago() << endl;
                }
                break;
        }
    } while (opcion != 'F');
    
    return 0;
}