#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cctype>
#include <limits>
#include "GrafoM1.h"

using namespace std;

// Quita espacios al inicio/fin
string trim(const string &s){
    int i = 0, j = (int)s.size() - 1;
    while(i <= j && isspace((unsigned char)s[i])) i++;
    while(j >= i && isspace((unsigned char)s[j])) j--;
    return (i <= j) ? s.substr(i, j - i + 1) : "";
}

// Quita comillas si existen
string stripQuotes(string s){
    s = trim(s);
    if(s.size() >= 2 && s.front()=='"' && s.back()=='"'){
        s = s.substr(1, s.size()-2);
    }
    return s;
}

// Convierte "H:MM" a minutos
int timeToMinutes(string t){
    t = trim(t);
    if(t.empty()) return -1;
    if(!t.empty() && t.back()=='\r') t.pop_back();

    size_t pos = t.find(':');
    if(pos == string::npos) return -1;

    string hStr = t.substr(0, pos);
    string mStr = t.substr(pos + 1);

    try{
        int h = stoi(hStr);
        int m = stoi(mStr);
        if(m < 0 || m >= 60 || h < 0) return -1;
        return h * 60 + m;
    }catch(...){
        return -1;
    }
}

// Convierte minutos a "HH:MM"
string minutesToHHMM(int mins){
    int h = mins / 60;
    int m = mins % 60;
    string hh = (h < 10 ? "0" : "") + to_string(h);
    string mm = (m < 10 ? "0" : "") + to_string(m);
    return hh + ":" + mm;
}

// Cargar TODO el CSV a 4 grafos
void cargarTodoDesdeCSV(
    GrafoM<string> &trenDist,
    GrafoM<string> &trenTime,
    GrafoM<string> &carDist,
    GrafoM<string> &carTime,
    const string &nombreArchivo
){
    ifstream archivo(nombreArchivo);

    if(!archivo.is_open()){
        cerr << "ERROR: No se pudo abrir el archivo: " << nombreArchivo << endl;
        return;
    }

    string linea;
    getline(archivo, linea); // header

    while(getline(archivo, linea)){
        if(trim(linea).empty()) continue;

        stringstream ss(linea);
        string origen, destino, timeTrenStr, distTrenStr, timeCarStr, distCarStr;

        getline(ss, origen, ',');
        getline(ss, destino, ',');
        getline(ss, timeTrenStr, ',');
        getline(ss, distTrenStr, ',');
        getline(ss, timeCarStr, ',');
        getline(ss, distCarStr, ',');

        origen = stripQuotes(origen);
        destino = stripQuotes(destino);

        timeTrenStr = trim(timeTrenStr);
        distTrenStr = trim(distTrenStr);
        timeCarStr  = trim(timeCarStr);
        distCarStr  = trim(distCarStr);

        if(origen.empty() || destino.empty()) continue;

        if(!distTrenStr.empty() && distTrenStr.back()=='\r') distTrenStr.pop_back();
        if(!distCarStr.empty()  && distCarStr.back()=='\r')  distCarStr.pop_back();

        trenDist.addVertex(origen); trenDist.addVertex(destino);
        trenTime.addVertex(origen); trenTime.addVertex(destino);
        carDist.addVertex(origen);  carDist.addVertex(destino);
        carTime.addVertex(origen);  carTime.addVertex(destino);

        try{
            if(!distTrenStr.empty()){
                int dTren = stoi(distTrenStr);
                trenDist.addEdge(origen, destino, dTren);
            }
        }catch(...){}

        int tTrenMin = timeToMinutes(timeTrenStr);
        if(tTrenMin != -1){
            trenTime.addEdge(origen, destino, tTrenMin);
        }

        try{
            if(!distCarStr.empty()){
                int dCar = stoi(distCarStr);
                carDist.addEdge(origen, destino, dCar);
            }
        }catch(...){}

        int tCarMin = timeToMinutes(timeCarStr);
        if(tCarMin != -1){
            carTime.addEdge(origen, destino, tCarMin);
        }
    }
    archivo.close();
}

int main(){

    GrafoM<string> trenDist, trenTime, carDist, carTime;

    string archivo;

cout << "Ingresa el nombre o ruta del archivo CSV: ";
getline(cin, archivo);

cargarTodoDesdeCSV(
    trenDist, trenTime, carDist, carTime,
    archivo
);


    bool seguir = true;
    while(seguir){

        string ida, regreso;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "\nCiudad de inicio: ";
        getline(cin, ida);

        cout << "Ciudad de destino: ";
        getline(cin, regreso);

        ida = stripQuotes(ida);
        regreso = stripQuotes(regreso);

        // Arreglos para rutas
        string rTD[100], rTT[100], rCD[100], rCT[100];
        int nTD, nTT, nCD, nCT;
        int tTD, tTT, tCD, tCT;

        bool okTD = trenDist.dijkstraPath(ida, regreso, tTD, rTD, nTD);
        bool okTT = trenTime.dijkstraPath(ida, regreso, tTT, rTT, nTT);
        bool okCD = carDist.dijkstraPath(ida, regreso, tCD, rCD, nCD);
        bool okCT = carTime.dijkstraPath(ida, regreso, tCT, rCT, nCT);

        cout << "\n=================================\n";

        // ---- Tren distancia ----
        cout << "Distancia mas corta en tren\n";
        if(okTD){
            cout << "Mejor ruta: ";
            for(int i=0;i<nTD;i++){
                cout << rTD[i];
                if(i<nTD-1) cout << " --> ";
            }
            cout << "\nDistancia total = " << tTD << " unidades\n\n";
        } else {
            cout << "No hay ruta en tren (distancia)\n\n";
        }

        // ---- Tren tiempo ----
        cout << "Tiempo mas corto en tren\n";
        if(okTT){
            cout << "Mejor ruta: ";
            for(int i=0;i<nTT;i++){
                cout << rTT[i];
                if(i<nTT-1) cout << " --> ";
            }
            cout << "\nTiempo total = " << minutesToHHMM(tTT) << " minutos\n\n";
        } else {
            cout << "No hay ruta en tren (tiempo)\n\n";
        }

        // ---- Carro distancia ----
        cout << "Distancia mas corta en carro\n";
        if(okCD){
            cout << "Mejor ruta: ";
            for(int i=0;i<nCD;i++){
                cout << rCD[i];
                if(i<nCD-1) cout << " --> ";
            }
            cout << "\nDistancia total = " << tCD << " unidades\n\n";
        } else {
            cout << "No hay ruta en carro (distancia)\n\n";
        }

        // ---- Carro tiempo ----
        cout << "Tiempo mas corto en carro\n";
        if(okCT){
            cout << "Mejor ruta: ";
            for(int i=0;i<nCT;i++){
                cout << rCT[i];
                if(i<nCT-1) cout << " --> ";
            }
            cout << "\nTiempo total = " << minutesToHHMM(tCT) << " minutos\n\n";
        } else {
            cout << "No hay ruta en carro (tiempo)\n\n";
        }

        // ===== COMPARACION FINAL =====
        cout << "----- Comparacion final -----\n";

        if(okTD && okCD){
            if(tTD < tCD) cout << "Mejor opcion por DISTANCIA: TREN\n";
            else if(tCD < tTD) cout << "Mejor opcion por DISTANCIA: CARRO\n";
            else cout << "Mejor opcion por DISTANCIA: EMPATE\n";
        } else {
            cout << "No se puede comparar distancia (falta alguna ruta).\n";
        }

        if(okTT && okCT){
            if(tTT < tCT) cout << "Mejor opcion por TIEMPO: TREN\n";
            else if(tCT < tTT) cout << "Mejor opcion por TIEMPO: CARRO\n";
            else cout << "Mejor opcion por TIEMPO: EMPATE\n";
        } else {
            cout << "No se puede comparar tiempo (falta alguna ruta).\n";
        }

        cout << "=================================\n";

        string op;
        cout << "Deseas hacer otra consulta? (si/no): ";
        cin >> op;

        if(!(op=="si" || op=="SI" || op=="Si"))
            seguir = false;
    }

    return 0;
}