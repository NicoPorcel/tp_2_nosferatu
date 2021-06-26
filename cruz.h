#ifndef BETA_TP2_CRUZ_H
#define BETA_TP2_CRUZ_H
#include "elemento.h"

class Cruz: Elemento {

public:

    //PRE: recibe dos parametros de tipo string
    //POS: crea un objeto
    Cruz(string nombre_objeto, string cuadrante);

    //PRE: recibe una lista cargada
    //POS: busca un objeto en la lista y lo muestra por pantalla en caso de encontrarlo
    // de lo contrario, muestra un mensaje informando que no se encontro
    void buscar_objeto(Lista& lista) override;

};


#endif //BETA_TP2_CRUZ_H
