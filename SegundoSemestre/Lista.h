const int tamMax=20;
template<class T>
class Lista{
    public:
    Lista();
    int getSize(){return size;};
    bool agrega(T dato);
    T getElement(int pos);
    int posicion(T dato);

    private:
    int size;
    T listaDatos[tamMax];
};

template<class T>
Lista<T>::Lista(){
    size=0;
}
template<class T>
bool Lista<T>::agrega(T dato){
    if(size<tamMax){
        listaDatos[size]=dato;
        size++;
        return true;
    }else{
        return false;
    }
}
template<class T>
int Lista<T>::posicion(T dato){
    int pos=-1;
    int i=0;
    while(pos==-1 && i<size){
        if(listaDatos[i]==dato){
            pos=i;
        }else{
            i++;
        }
    }
    return pos;
}
template<class T>
T Lista<T>::getElement(int pos){
    T dato;
    if(pos>=0 && pos<size){
        dato=listaDatos[pos];
    }
    return dato;
}