#ifndef BETA_TP2_VAMPIRO_H
#define BETA_TP2_VAMPIRO_H
#include "monstruo.h"

class Vampiro: Monstruo {

protected:

    string nombre;
    vec_coord pos_xy{};
    string cardinal;

public:

    //constructor sin parametros
    //POS: crea un objeto
    Vampiro();

    //PRE: recibe dos parametros tipo string
    //POS: crea un objeto
    Vampiro(string nombre_objeto, string cuadrante);

    //PRE: recibe una lista cargada
    //POS: busca un objeto en la lista y lo muestra por pantalla en caso de encontrarlo
    // de lo contrario, muestra un mensaje informando que no se encontro
    void buscar_objeto(Lista& lista) override;

    void mostrar_objeto(const string& aux_nombre) override;
};


#endif //BETA_TP2_VAMPIRO_H
