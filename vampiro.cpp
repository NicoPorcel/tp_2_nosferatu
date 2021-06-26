#include "vampiro.h"

Vampiro::Vampiro() = default;

Vampiro::Vampiro(string nombre_objeto, string cuadrante) {
    nombre = std::move(nombre_objeto);
    cardinal = std::move(cuadrante);
    pos_xy[X] = 0;
    pos_xy[Y] = 0;
}

void Vampiro::buscar_objeto(Lista& lista) {
    bool encontrado = false;
    unsigned i = 0;
    int cantidad = 0;
    string aux_nombre;
    cout << endl << "─────────────| BUSQUEDA |───────────────────────────────────" << endl << endl;
    do{
        i++;
        if((lista.consultar(i).nombre == nombre || lista.consultar(i).nombre == "Vampirella" || lista.consultar(i).nombre == "Nosferatu") && lista.consultar(i).cardinal == cardinal){
            encontrado = true;
            cantidad++;
            aux_nombre = lista.consultar(i).nombre;
            pos_xy[X] = lista.consultar(i).pos_xy[X];
            pos_xy[Y] = lista.consultar(i).pos_xy[Y];
            mostrar_objeto(aux_nombre);
        }
    }while(i < lista.obtenerTam());
    if(encontrado) cout << "Se encontro/encontraron " << cantidad << " vampiro/os" << endl;
    else cout << "» No se encontraron vampiros en el cuadrante " << "'" << cardinal << "'" << endl << endl;
    cout << "────────────────────────────────────────────────────────────" << endl;
}

void Vampiro::mostrar_objeto(const string& aux_nombre) {
    cout << "· Nombre: " << aux_nombre << endl;
    cout << "· Posicion: " << "(" << pos_xy[X] << ", " << pos_xy[Y] << ")" << endl;
    cout << "· Cuadrante: " << cardinal << endl << endl;
}