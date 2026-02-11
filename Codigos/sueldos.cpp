#include <iostream>

using namespace std;

int main()
{
    float sueldoAgosto, sueldoSeptiembre, porcentajeAumento;

    cout << "Ingrese el sueldo del mes de agosto: ";
    cin >> sueldoAgosto;

    cout << "Ingrese el sueldo del mes de septiembre: ";
    cin >> sueldoSeptiembre;

    float auxiliar = sueldoSeptiembre + sueldoAgosto;
    porcentajeAumento = ((sueldoSeptiembre - sueldoAgosto) / sueldoAgosto) * 100;

    cout << "El porcentaje de aumento es: " << porcentajeAumento << "%" << endl;

    return 0;
}