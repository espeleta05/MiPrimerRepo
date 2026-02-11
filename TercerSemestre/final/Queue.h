#include <iostream>
using namespace std;
#include "node.h"

template <class T>
class Queue {
private:
    Node<T> *head;
    int size;

public:
    Queue() {
        size = 0;
        head = nullptr;
    }

    int getSize() {
        return size;
    }

    bool isEmpty() {
        return head == nullptr ? true : false;
    }

    void enqueue(T valor);
    T dequeue();
    T front();
    T back();
    void print();
    void clear();
};

// Insertar al final
template <class T>
void Queue<T>::enqueue(T valor) {
    Node<T> *ptrNuevo = new Node<T>(valor);
    if (head == nullptr) {
        head = ptrNuevo;
    } else {
        Node<T> *aux = head;
        while (aux->next != nullptr) {
            aux = aux->next;
        }
        aux->next = ptrNuevo;
    }
    size++;
}

// Eliminar primer elemento
template <class T>
T Queue<T>::dequeue() {
    if (!isEmpty()) {
        T valor = head->data;
        Node<T> *aux = head;
        head = aux->next;
        size--;
        delete aux;
        return valor;
    } else {
        throw runtime_error("Fila vacía");
    }
}

// Ver primer elemento
template <class T>
T Queue<T>::front() {
    if (!isEmpty()) {
        return head->data;
    } else {
        throw runtime_error("Fila vacía");
    }
}

// Ver último elemento
template <class T>
T Queue<T>::back() {
    if (!isEmpty()) {
        Node<T> *aux = head;
        while (aux->next != nullptr) {
            aux = aux->next;
        }
        return aux->data;
    } else {
        throw runtime_error("Fila vacía");
    }
}

// Imprimir todos los elementos
template <class T>
void Queue<T>::print() {
    Node<T> *aux = head;
    while (aux != nullptr) {
        cout << aux->data << " ";
        aux = aux->next;
    }
    cout << endl;
}

// Vaciar la cola
template <class T>
void Queue<T>::clear() {
    while (head != nullptr) {
        Node<T> *aux = head;
        head = head->next;
        delete aux;
        size--;
    }
}