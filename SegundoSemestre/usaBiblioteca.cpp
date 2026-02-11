#include <iostream>
#include <fstream>
#include "Biblioteca.h"
using namespace std;

void mostrarLibro(Libro libro) {
    cout << "\n--- LIBRO ---\n";
    cout << "Titulo: " << libro.getTitulo() << endl;
    cout << "Ano: " << libro.getAnioPublicacion() << endl;
    cout << "Precio: $" << libro.getPrecio() << endl;
    cout << "Autor: " << libro.getAutor().getNombre();
    cout << " (" << libro.getAutor().getNacionalidad() << ")\n";
}

void guardarAutores(Autor* autores, int numAutores, const string& archivo) {
    ofstream file(archivo);
    for (int i = 0; i < numAutores; i++) {
        file << autores[i].getId() << ","
             << autores[i].getNombre() << ","
             << autores[i].getNacionalidad() << ","
             << autores[i].getNumLibrosPublicados() << "\n";
    }
    file.close();
}

int main() {
    Biblioteca biblioteca;
    Autor* autores = new Autor[50];
    int numAutores = 0;

    
    ifstream archAutores("Autores.txt");
    string linea;
    while (getline(archAutores, linea)) {
        size_t pos1 = linea.find(',');
        size_t pos2 = linea.find(',', pos1 + 1);
        size_t pos3 = linea.find(',', pos2 + 1);

        autores[numAutores].setId(stoi(linea.substr(0, pos1)));
        autores[numAutores].setNombre(linea.substr(pos1 + 1, pos2 - pos1 - 1));
        autores[numAutores].setNacionalidad(linea.substr(pos2 + 1, pos3 - pos2 - 1));
        autores[numAutores].setNumLibrosPublicados(stoi(linea.substr(pos3 + 1)));
        
        numAutores++;
    }
    archAutores.close();

    
    biblioteca.cargarLibros("libros.txt", autores, numAutores);

    int opcion;
    string titulo;
    int anio, idAutor;
    double precio;

    do {
        cout << "\n--- BIBLIOTECA DIGITAL ---\n";
        cout << "1. Agregar libro\n";
        cout << "2. Eliminar libro\n";
        cout << "3. Mostrar todos los libros\n";
        cout << "4. Buscar libro por titulo\n";
        cout << "5. Guardar y salir\n";
        cout << "Opcion: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
        case 1: {
            cout << "Titulo: ";
            getline(cin, titulo);
            cout << "Anio: ";
            cin >> anio;
            cout << "Precio: ";
            cin >> precio;
            cout << "ID Autor (1-" << numAutores << "): ";
            cin >> idAutor;
            cin.ignore();

            bool autorEncontrado = false;
            Autor autor;
            for (int i = 0; i < numAutores; i++) {
                if (autores[i].getId() == idAutor) {
                    autor = autores[i];
                    autorEncontrado = true;
                    break;
                }
            }

            if (!autorEncontrado) {
                cout << "ID Autor no valido!\n";
                break;
            }

            Libro nuevo(titulo, anio, precio, autor);
            biblioteca += nuevo;
            cout << "Libro agregado!\n";
            break;
        }
        case 2: {
            cout << "Titulo del libro a eliminar: ";
            getline(cin, titulo);
            biblioteca -= titulo;
            cout << "Libro eliminado (si existia).\n";
            break;
        }
        case 3: {
            cout << "\n--- LISTA COMPLETA DE LIBROS ---\n";
            Libro* libros = biblioteca.getLibros();
            for (int i = 0; i < biblioteca.getCantidad(); i++) {
                mostrarLibro(libros[i]);
            }
            break;
        }
        case 4: {
            cout << "Titulo a buscar: ";
            getline(cin, titulo);
            bool encontrado = false;
            Libro* libros = biblioteca.getLibros();
            
            for (int i = 0; i < biblioteca.getCantidad(); i++) {
                if (libros[i].getTitulo().find(titulo) != string::npos) {
                    mostrarLibro(libros[i]);
                    encontrado = true;
                }
            }
            
            if (!encontrado) {
                cout << "No se encontraron libros con ese titulo.\n";
            }
            break;
        }
        case 5: {
            
            biblioteca.guardarLibros("libros.txt");
            guardarAutores(autores, numAutores, "Autores.txt");
            cout << "Datos guardados en archivos originales. Saliendo...\n";
            break;
        }
        default:
            cout << "Opcion no valida. Intente de nuevo.\n";
        }
    } while (opcion != 5);

    delete[] autores;
    return 0;
}