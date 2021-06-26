#ifndef BETA_TP2_AGUA_BENDITA_H
#define BETA_TP2_AGUA_BENDITA_H
#include "elemento.h"

class Agua_bendita: Elemento {

public:

    //Constructor
    //PRE: recibe dos parametros de tipo string
    //POS: crea un objeto
    Agua_bendita(string nombre_objeto, string cuadrante);

    //PRE: recibe una lista cargada
    //POS: busca un objeto en la lista y lo muestra por pantalla en caso de encontrarlo
    // de lo contrario, muestra un mensaje informando que no se encontro
    void buscar_objeto(Lista& lista) override;
};


#endif //BETA_TP2_AGUA_BENDITA_H
