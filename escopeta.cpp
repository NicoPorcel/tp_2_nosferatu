#include "escopeta.h"

Escopeta::Escopeta(string nombre_objeto, string cuadrante) {
    nombre = std::move(nombre_objeto);
    pos_xy[X] = 0;
    pos_xy[Y] = 0;
    cardinal = std::move(cuadrante);
    cantidad = 1;
}

void Escopeta::buscar_objeto(Lista& lista) {
    bool encontrado = false;
    unsigned i = 0;
    float total = 0;
    cout << endl << "─────────────| BUSQUEDA |───────────────────────────────────" << endl << endl;
    do{
        i++;
        if(lista.consultar(i).nombre == nombre && lista.consultar(i).cardinal == cardinal){
            encontrado = true;
            total ++;
            pos_xy[X] = lista.consultar(i).pos_xy[X];
            pos_xy[Y] = lista.consultar(i).pos_xy[Y];
            mostrar_objeto();
        }
    }while(i < lista.obtenerTam());
    if(encontrado) cout << "Se encontro/encontraron " << total <<  " Escopeta/as" << endl;
    else cout << "» No se encontro ninguna Escopeta en el cuadrante " << "'" << cardinal << "'" << endl << endl;
    cout << "────────────────────────────────────────────────────────────" << endl;
}