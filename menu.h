#ifndef BETA_TP2_MENU_H
#define BETA_TP2_MENU_H
#include "tablero.h"
#include "menu_consulta.h"
#include "menu_alta.h"
#include "menu_baja.h"

class Menu {

private:

    char opcion{};
    int fila;
    int columna;
    Menu_consulta consulta;
    Menu_alta alta;
    Menu_baja baja;

public:

    //PRE: recibe dos enteros
    //POS: crea un objeto de clase Menu y se iniccializa sus atributos
    Menu(int fil, int col);

    static void titulo();

    //PRE: recibe una lista cargada
    //POS: imprime un menu con opciones
    // y llama a funciones que realizen lo que el usuario elija
    void mostrar_menu(Lista& list_dato);

    //PRE: recibe 2 parametros de tipo char
    //POS: se valida una opcion ingresada por el usuario
    void validar_opcion(char min, char max);

    //PRE: recibe una lista cargada, y un objeto Tablero
    //POS: llama a una funcion que realice lo que quiere el usuario
    void procesar_opcion(Lista& list_dato, Tablero &mapa);

    //PRE: recibe una lista cargada
    //POS: imprime los datos de la lista
    static void mostrar_lista_de_datos(Lista& list);

    //POS: imprime informacion por pantalla
    static void mostrar_creditos();

};


#endif //BETA_TP2_MENU_H
