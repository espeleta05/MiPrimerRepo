template < class T >
class ListaEjercicio {
    public:
    ListaEjercicio();
    bool agrega(T data);
    int getSize();
    T getElemen(int pos);
    int posicion(T data);
    private: 
    int size;
    T ListaDatos[20];

};

template <class T>
ListaEjercicio<T>::ListaEjercicio() {
    size = 0;
}

template <class T>
bool ListaEjercicio<T>::agrega(T data) {
    if (size < 20){
        ListaDatos[size]= data;
        size++;
        return true;
    }
    else {
        return false;
    }
}

template <class T>
int ListaEjercicio<T>::getSize(){
    return size;
}

template <class T>
T ListaEjercicio<T>::getElemen(int pos) {
    // precondicion que pos < size
    return ListaDatos[pos];
}

template <class T>
int ListaEjercicio<T>::posicion(T data) {
    int pos = -1;
    for (int i = 0; i < size; i++) {
        if (ListaDatos[i] == data) {
            pos = i;
        }
    }
    return pos;
}