#ifndef BETA_TP2_MENU_CONSULTA_H
#define BETA_TP2_MENU_CONSULTA_H
#include "utiles.h"
#include "lista.h"
#include "seres_elementos.h"

class Menu_consulta {

private:

    char opcion_cuadrante{};
    string cuadrante_elegido;

protected:

    char opcion_objeto{};

public:

    //PRE: recibe una lista cargada
    //POS: se informa al usuario si se encontro un objeto elegido por el
    void menu_consulta(Lista& list);

    //PRE: recibe una lista cargada
    //POS: procesa la opcion ingresada por el usuario
    void procesar_opcion(Lista& list);

    //PRE: recibe una lista cargada
    //POS: se le pide elegir un objeto al usuario
    void procesar_opcion_humano(Lista& list);

    //PRE: recibe una lista cargada
    //POS: se le pide elegir un objeto al usuario
    void procesar_opcion_vampiro(Lista& list);

    //POS: se da valor al cuadrante elegido por el usuario
    void elegir_cuadrante();

    //PRE: recibe 3 parametros de tipo char
    //POS: se valida una opcion ingresada por el usuario
    static void validar_opcion(char& eleccion, char min, char max);

};


#endif //BETA_TP2_MENU_CONSULTA_H
