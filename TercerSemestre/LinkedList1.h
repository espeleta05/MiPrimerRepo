#include <iostream>
#include <stdexcept>
#include "Node.h"

using namespace std;

template <class T>
class LinkedList
{
private:
    Node<T>* head;
    Node<T>* tail;
    int size;

public:
    LinkedList() : head(nullptr), tail(nullptr), size(0) {}
    ~LinkedList() { clear(); }

    int getSize() const { return size; }
    bool isEmpty() const { return size == 0; }

    void insertFirst(const T& valor);
    void insertLast(const T& valor);
    void insertAt(int index, const T& valor);

    bool deleteFirst();
    void deleteLast();
    bool deleteAt(int index);

    T getData(int index) const;
    int getIndex(const T& valor) const;

    void updateData(const T& valorARemplazar, const T& nuevoValor);
    void updateAt(int index, const T& data);

    void print() const;
    void clear();
};

template <class T>
void LinkedList<T>::insertFirst(const T& valor)
{
    Node<T>* nuevo = new Node<T>(valor);
    if (!head)
    {
        head = tail = nuevo;
        nuevo->next = nuevo;
    }
    else
    {
        nuevo->next = head;
        head = nuevo;
        tail->next = head;
    }
    ++size;
}

template <class T>
void LinkedList<T>::insertLast(const T& valor)
{
    Node<T>* nuevo = new Node<T>(valor);
    if (!head)
    {
        head = tail = nuevo;
        nuevo->next = nuevo;
    }
    else
    {
        nuevo->next = head;
        tail->next = nuevo;
        tail = nuevo;
    }
    ++size;
}

template <class T>
void LinkedList<T>::insertAt(int index, const T& valor)
{
    if (index < 0 || index > size)
    {
        cout << "index fuera de rango\n";
        return;
    }

    if (index == 0)
    {
        insertFirst(valor);
        return;
    }

    if (index == size)
    {
        insertLast(valor);
        return;
    }

    Node<T>* nuevo = new Node<T>(valor);
    Node<T>* aux = head;
    for (int i = 0; i < index - 1; ++i)
    {
        aux = aux->next;
    }
    nuevo->next = aux->next;
    aux->next = nuevo;
    ++size;
}

template <class T>
bool LinkedList<T>::deleteFirst()
{
    if (!head)
    {
        return false;
    }

    if (size == 1)
    {
        delete head;
        head = tail = nullptr;
        size = 0;
        return true;
    }

    Node<T>* antiguoHead = head;
    head = head->next;
    tail->next = head;
    delete antiguoHead;
    --size;
    return true;
}

template <class T>
void LinkedList<T>::deleteLast()
{
    if (!head)
    {
        return;
    }

    if (size == 1)
    {
        delete head;
        head = tail = nullptr;
        size = 0;
        return;
    }

    Node<T>* previo = head;
    while (previo->next != tail)
    {
        previo = previo->next;
    }
    previo->next = head;
    delete tail;
    tail = previo;
    --size;
}

template <class T>
bool LinkedList<T>::deleteAt(int index)
{
    if (index < 0 || index >= size || !head)
    {
        return false;
    }

    if (index == 0)
    {
        return deleteFirst();
    }

    if (index == size - 1)
    {
        deleteLast();
        return true;
    }

    Node<T>* previo = head;
    for (int i = 0; i < index - 1; ++i)
    {
        previo = previo->next;
    }
    Node<T>* eliminado = previo->next;
    previo->next = eliminado->next;
    delete eliminado;
    --size;
    return true;
}

template <class T>
T LinkedList<T>::getData(int index) const
{
    if (index < 0 || index >= size)
    {
        throw out_of_range("index fuera de rango");
    }

    Node<T>* aux = head;
    for (int i = 0; i < index; ++i)
    {
        aux = aux->next;
    }
    return aux->data;
}

template <class T>
int LinkedList<T>::getIndex(const T& valor) const
{
    if (!head)
    {
        return -1;
    }

    Node<T>* aux = head;
    for (int i = 0; i < size; ++i)
    {
        if (aux->data == valor)
        {
            return i;
        }
        aux = aux->next;
    }
    return -1;
}

template <class T>
void LinkedList<T>::updateData(const T& valorARemplazar, const T& nuevoValor)
{
    if (!head)
    {
        return;
    }

    Node<T>* puntero = head;
    for (int i = 0; i < size; ++i)
    {
        if (puntero->data == valorARemplazar)
        {
            puntero->data = nuevoValor;
            return;
        }
        puntero = puntero->next;
    }

    cout << "Valor no encontrado\n";
}

template <class T>
void LinkedList<T>::updateAt(int index, const T& data)
{
    if (index < 0 || index >= size)
    {
        cout << "Valor invalido" << endl;
        return;
    }

    Node<T>* aux = head;
    for (int i = 0; i < index; ++i)
    {
        aux = aux->next;
    }
    aux->data = data;
}

template <class T>
void LinkedList<T>::print() const
{
    if (!head)
    {
        return;
    }

    Node<T>* aux = head;
    for (int i = 0; i < size; ++i)
    {
        cout << aux->data << " ";
        aux = aux->next;
    }
    cout << endl;
}

template <class T>
void LinkedList<T>::clear()
{
    while (!isEmpty())
    {
        deleteFirst();
    }
}
