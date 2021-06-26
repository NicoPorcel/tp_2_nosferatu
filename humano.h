#ifndef BETA_TP2_HUMANO_H
#define BETA_TP2_HUMANO_H
#include "ser.h"

class Humano: Ser {

protected:

    string nombre;
    vec_coord pos_xy{};
    string cardinal;

public:

    //constructor sin parametros
    //POS: crea un objeto
    Humano();

    //PRE: recibe dos parametros tipo string
    //POS: crea un objeto
    Humano(string nombre_objeto, string cuadrante);

    //PRE: recibe una lista cargada
    //POS: busca un objeto en la lista y lo muestra por pantalla en caso de encontrarlo
    // de lo contrario, muestra un mensaje informando que no se encontro
    void buscar_objeto(Lista& lista) override;

    //PRE: recibe un parametro de tipo string
    //POS: mustra por pantalla los datos del objeto
    void mostrar_objeto(const string& aux_nombre) override;
};


#endif //BETA_TP2_HUMANO_H
