#ifndef BETA_TP2_CAZAVAMPIRO_H
#define BETA_TP2_CAZAVAMPIRO_H
#include "humano.h"

class Cazavampiro: Humano {

public:

    //PRE: recibe dos parametros de tipo string
    //POS: crea un objeto
    Cazavampiro(string nombre_objeto, string cuadrante);

    //PRE: recibe una lista cargada
    //POS: busca un objeto en la lista y lo muestra por pantalla en caso de encontrarlo
    // de lo contrario, muestra un mensaje informando que no se encontro
    void buscar_objeto(Lista& list) override;

};

#endif //BETA_TP2_CAZAVAMPIRO_H
