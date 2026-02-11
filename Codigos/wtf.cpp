#include <iostream>
#include <cstring>
using namespace std;

const char usuarios[][20] = {"cliente1", "cliente2", "cliente3"};
const char contrasenas[][20] = {"pass123", "abc123", "qwerty"};
const int numUsuarios = 3;

const char comida[][20] = {"Hamburguesa", "Papas Fritas", "Refresco", "Helado"};
const double precios[] = {5.99, 2.99, 1.99, 3.50};
const int numComidas = 4;

bool validarUsuario(char usuario[], char contrasena[])
{
    for (int i = 0; i < numUsuarios; i++)
    {
        if (strcmp(usuarios[i], usuario) == 0 && strcmp(contrasenas[i], contrasena) == 0)
        {
            return true;
        }
    }
    return false;
}

void mostrarMenu()
{
    cout << "\n--- MENÚ DE COMIDA ---\n";
    for (int i = 0; i < numComidas; i++)
    {
        cout << i + 1 << ". " << comida[i] << " - $" << precios[i] << endl;
    }
    cout << "5. Quitar artículo del carrito\n";
    cout << "6. Ver carrito\n";
    cout << "7. Pagar\n";
    cout << "8. Salir\n";
    cout << "Seleccione una opción: ";
}

double aplicarDescuento(double total)
{
    char codigo[10];
    cout << "¿Tiene un código de descuento? (s/n): ";
    char respuesta;
    cin >> respuesta;

    if (respuesta == 's' || respuesta == 'S')
    {
        cout << "Ingrese el código de descuento: ";
        cin >> codigo;

        if (strcmp(codigo, "DESC10") == 0)
        {
            return total * 0.90;
        }
        else if (strcmp(codigo, "DESC15") == 0)
        {
            return total * 0.85;
        }
        else if (strcmp(codigo, "DESC20") == 0)
        {
            return total * 0.80;
        }
        else
        {
            cout << "Código de descuento inválido.\n";
        }
    }
    return total;
}

int main()
{
    char usuario[20], contrasena[20];
    double total = 0.0;
    int carrito[10] = {0};
    int opcion;
    int intentos = 0;

    bool accesoPermitido = false;
    while (intentos < 3 && !accesoPermitido)
    {
        cout << "Ingrese su usuario: ";
        cin >> usuario;
        cout << "Ingrese su contraseña: ";
        cin >> contrasena;

        if (validarUsuario(usuario, contrasena))
        {
            accesoPermitido = true;
        }
        else
        {
            intentos++;
            if (intentos < 3)
            {
                cout << "Usuario o contraseña incorrectos. Intentos restantes: " << (3 - intentos) << endl;
            }
            else
            {
                cout << "Ha excedido el número de intentos. Acceso denegado.\n";
                return 0;
            }
        }
    }

    cout << "¡Bienvenido al sistema de autocobro!\n";

    do
    {
        mostrarMenu();
        cin >> opcion;

        switch (opcion)
        {
        case 1:
        case 2:
        case 3:
        case 4:
        {
            int indice = opcion - 1;
            carrito[indice]++;
            total += precios[indice];
            cout << comida[indice] << " agregado al carrito. Total: $" << total << endl;
            break;
        }
        case 5:
        {
            cout << "Carrito actual:\n";
            for (int i = 0; i < numComidas; i++)
            {
                if (carrito[i] > 0)
                {
                    cout << i + 1 << ". " << comida[i] << " - Cantidad: " << carrito[i] << endl;
                }
            }

            cout << "Seleccione el número del artículo a quitar: ";
            int indice;
            cin >> indice;
            indice--;

            if (indice >= 0 && indice < numComidas && carrito[indice] > 0)
            {
                carrito[indice]--;
                total -= precios[indice];
                cout << comida[indice] << " eliminado del carrito. Total: $" << total << endl;
            }
            else
            {
                cout << "Selección inválida.\n";
            }
            break;
        }
        case 6:
        {
            cout << "Artículos en el carrito:\n";
            for (int i = 0; i < numComidas; i++)
            {
                if (carrito[i] > 0)
                {
                    cout << comida[i] << " - Cantidad: " << carrito[i] << " - Total: $" << carrito[i] * precios[i] << endl;
                }
            }
            cout << "Total: $" << total << endl;
            break;
        }
        case 7:
        {
            double totalConDescuento = aplicarDescuento(total);
            cout << "El total final a pagar es: $" << totalConDescuento << endl;
            cout << "Pago realizado exitosamente. Recoja su pedido en la ventanilla 2.\n";
            for (int i = 0; i < numComidas; i++)
            {
                carrito[i] = 0;
            }
            total = 0.0;
            break;
        }
        case 8:
            cout << "Gracias por usar nuestro sistema. ¡Hasta luego!\n";
            break;
        default:
            cout << "Opción inválida. Intente de nuevo.\n";
        }
    } while (opcion != 8);

    return 0;
}