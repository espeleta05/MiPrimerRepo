#include <iostream>

namespace Ejemplo {
    void mostrarMensaje() {
        std::cout << "Hola desde el namespace Ejemplo!" << std::endl;
    }
}
namespace NuevoEjemplo {
    void mostrarMensaje() {
        std::cout << "Hola desde el namespace NuevoEjemplo!" << std::endl;
    }
}

int main() {
    Ejemplo::mostrarMensaje();
    NuevoEjemplo::mostrarMensaje();
    
    return 0;
}