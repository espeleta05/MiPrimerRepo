#include <iostream>
using namespace std;

int main()
{
    int num_clientes = 0;
    string mas_clientes = "Si";

    while (mas_clientes == "Si" || mas_clientes == "si" || mas_clientes == "s" || mas_clientes == "S")
    {
        int num_articulos;
        float subtotal = 0, iva, total, descuento = 0;
        string cupon;

        cout << "Cuantos articulos va a comprar el cliente? (sin limite): ";
        cin >> num_articulos;

        float precios[num_articulos];

        for (int i = 0; i < num_articulos; i++)
        {
            cout << "Precio del articulo " << i + 1 << ": ";
            cin >> precios[i];
            subtotal += precios[i];
        }

        iva = subtotal * 0.16; // Calcular IVA al 16%
        total = subtotal + iva;

        cout << "Tiene un cupon? Ingrese la clave (si es '3A' se aplica descuento): ";
        cin >> cupon;

        if (cupon == "3A" || cupon == "3a")
        {
            descuento = total * 0.10;
            total -= descuento;
        }

        cout << "\nResumen de compra del cliente:\n";
        cout << "Subtotal: $" << subtotal << endl;
        cout << "IVA: $" << iva << endl;
        cout << "Descuento: $" << descuento << endl;
        cout << "Total: $" << total << endl;

        num_clientes++;

        cout << "\nDesea agregar otro cliente? (Si/No): ";
        cin >> mas_clientes;
    }

    cout << "\nNumero total de clientes que asistieron a la tienda: " << num_clientes << endl;

    return 0;
}
