#ifndef BETA_TP2_MENU_BAJA_H
#define BETA_TP2_MENU_BAJA_H
#include "menu_consulta.h"

class Menu_baja: Menu_consulta {

private:

    char opcion_ser{};
    char opcion_elemento{};
    Dato dato;
    unsigned baja{};

public:

    //PRE: recibe una lista y dos enteros
    //POS: imprime un menu por pantalla y se da baja a un objeto elegido por el ususario
    void menu_baja(Lista& list, int f, int c);

    //PRE: recibe una lista y dos enteros
    //POS: se muestra un menu, y el usuario elije un objeto
    void elegir_tipo_humano(Lista& list, int f, int c);

    //PRE: recibe una lista y dos enteros
    //POS: se muestra un menu, y el usuario elije un objeto
    void elegir_tipo_monstruo(Lista& list, int f, int c);

    //PRE: recibe una lista y dos enteros
    //POS: se muestra un menu, y el usuario elije un objeto
    void elegir_tipo_elemento(Lista& list, int f, int c);

    //PRE: recibe una lista y dos enteros
    //POS: el usuario elige una posicion, se valida y se guarda la posicion ingresada
    void elegir_posicion(Lista& list, int fil, int col);

    //PRE: recibe una lista
    //POS: devuelve verdadero si la posicion es valida, falso de lo contrario
    bool validar_posicion(Lista& list);

};


#endif //BETA_TP2_MENU_BAJA_H
