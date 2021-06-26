#include "lista.h"

#include <utility>

Lista::Lista() {primero = nullptr; tam = 0;}

Lista::~Lista() {
    while(!(vacia())){
        baja(1);
    }
}

bool Lista::vacia() {
    return (primero == nullptr);
}

void Lista::alta(Dato d, unsigned int pos) {
    Nodo* nuevo = new Nodo{std::move(d)};
    if(pos == 1){
        nuevo->asignarSiguiente(primero);
        primero = nuevo;
    }else{
        Nodo* anterior = obtenerNodo(pos - 1);
        nuevo->asignarSiguiente(anterior->obtenerSiguiente());
        anterior->asignarSiguiente(nuevo);
    }
    tam++;
}

Dato Lista::consultar(unsigned int pos) {
    return (obtenerNodo(pos))->obtenerDato();
}

void Lista::baja(unsigned pos) {
    Nodo* borrar = primero;
    if(pos == 1){
        primero = borrar->obtenerSiguiente();
    }else{
        Nodo* anterior = obtenerNodo(pos - 1);
        borrar = anterior->obtenerSiguiente();
        anterior->asignarSiguiente(borrar->obtenerSiguiente());
    }
    delete borrar;
    tam--;
}

unsigned Lista::obtenerTam() const{
    return tam;
}

Nodo* Lista::obtenerNodo(unsigned int pos) {
    Nodo* aux = primero;
    unsigned i = 1;
    while(i < pos){
        aux = aux->obtenerSiguiente();
        i++;
    }
    return aux;
}