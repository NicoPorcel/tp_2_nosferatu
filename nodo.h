#ifndef BETA_TP2_NODO_H
#define BETA_TP2_NODO_H
#include "utiles.h"

class Nodo {

    //ATRIBUTOS
private:

    Dato dato;
    Nodo* P_sig;

    //METODOS
public:

    //POS: crea un Nodo con el dato 'd' y el puntero a null
    explicit Nodo(Dato d);

    //POS: devuelve el dato que contiene el nodo
    Dato obtenerDato();

    //POS: el puntero al siguiente nodo apuntara a ps
    void asignarSiguiente(Nodo* ps);

    //POS: devuelve el puntero al siguiente nodo
    Nodo* obtenerSiguiente();

};


#endif //BETA_TP2_NODO_H
