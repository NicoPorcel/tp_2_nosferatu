#include "nosferatu.h"

#include <utility>

Nosferatu::Nosferatu(string nombre_objeto, string cuadrante) {
    nombre = std::move(nombre_objeto);
    pos_xy[X] = 0;
    pos_xy[Y] = 0;
    cardinal = std::move(cuadrante);
}

void Nosferatu::buscar_objeto(Lista& lista) {
    bool encontrado = false;
    unsigned i = 0;
    cout << endl << "─────────────| BUSQUEDA |───────────────────────────────────" << endl << endl;
    do{
        i++;
        if(lista.consultar(i).nombre == nombre && lista.consultar(i).cardinal == cardinal){
            encontrado = true;
            pos_xy[X] = lista.consultar(i).pos_xy[X];
            pos_xy[Y] = lista.consultar(i).pos_xy[Y];
            mostrar_objeto(nombre);
        }
    }while(i < lista.obtenerTam());
    if(encontrado) cout << "Se encontro a Nosferatu " << endl;
    else cout << "» No se encontro a Nosferatu en el cuadrante " << "'" << cardinal << "'" << endl << endl;
    cout << "────────────────────────────────────────────────────────────" << endl;
}