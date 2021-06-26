#ifndef BETA_TP2_TABLERO_H
#define BETA_TP2_TABLERO_H
#include "lista.h"

class Tablero {

private:

    int fila;
    int columna;
    Dato dato;
    char** matriz_c;
    float* contador;

public:

    //PRE: recibe dos enteros
    //POS: crea un objeto Tablero y se le da valor sus atributos
    Tablero(int f, int c);

    //POS: inicializa las pocisiones del tablero en 'vacio' con un '*'
    void iniciar_tablero();

    //PRE: recibe una lista cargada
    //POS: imprime el tablero
    void mostrar_tablero(Lista& lista);

    //PRE: recibe una lista cargada
    //POS: carga las pocisiones del tablero
    void cargar_tablero(Lista& lista);

    //POS: inicia el contador en '0'
    void iniciar_contador();

    //PRE: recibe una lista cargada
    //POS: imprime un cuadro resumen de datos
    void mostrar_cuadro(Lista& lista);

    //PRE: recibe una lista cargada
    //POS: se carga un vector contador
    void cargar_contador(Lista& lista);

    //POS: libera memoria utilizada
    ~Tablero();
};


#endif //BETA_TP2_TABLERO_H
