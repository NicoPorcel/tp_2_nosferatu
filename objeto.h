#ifndef BETA_TP2_OBJETO_H
#define BETA_TP2_OBJETO_H
#include "lista.h"

class Objeto {

private:

    Dato dato;

    //METODOS
public:

    //Constructor sin parametros
    Objeto();

    //PRE: recibe una lista cargada
    //POS: busca un objeto en la lista y lo muestra por pantalla en caso de encontrarlo
    // de lo contrario, muestra un mensaje informando que no se encontro
    virtual void buscar_objeto(Lista& lista);

    //PRE: recibe un string
    //POS: imprime los atributos del objeto
    virtual void mostrar_objeto(const string& aux_nombre);

    //PRE: recibe una lista cargada y un struct tipo 'Dato'
    //POS: se agrega un nuevo objeto a la lista
    static void agregar_objeto(Lista& list, Dato dato);

    //PRE: recibe una lista cargada y una 'posicion'
    //POS: se elimina un objeto de la lista
    static void eliminar_objeto(Lista& list, unsigned i);
};


#endif //BETA_TP2_OBJETO_H
