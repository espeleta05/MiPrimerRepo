#include <iostream>
using namespace std;

const int TAM = 10;

int main() {
    string productos[TAM];
    float precios[TAM];
    int existencias[TAM];
    int opcion;
    bool salir = false;

    for (int i = 0; i < TAM; i++) {
        productos[i] = "Sin nombre";
        precios[i] = 0.0;
        existencias[i] = 0;
    }

    while (!salir) {
        cout << "\n Menu \n";
        cout << "1. Alta de productos\n";
        cout << "2. Cambio de precio de un producto\n";
        cout << "3. Mostrar existencia de un producto\n";
        cout << "4. Mostrar relacion de productos, precios y existencias\n";
        cout << "5. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1: {
            cout << "\n Alta de productos \n";
            for (int i = 0; i < TAM; i++) {
                cout << "Producto " << i + 1 << ":\n";
                cout << "Nombre: ";
                cin >> productos[i];
                cout << "Precio: ";
                cin >> precios[i];
                cout << "Existencias: ";
                cin >> existencias[i];
            }
            break;
        }
        case 2: {
            int productoId;
            cout << "\n Cambio de precio \n";
            cout << "Ingresa el numero del producto (1-" << TAM << "): ";
            cin >> productoId;

            if (productoId >= 1 && productoId <= TAM) {
                cout << "Producto seleccionado: " << productos[productoId - 1] << endl;
                cout << "Precio actual: $" << precios[productoId - 1] << endl;
                cout << "Ingresa el nuevo precio: ";
                cin >> precios[productoId - 1];
                cout << "Precio actualizado correctamente.\n";
            } else {
                cout << "Producto no valido.\n";
            }
            break;
        }
        case 3: {
            int productoId;
            cout << "\n Mostrar existencia \n";
            cout << "Ingresa el numero del producto (1-" << TAM << "): ";
            cin >> productoId;

            if (productoId >= 1 && productoId <= TAM) {
                cout << "Producto: " << productos[productoId - 1] << endl;
                cout << "Existencias: " << existencias[productoId - 1] << endl;
            } else {
                cout << "Producto no valido.\n";
            }
            break;
        }
        case 4: {
            cout << "\n Relacion de productos \n";
            cout << "Producto\tPrecio\tExistencia\n";
            for (int i = 0; i < TAM; i++) {
                cout << productos[i] << "\t" << precios[i] << "\t" << existencias[i] << endl;
            }
            break;
        }
        case 5:
            salir = true;
            cout << "Saliendo\n";
            break;
        default:
            cout << "Opción no valida, Intente otra vez.\n";
        }

        // Calcular producto con el menor precio
        int menorPrecio = precios[0]; 
        bool encontrado = false;

        for (int i = 1; i < TAM; i++) {
            if (precios[i] > 0.0) {  
                if (!encontrado || precios[i] < precios[menorPrecio]) {
                    menorPrecio = i;
                    encontrado = true;
                }
            }
        }

        if (encontrado) {
            cout << "\nProducto con el menor precio: \n";
            cout << "Producto: " << productos[menorPrecio] << endl;
            cout << "Precio: $" << precios[menorPrecio] << endl;
            cout << "Existencias: " << existencias[menorPrecio] << endl;
        } else {
            cout << "No hay productos con precio válido.\n";
        }
    }

    cout << "Fin\n";    
    return 0;
}
