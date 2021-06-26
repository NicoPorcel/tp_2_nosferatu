#ifndef BETA_TP2_ELEMENTO_H
#define BETA_TP2_ELEMENTO_H
#include "objeto.h"

class Elemento: Objeto {

protected:

    string nombre;
    vec_coord pos_xy{};
    string cardinal;
    float cantidad{};

public:

    //constructor sin parametros
    Elemento();

    //POS: mustra por pantalla los datos del objeto
    void mostrar_objeto();
};


#endif //BETA_TP2_ELEMENTO_H
