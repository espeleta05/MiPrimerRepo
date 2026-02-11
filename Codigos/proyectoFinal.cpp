#include <iostream>  // Incluyendo la biblioteca para entrada/salida estándar
#include <algorithm> // Para transformar la cadena a minusculas

using namespace std;

string uusuario; // Variable para almacenar el nombre de usuario

int main()
{
    string usuario = "eugenio";    // Usuario en minusculas para comparar uniformemente
    int contra = 1234;             // Establece la contrasena
    int contador = 0;              // Define que el contador de intentos inicie en 0
    int contraUsuario;             // Definiendo la variable para la contrasena ingresada
    const int intentosMaximos = 5; // Define la cantidad de intentos disponibles

    int hs = 0, hq = 0, hsd = 0, hqd = 0, hv = 0, hvd = 0, hp = 0, agua = 0, refresco = 0, aguan = 0, papas = 0, galleta = 0, nieve = 0, brownie = 0; // contadores
    double total = 0;

    do
    {                                   // Inicio del while
        cout << "Ingrese su usuario: "; // Se pide y se lee el usuario
        cin >> uusuario;

        // Convertir entrada del usuario a minusculas
        transform(uusuario.begin(), uusuario.end(), uusuario.begin(), ::tolower);

        if (uusuario == usuario)
        { // Si el usuario existe, se pide y se lee la contrasena
            cout << "Ingresa tu contrasena: ";
            cin >> contraUsuario;
            contador++;

            if (contraUsuario == contra)
            { // Si la contrasena es correcta, se le concede el acceso
                cout << "Acceso concedido." << endl;

                cout << "Bienvenido, a continuacion se le mostrara el menu.\nFavor de seleccionar la accion que quiere realizar.\n";
                bool salir = false;
                int opcion;

                // Menu principal
                while (!salir)
                {
                    cout << "\nAcciones disponibles:\n";
                    cout << "1. Anadir articulos\n";
                    cout << "2. Remover articulos\n";
                    cout << "3. Ver articulos en el carrito\n";
                    cout << "4. Proceder al pago\n";
                    cin >> opcion;

                    int menu, bebida, postre;

                    // Caso segun la opcion seleccionada
                    switch (opcion)
                    {
                    case 1:
                    { // Anadir articulos
                        cout << "Seleccione el articulo que quiera agregar al carrito:\n";
                        cout << "\n---Menu---\n";
                        cout << "1. Hamburguesa simple - $75\n2. Hamburguesa con queso - $80\n3. Hamburguesa simple doble - $85\n4. Hamburguesa con queso doble - $90\n5. Hamburguesa vegetariana - $80\n6. Hamburguesa vegetariana doble - $90\n7. Hamburguesa de pollo - $80\n8. Bebida - $25-$40\n9. Papas a la francesa - $35\n10. Postre - $25-$50\n";
                        cin >> menu;

                        switch (menu)
                        {
                        case 1:
                            cout << "Se anadio una Hamburguesa simple - $75\n";
                            hs++;
                            total += 75;
                            break;
                        case 2:
                            cout << "Se anadio una Hamburguesa con queso - $80\n";
                            hq++;
                            total += 80;
                            break;
                        case 3:
                            cout << "Se anadio una Hamburguesa simple doble - $85\n";
                            hsd++;
                            total += 85;
                            break;
                        case 4:
                            cout << "Se anadio una Hamburguesa con queso doble - $90\n";
                            hqd++;
                            total += 90;
                            break;
                        case 5:
                            cout << "Se anadio una Hamburguesa vegetariana - $80\n";
                            hv++;
                            total += 80;
                            break;
                        case 6:
                            cout << "Se anadio una Hamburguesa vegetariana doble - $90\n";
                            hvd++;
                            total += 90;
                            break;
                        case 7:
                            cout << "Se anadio una Hamburguesa de pollo - $80\n";
                            hp++;
                            total += 80;
                            break;
                        case 8:
                            cout << "Seleccione una bebida\n";
                            cout << "1. Agua - $25\n2. Refresco - $40\n3. Aguas naturales - $35\n";
                            cin >> bebida;

                            switch (bebida)
                            {
                            case 1:
                                cout << "Se anadio Agua - $25\n";
                                agua++;
                                total += 25;
                                break;
                            case 2:
                                cout << "Se anadio Refresco - $40\n";
                                refresco++;
                                total += 40;
                                break;
                            case 3:
                                cout << "Se anadio Agua natural - $35\n";
                                aguan++;
                                total += 35;
                                break;
                            default:
                                cout << "Articulo no encontrado\n";
                                break;
                            }
                            break;
                        case 9:
                            cout << "Se anadio una orden de Papas a la francesa - $35\n";
                            papas++;
                            total += 35;
                            break;
                        case 10:
                            cout << "Seleccione su postre\n";
                            cout << "1. Galleta de chocolate - $25\n2. Cono de nieve - $35\n3. Brownie con nieve - $50\n";
                            cin >> postre;

                            switch (postre)
                            {
                            case 1:
                                cout << "Se anadio Galleta de chocolate - $25\n";
                                galleta++;
                                total += 25;
                                break;
                            case 2:
                                cout << "Se anadio Cono de nieve - $35\n";
                                nieve++;
                                total += 35;
                                break;
                            case 3:
                                cout << "Se anadio Brownie con nieve - $50\n";
                                brownie++;
                                total += 50;
                                break;
                            default:
                                cout << "Articulo no encontrado\n";
                                break;
                            }
                            break;
                        default:
                            cout << "Articulo no encontrado, intente otra vez\n";
                            break;
                        }
                        break;
                    }

                    case 2:
                        cout << "Seleccione el articulo que quiere remover del carrito:\n";
                        cout << "\n---Carrito---\n";

                        // Mostrar los articulos en el carrito con sus cantidades
                        if (hs > 0)
                            cout << "1. Hamburguesa simple - Cantidad: " << hs << " - $75 cada una\n";
                        if (hq > 0)
                            cout << "2. Hamburguesa con queso - Cantidad: " << hq << " - $80 cada una\n";
                        if (hsd > 0)
                            cout << "3. Hamburguesa simple doble - Cantidad: " << hsd << " - $85 cada una\n";
                        if (hqd > 0)
                            cout << "4. Hamburguesa con queso doble - Cantidad: " << hqd << " - $90 cada una\n";
                        if (hv > 0)
                            cout << "5. Hamburguesa vegetariana - Cantidad: " << hv << " - $80 cada una\n";
                        if (hvd > 0)
                            cout << "6. Hamburguesa vegetariana doble - Cantidad: " << hvd << " - $90 cada una\n";
                        if (hp > 0)
                            cout << "7. Hamburguesa de pollo - Cantidad: " << hp << " - $80 cada una\n";
                        if (agua > 0)
                            cout << "8. Agua - Cantidad: " << agua << " - $25 cada una\n";
                        if (refresco > 0)
                            cout << "9. Refresco - Cantidad: " << refresco << " - $40 cada uno\n";
                        if (aguan > 0)
                            cout << "10. Agua natural - Cantidad: " << aguan << " - $35 cada una\n";
                        if (papas > 0)
                            cout << "11. Papas a la francesa - Cantidad: " << papas << " - $35 cada orden\n";
                        if (galleta > 0)
                            cout << "12. Galleta de chocolate - Cantidad: " << galleta << " - $25 cada una\n";
                        if (nieve > 0)
                            cout << "13. Cono de nieve - Cantidad: " << nieve << " - $35 cada uno\n";
                        if (brownie > 0)
                            cout << "14. Brownie con nieve - Cantidad: " << brownie << " - $50 cada uno\n";

                        int quitar;
                        cout << "Ingrese el numero del articulo que desea quitar: ";
                        cin >> quitar;

                        // Eliminar el articulo seleccionado
                        switch (quitar)
                        {
                        case 1:
                            if (hs > 0)
                            {
                                hs--;
                                total -= 75;
                                cout << "Se quito una Hamburguesa simple - $75\n";
                            }
                            else
                                cout << "No tienes Hamburguesas simples en el carrito.\n";
                            break;
                        case 2:
                            if (hq > 0)
                            {
                                hq--;
                                total -= 80;
                                cout << "Se quito una Hamburguesa con queso - $80\n";
                            }
                            else
                                cout << "No tienes Hamburguesas con queso en el carrito.\n";
                            break;
                        case 3:
                            if (hsd > 0)
                            {
                                hsd--;
                                total -= 85;
                                cout << "Se quito una Hamburguesa simple doble - $85\n";
                            }
                            else
                                cout << "No tienes Hamburguesas simples dobles en el carrito.\n";
                            break;
                        case 4:
                            if (hqd > 0)
                            {
                                hqd--;
                                total -= 90;
                                cout << "Se quito una Hamburguesa con queso doble - $90\n";
                            }
                            else
                                cout << "No tienes Hamburguesas con queso dobles en el carrito.\n";
                            break;
                        case 5:
                            if (hv > 0)
                            {
                                hv--;
                                total -= 80;
                                cout << "Se quito una Hamburguesa vegetariana - $80\n";
                            }
                            else
                                cout << "No tienes Hamburguesas vegetarianas en el carrito.\n";
                            break;
                        case 6:
                            if (hvd > 0)
                            {
                                hvd--;
                                total -= 90;
                                cout << "Se quito una Hamburguesa vegetariana doble - $90\n";
                            }
                            else
                                cout << "No tienes Hamburguesas vegetarianas dobles en el carrito.\n";
                            break;
                        case 7:
                            if (hp > 0)
                            {
                                hp--;
                                total -= 80;
                                cout << "Se quito una Hamburguesa de pollo - $80\n";
                            }
                            else
                                cout << "No tienes Hamburguesas de pollo en el carrito.\n";
                            break;
                        case 8:
                            if (agua > 0)
                            {
                                agua--;
                                total -= 25;
                                cout << "Se quito una Agua - $25\n";
                            }
                            else
                                cout << "No tienes Agua en el carrito.\n";
                            break;
                        case 9:
                            if (refresco > 0)
                            {
                                refresco--;
                                total -= 40;
                                cout << "Se quito un Refresco - $40\n";
                            }
                            else
                                cout << "No tienes Refrescos en el carrito.\n";
                            break;
                        case 10:
                            if (aguan > 0)
                            {
                                aguan--;
                                total -= 35;
                                cout << "Se quito un Agua natural - $35\n";
                            }
                            else
                                cout << "No tienes Agua natural en el carrito.\n";
                            break;
                        case 11:
                            if (papas > 0)
                            {
                                papas--;
                                total -= 35;
                                cout << "Se quito una orden de Papas a la francesa - $35\n";
                            }
                            else
                                cout << "No tienes Papas a la francesa en el carrito.\n";
                            break;
                        case 12:
                            if (galleta > 0)
                            {
                                galleta--;
                                total -= 25;
                                cout << "Se quito una Galleta de chocolate - $25\n";
                            }
                            else
                                cout << "No tienes Galletas de chocolate en el carrito.\n";
                            break;
                        case 13:
                            if (nieve > 0)
                            {
                                nieve--;
                                total -= 35;
                                cout << "Se quito un Cono de nieve - $35\n";
                            }
                            else
                                cout << "No tienes Conos de nieve en el carrito.\n";
                            break;
                        case 14:
                            if (brownie > 0)
                            {
                                brownie--;
                                total -= 50;
                                cout << "Se quito un Brownie con nieve - $50\n";
                            }
                            else
                                cout << "No tienes Brownie con nieve en el carrito.\n";
                            break;
                        default:
                            cout << "Opcion no valida. Intente de nuevo.\n";
                            break;
                        }
                        break;

                    case 3: // Ver articulos en el carrito
                        cout << "Carrito:\n";
                        cout << "Hamburguesas:\n";
                        cout << "Hamburguesas simples: " << hs << endl;
                        cout << "Hamburguesas con queso: " << hq << endl;
                        cout << "Hamburguesas dobles: " << hsd << endl;
                        cout << "Hamburguesas con queso dobles: " << hqd << endl;
                        cout << "Hamburguesas vegetarianas: " << hv << endl;
                        cout << "Hamburguesas vegetarianas dobles: " << hvd << endl;
                        cout << "Hamburguesas de pollo: " << hp << endl;
                        cout << "Bebidas:\n";
                        cout << "Agua: " << agua << endl;
                        cout << "Refrescos: " << refresco << endl;
                        cout << "Agua natural: " << aguan << endl;
                        cout << "Postres:\n";
                        cout << "Galletas: " << galleta << endl;
                        cout << "Conos de nieve: " << nieve << endl;
                        cout << "Brownie con nieve: " << brownie << endl;
                        cout << "Total: $" << total << endl;
                        break;

                    case 4: // Proceder al pago
                        cout << "Total a pagar: $" << total << endl;
                        cout << "Pago exitoso. Gracias por su compra.\n";
                        salir = true; // Salir despues de realizar el pago
                        return 0;

                    default:
                        cout << "Opcion no valida, intente de nuevo.\n";
                        break;
                    }
                }
            }
            else
            { // Si la contrasena es incorrecta, se notifica y se permite un nuevo intento
                cout << "Contrasena incorrecta. Intentos restantes: " << intentosMaximos - contador << endl;
            }
        }
        else
        { // Si el usuario es incorrecto
            cout << "Usuario incorrecto.\n";
        }
    } while (contador < intentosMaximos); // Limite de intentos
    return 0;
}   