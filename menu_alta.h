#ifndef BETA_TP2_MENU_ALTA_H
#define BETA_TP2_MENU_ALTA_H
#include "menu_consulta.h"

class Menu_alta: Menu_consulta {

private:

    char opcion_ser{};
    char opcion_elemento{};
    Dato dato;

public:

    //PRE: recibe una lista y dos enteros
    //POS: imprime un menu por pantalla y se da alta a un objeto elegido por el ususario
    void menu_alta(Lista& list, int f, int c);

    //PRE: recibe una lista y dos enteros
    //POS: se muestra un menu, y el usuario elije un objeto
    void elegir_tipo_humano(Lista& list, int f, int c);

    //PRE: recibe una lista y dos enteros
    //POS: se muestra un menu, y el usuario elije un objeto
    void elegir_tipo_monstruo(Lista& list, int f, int c);

    //PRE: recibe una lista y dos enteros
    //POS: se muestra un menu, y el usuario elije un objeto
    void elegir_tipo_elemento(Lista& list, int f, int c);

    //PRE: recibe una lista
    //POS: el usuario elije una cantidad y se guarda ese valor
    void elegir_cantidad(Lista& list);

    //PRE: recibe una lista y dos enteros
    //POS: el usuario elige una posicion, se valida y se guarda la posicion ingresada
    void elegir_posicion(Lista& list, int fil, int col);

    //PRE: recibe dos enteros validos
    //POS: asigna un valor al atributo 'cuadrante' de un struct tipo 'Dato'
    void asignar_cuadrante(int fil, int col);

    //PRE: recibe una lista cargada
    //POS: se agrega un objeto a la lista
    void dar_alta_humano(Lista& list);

    //PRE: recibe una lista cargada
    //POS: se agrega un objeto a la lista
    void dar_alta_monstruo(Lista& list);

    //PRE: recibe una lista cargada
    //POS: se agrega un objeto a la lista
    void dar_alta_elemento(Lista& list);

    //PRE: recibe una lista cargada
    //POS: devuelve verdadero si la posicion es valida, falso de lo contrario
    bool validar_posicion(Lista& list) const;

};


#endif //BETA_TP2_MENU_ALTA_H
