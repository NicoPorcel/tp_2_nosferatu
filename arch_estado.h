#ifndef BETA_TP2_ARCH_ESTADO_H
#define BETA_TP2_ARCH_ESTADO_H
#include "lista.h"

class Arch_estado {

private:

    Dato dato;
    int fila{};
    int columna{};

public:

    //Constructor sin parametros
    //POS: inicializa los atributos en '0'
    Arch_estado();

    //PRE: recibe una lista vacia
    //POS: carga la lista con datos leidos de un archivo
    void leer_archivo(Lista& lista);

    //PRE: se lee un archivo previamente
    //POS: asigna un cuadrante a cada objeto segun su posicion
    void ubicar_en_mapa();

    //PRE: se lee un archivo previamente
    //POS: asigna un simbolo a cada objeto
    void asignar_simbolo();

    //PRE: se lee un archivo previamente
    //POS: retorna la cantidad de filas
    int obtener_fila() const;

    //PRE: se lee un archivo previamente
    //POS: retorna la cantidad de columnas
    int obtener_columna() const;

};


#endif //BETA_TP2_ARCH_ESTADO_H
