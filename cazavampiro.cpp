#include "cazavampiro.h"

#include <utility>

Cazavampiro::Cazavampiro(string nombre_objeto, string cuadrante) {
    nombre = std::move(nombre_objeto);
    pos_xy[X] = 0;
    pos_xy[Y] = 0;
    cardinal = std::move(cuadrante);
}

void Cazavampiro::buscar_objeto(Lista& lista) {
    bool encontrado = false;
    unsigned i = 0;
    int cantidad = 0;
    string aux_nombre;
    cout << endl << "─────────────| BUSQUEDA |───────────────────────────────────" << endl << endl;
    do{
        i++;
        if((lista.consultar(i).nombre == nombre || lista.consultar(i).nombre == "Vanesa") && lista.consultar(i).cardinal == cardinal){
            encontrado = true;
            cantidad++;
            aux_nombre = lista.consultar(i).nombre;
            pos_xy[X] = lista.consultar(i).pos_xy[X];
            pos_xy[Y] = lista.consultar(i).pos_xy[Y];
            mostrar_objeto(aux_nombre);
        }
    }while(i < lista.obtenerTam());
    if(encontrado) cout << "Se encontro/encontraron " << cantidad << " Caza-vampiro/os" << endl;
    else cout << "» No se encontraron Caza-vampiros en el cuadrante " << "'" << cardinal << "'" << endl << endl;
    cout << "────────────────────────────────────────────────────────────" << endl;
}