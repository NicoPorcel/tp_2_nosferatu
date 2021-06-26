#ifndef BETA_TP2_LISTA_H
#define BETA_TP2_LISTA_H
#include "nodo.h"

class Lista {
    //ATRIBUTOS
private:

    Nodo* primero;
    unsigned tam;

    //METODOS
public:
    //POS: construye una lista vacia
    Lista();

    //POS: devuelve verdadero si la lista es vacia, falso de lo contrario
    bool vacia();

    //PRE: 0 < pos <= tam + 1
    //POS: agrega un dato en la posicion pos
    void alta(Dato d, unsigned pos);

    //PRE: 0 < pos <= tam
    //POS: devuelve el dato
    Dato consultar(unsigned int pos);

    //PRE: 0 < pos <= tam
    //POS: borra el nodo en la posicion pos
    void baja(unsigned pos);

    //POS: libera todos los recursos de la lista
    ~Lista();

    //POS: devuelve el tamaño de la lista
    unsigned obtenerTam() const;

private:

    //PRE: 0 < pos <= tam
    //POS: devuelve un puntero al nodo
    Nodo* obtenerNodo(unsigned pos);
};


#endif //BETA_TP2_LISTA_H
