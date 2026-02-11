#pragma once
#include <iostream>
using namespace std;

template <class T>
class GraphM {
private:
    static constexpr int MAX = 4;
    T vertex[MAX];
    int matAdj[MAX][MAX];
    int size;
public:
    GraphM();
    bool addVertex(const T& data);
    bool addEdge(const T& from, const T& to, int weight);
    int findVertex(const T& data) const;
    void print() const;
};

template <class T>
GraphM<T>::GraphM() : size(0) {
    for (int i = 0; i < MAX; ++i)
        for (int j = 0; j < MAX; ++j)
            matAdj[i][j] = 0;
}

template <class T>
int GraphM<T>::findVertex(const T& data) const {
    for (int i = 0; i < size; ++i)
        if (vertex[i] == data)
            return i;
    return -1;
}

template <class T>
bool GraphM<T>::addVertex(const T& data) {
    if (findVertex(data) == -1 && size < MAX) {
        vertex[size++] = data;
        return true;
    }
    return false;
}

template <class T>
bool GraphM<T>::addEdge(const T& from, const T& to, int weight) {
    int posF = findVertex(from);
    int posT = findVertex(to);
    if (posF != -1 && posT != -1 && posF != posT) {
        matAdj[posF][posT] = weight;
        matAdj[posT][posF] = weight;
        return true;
    }
    return false;
}

template <class T>
void GraphM<T>::print() const {
    cout << "Vertices (" << size << "): ";
    for (int i = 0; i < size; ++i) {
        cout << vertex[i];
        if (i + 1 < size) cout << ", ";
    }
    cout << "\nMatriz de adyacencia (pesos):\n   ";
    for (int i = 0; i < size; ++i) cout << i << " ";
    cout << '\n';
    for (int i = 0; i < size; ++i) {
        cout << i << ": ";
        for (int j = 0; j < size; ++j)
            cout << matAdj[i][j] << " ";
        cout << '\n';
    }
}
