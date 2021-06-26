#include "elemento.h"

Elemento::Elemento() = default;

void Elemento::mostrar_objeto() {
    cout << "· Nombre: " << nombre << endl;
    cout << "· Cantidad:" << cantidad << endl;
    cout << "· Posicion: " << "(" << pos_xy[X] << ", " << pos_xy[Y] << ")" << endl;
    cout << "· Cuadrante: " << cardinal << endl << endl;
}

