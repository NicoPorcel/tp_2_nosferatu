#include "nodo.h"
#include <utility>

Nodo::Nodo(Dato d) {
    dato = std::move(d);
    P_sig = nullptr;
}

Dato Nodo::obtenerDato() {
    return dato;
}

void Nodo::asignarSiguiente(Nodo *ps) {
    P_sig = ps;
}

Nodo * Nodo::obtenerSiguiente() {
    return P_sig;
}