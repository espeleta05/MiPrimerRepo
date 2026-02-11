#include <iostream>

using namespace std;

int main() {
    double total_nomina[5] = {0};  // Array para almacenar el total de nómina de cada departamento
    int departamento;
    double salario;
    char continuar;

    do {
        cout << "Seleccione el departamento:\n";
        cout << "1. Recursos Humanos\n2. Compras\n3. Ventas\n4. Almacen\n5. Contabilidad\n";
        cin >> departamento;

        if (departamento < 1 || departamento > 5) {
            cout << "Departamento invalido. Intentalo de nuevo.\n";
            continue;
        }

        cout << "Ingrese el salario del empleado: ";
        cin >> salario;

        total_nomina[departamento - 1] += salario;

        cout << "¿Desea ingresar otro salario? (s/n): ";
        cin >> continuar;
    } while (continuar == 's' || continuar == 'S');

    // Identificar el departamento con mayor nómina
    double max_nomina = total_nomina[0];
    int dep_mayor_nomina = 0;
    for (int i = 1; i < 5; ++i) {
        if (total_nomina[i] > max_nomina) {
            max_nomina = total_nomina[i];
            dep_mayor_nomina = i;
        }
    }

    // Mostrar resultados
    const char* nombres_departamentos[] = {"Recursos Humanos", "Compras", "Ventas", "Almacen", "Contabilidad"};
    cout << "\nMonto acumulado por departamento:\n";
    for (int i = 0; i < 5; ++i) {
        cout << nombres_departamentos[i] << ": $" << total_nomina[i] << "\n";
    }

    cout << "\nEl departamento con mayor pago de nomina es: " 
         << nombres_departamentos[dep_mayor_nomina] 
         << " con $" << max_nomina << "\n";

    return 0;
}
