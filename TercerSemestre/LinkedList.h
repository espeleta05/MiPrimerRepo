#include "node.h"
#include <iostream>
using namespace std;

template <class T>
class LinkedList {
private:
    Node<T> *head;
    int size;
public:
    LinkedList();
    ~LinkedList();
    void addLast(T data);
    void addFirst(T data);
    T getData(int index);
    int findData(T data);
    bool deleteData(T data);
    bool deleteAt(int index);
    void updateData(T data, T newData);
    void updateAt(int index, T newData);
    int getSize() { return size; }
    void print();
    void clear();
    bool isEmpty();
};

template <class T>
LinkedList<T>::LinkedList() : head(nullptr), size(0) {}

template <class T>
LinkedList<T>::~LinkedList() {
    clear();
}

template <class T>
bool LinkedList<T>::isEmpty() {
    return head == nullptr;
}

template <class T>
void LinkedList<T>::addFirst(T valor) {
    Node<T> *ptrnuevo = new Node<T>(valor);
    ptrnuevo->next = head;
    head = ptrnuevo;
    size++;
}

template <class T>
void LinkedList<T>::addLast(T valor) {
    Node<T> *ptrnuevo = new Node<T>(valor);
    if (head == nullptr) {
        head = ptrnuevo;
    } else {
        Node<T> *aux = head;
        while (aux->next != nullptr) {
            aux = aux->next;
        }
        aux->next = ptrnuevo;
    }
    size++;
}

template <class T>
void LinkedList<T>::print() {
    Node<T> *aux = head;
    while (aux != nullptr) {
        cout << aux->data << " ";
        aux = aux->next;
    }
    cout << endl;
}

template <class T>
T LinkedList<T>::getData(int index) {
    if (index < 0 || index >= size) {
        throw out_of_range("Index out of range");
    }
    Node<T> *aux = head;
    for (int i = 0; i < index; i++) {
        aux = aux->next;
    }
    return aux->data;
}

template <class T>
int LinkedList<T>::findData(T valor) {
    Node<T> *aux = head;
    int pos = 0;
    while (aux != nullptr) {
        if (aux->data == valor) {
            return pos;
        }
        aux = aux->next;
        pos++;
    }
    return -1;
}

template <class T>
bool LinkedList<T>::deleteData(T valor) {
    if (head == nullptr) return false;
    if (head->data == valor) {
        Node<T> *tmp = head;
        head = head->next;
        delete tmp;
        size--;
        return true;
    }
    Node<T> *aux = head;
    while (aux->next != nullptr && aux->next->data != valor) {
        aux = aux->next;
    }
    if (aux->next == nullptr) return false;
    Node<T> *tmp = aux->next;
    aux->next = tmp->next;
    delete tmp;
    size--;
    return true;
}

template <class T>
bool LinkedList<T>::deleteAt(int index) {
    if (index < 0 || index >= size) return false;
    if (index == 0) {
        Node<T> *tmp = head;
        head = head->next;
        delete tmp;
        size--;
        return true;
    }
    Node<T> *aux = head;
    for (int i = 0; i < index - 1; i++) {
        aux = aux->next;
    }
    Node<T> *tmp = aux->next;
    aux->next = tmp->next;
    delete tmp;
    size--;
    return true;
}

template <class T>
void LinkedList<T>::updateData(T data, T newData) {
    Node<T> *aux = head;
    while (aux != nullptr) {
        if (aux->data == data) {
            aux->data = newData;
            return;
        }
        aux = aux->next;
    }
}

template <class T>
void LinkedList<T>::updateAt(int index, T newData) {
    if (index < 0 || index >= size) return;
    Node<T> *aux = head;
    for (int i = 0; i < index; i++) {
        aux = aux->next;
    }
    aux->data = newData;
}

template <class T>
void LinkedList<T>::clear() {
    while (head != nullptr) {
        Node<T> *tmp = head;
        head = head->next;
        delete tmp;
        size--;
    }
}