class calificacion {
    public:
    double calculaCalif();
    void imprime();
    void setCalAct(double act) {calAct = act;};
    void setCalProy(double proy) { calProy = proy;};
    void setCalEx(double ex) {calEx = ex;};
    void setName(string nom) { nombre = nom;};
    string getName(){return nombre;};
    double getCalAct(){return calAct;};
    double getCalProy(){return calProy;};
    double getCalEx(){return calEx;};
    private:
    string nombre;
    double calAct;
    double calProy;
    double calEx;
};

double calificacion::calculaCalif () {
    return calAct * 0.3 + calProy * 0.4 + calEx * 0.3;
}

void calificacion::imprime() {
    cout << nombre << " " << calAct << " " << calProy << " " << calEx << " " << calculaCalif() << endl;
}