#include "objeto.h"

Objeto::Objeto() = default;

void Objeto::buscar_objeto(Lista &lista) {}

void Objeto::mostrar_objeto(const string& aux_nombre) {}

void Objeto::agregar_objeto(Lista& list, Dato dato) {
    list.alta(dato, 1);
}

void Objeto::eliminar_objeto(Lista& list, unsigned i) {
    list.baja(i);
}