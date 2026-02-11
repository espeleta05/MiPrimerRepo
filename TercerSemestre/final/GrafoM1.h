#include <iostream>
#include "Queue.h"

using namespace std;

template <class T>
class GrafoM {
    private:
        T vertex[100];
        bool status[100];
        int matAdj[100][100];
        int size; 
    public:
        GrafoM();
        bool addVertex(T data);
        bool addEdge(T from, T to, int edge);
        int findVertex(T data);
        void print();
        void BFS(T data); 
        void dijkstra(T from, T to);

        // NUEVA: Dijkstra que regresa ruta y total (SIN vector)
        bool dijkstraPath(T from, T to, int &total, T ruta[], int &rutaSize);
};

template <class T>
GrafoM<T>::GrafoM() {
    size = 0;
    for (int i = 0; i < 100; i++) {
        status[i] = false;
        for (int j = 0; j < 100; j++) {
            matAdj[i][j] = 0;
        }
    }
}

template <class T>
int GrafoM<T>::findVertex(T data) {
    for (int i = 0; i < size; i++) {
        if (vertex[i] == data) {
            return i;
        }
    }
    return -1;
}

template <class T>
bool GrafoM<T>::addVertex(T data) {
    if (findVertex(data) != -1) {
        return true; 
    }

    if (size < 100) {
        vertex[size] = data;
        status[size] = false;
        size++;
        return true;
    }
    
    cout << "No se pudo agregar: " << data << endl;
    return false;
}

template <class T>
bool GrafoM<T>::addEdge(T from, T to, int edge) {
    int posF = findVertex(from);
    int posT = findVertex(to);

    if (posF != -1 && posT != -1) {
        matAdj[posF][posT] = edge;
        matAdj[posT][posF] = edge;
        return true;
    } else {
        return false;
    }
}

// Se imprime como lista de adyacencias
template <class T>
void GrafoM<T>::print() {
    cout << "Size: " << size << endl;
    for (int r = 0; r < size; r++) {
        cout << vertex[r] << " -> ";
        for (int c = 0; c < size; c++) {
            if (matAdj[r][c] > 0) {
                cout << vertex[c] << "(" << matAdj[r][c] << ") ";
            }
        }
        cout << endl;
    }
}

template <class T>
void GrafoM<T>::BFS(T data) {
    int pos = findVertex(data);
    if (pos == -1) {
        cout << "Vertice inicial no encontrado." << endl;
        return;
    }

    for (int k = 0; k < size; k++) {
        status[k] = false;
    }

    Queue<T> fila;
    fila.enqueue(data);
    status[pos] = true;

    cout << "Recorrido: ";
    while (!fila.isEmpty()) {
        T vert = fila.dequeue();
        cout << vert << " ";
        
        int currentPos = findVertex(vert);
        for (int i = 0; i < size; i++) {
            if (matAdj[currentPos][i] > 0 && status[i] == false) {
                fila.enqueue(vertex[i]);
                status[i] = true;
            }
        }
    }
    cout << endl;
}

template <class T>
void GrafoM<T>::dijkstra(T origenData, T destinoData) {
    int s = findVertex(origenData);
    int e = findVertex(destinoData);

    if (s == -1 || e == -1) {
        cout << "Error: Uno de los vertices no existe." << endl;
        return;
    }

    int dist[100];
    bool visited[100];
    int prev[100];
    
    for (int i = 0; i < size; i++) {
        dist[i] = 999999999;
        visited[i] = false;
        prev[i] = -1;
    }
    
    dist[s] = 0;

    for (int count = 0; count < size - 1; count++) {
        int min = 999999999;
        int u = -1;

        for (int i = 0; i < size; i++) {
            if (!visited[i] && dist[i] <= min) {
                min = dist[i];
                u = i;
            }
        }

        if (u == -1) break;
        visited[u] = true;

        for (int v = 0; v < size; v++) {
            if (!visited[v] && matAdj[u][v] > 0 &&
                dist[u] != 999999999 &&
                dist[u] + matAdj[u][v] < dist[v]) {
                
                dist[v] = dist[u] + matAdj[u][v];
                prev[v] = u;
            }
        }
    }

    if (dist[e] == 999999999) {
        cout << "No hay camino entre " << origenData << " y " << destinoData << endl;
    } else {
        cout << "\nRuta mas corta de " << origenData << " a " << destinoData << endl;
        cout << "Distancia Total: " << dist[e] << " km" << endl;
        
        int path[100];
        int pathSize = 0;
        int curr = e;
        
        while (curr != -1) {
            path[pathSize++] = curr;
            curr = prev[curr];
        }

        cout << "Ruta: ";
        for (int i = pathSize - 1; i >= 0; i--) {
            cout << vertex[path[i]];
            if (i > 0) cout << " -> ";
        }
        cout << endl;
    }
}

// ===== NUEVA FUNCION SIN vector =====
template <class T>
bool GrafoM<T>::dijkstraPath(T origenData, T destinoData, int &total, T ruta[], int &rutaSize) {

    int s = findVertex(origenData);
    int e = findVertex(destinoData);

    if (s == -1 || e == -1) return false;

    int dist[100];
    bool visited[100];
    int prev[100];

    for (int i = 0; i < size; i++) {
        dist[i] = 999999999;
        visited[i] = false;
        prev[i] = -1;
    }

    dist[s] = 0;

    for (int count = 0; count < size - 1; count++) {

        int minVal = 999999999;
        int u = -1;

        for (int i = 0; i < size; i++) {
            if (!visited[i] && dist[i] <= minVal) {
                minVal = dist[i];
                u = i;
            }
        }

        if (u == -1) break;
        visited[u] = true;

        for (int v = 0; v < size; v++) {
            if (!visited[v] && matAdj[u][v] > 0 &&
                dist[u] + matAdj[u][v] < dist[v]) {

                dist[v] = dist[u] + matAdj[u][v];
                prev[v] = u;
            }
        }
    }

    if (dist[e] == 999999999) return false;

    // reconstruir ruta en reversa
    int temp[100];
    int k = 0;
    int curr = e;

    while (curr != -1) {
        temp[k++] = curr;
        curr = prev[curr];
    }

    // invertir temp[] en ruta[]
    rutaSize = 0;
    for (int i = k - 1; i >= 0; i--) {
        ruta[rutaSize++] = vertex[temp[i]];
    }

    total = dist[e];
    return true;
}
