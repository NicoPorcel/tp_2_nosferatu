#include "arch_estado.h"

Arch_estado::Arch_estado() {
    fila = 0;
    columna = 0;
}

void Arch_estado::leer_archivo(Lista& lista) {
    string linea;
    char c;
    ifstream estado;
    estado.open("estado.txt");
    //estado.open("../estado.txt");
    if(!estado.is_open())  cout << "Error de apertura de archivo" << endl;
    else{
        estado >> fila >> columna;
        while(!estado.eof()){
            estado >> dato.nombre;
            if (dato.nombre == "agua" || dato.nombre == "bala") {
                estado >> dato.cantidad;
            }else{
                dato.cantidad = 1;
            }
            getline(estado, linea, '(');
            if (linea == " CV ") {
                dato.nombre += " CV";
            }
            estado >> dato.pos_xy[X] >> c >> dato.pos_xy[Y] >> linea;
            ubicar_en_mapa();
            asignar_simbolo();
            lista.alta(dato, 1);
        }
    }
    estado.close();
}

void Arch_estado::ubicar_en_mapa() {
    if(dato.pos_xy[X] <= (columna/2) && dato.pos_xy[Y] <= (fila/2))
        dato.cardinal = "NO";
    else if (dato.pos_xy[X] > (columna / 2) && dato.pos_xy[Y] <= (fila / 2))
        dato.cardinal = "NE";
    else if (dato.pos_xy[X] <= (columna / 2) && dato.pos_xy[Y] > (fila / 2))
        dato.cardinal = "SO";
    else dato.cardinal = "SE";
}

void Arch_estado::asignar_simbolo() {
    if (dato.nombre == "humano") { dato.simbolo = 'h'; }
    else if (dato.nombre == "humano CV") { dato.simbolo = 'H'; }
    else if (dato.nombre == "Vanesa") { dato.simbolo = 'W'; }
    else if (dato.nombre == "zombi") { dato.simbolo = 'z'; }
    else if (dato.nombre == "vampiro") { dato.simbolo = 'v'; }
    else if (dato.nombre == "Nosferatu") { dato.simbolo = 'N'; }
    else if (dato.nombre == "Vampirella") { dato.simbolo = 'V'; }
    else if (dato.nombre == "agua") { dato.simbolo = 'a'; }
    else if (dato.nombre == "cruz") { dato.simbolo = 'c'; }
    else if (dato.nombre == "estaca") { dato.simbolo = 'e'; }
    else if (dato.nombre == "escopeta") { dato.simbolo = 'E'; }
    else dato.simbolo = 'b';
}

int Arch_estado::obtener_fila() const {
    return fila;
}

int Arch_estado::obtener_columna() const {
    return columna;
}