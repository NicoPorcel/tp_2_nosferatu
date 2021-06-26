#ifndef BETA_TP2_UTILES_H
#define BETA_TP2_UTILES_H

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

const int TIPOS = 8;
const int X = 0; const int Y = 1;
const int X_Y = 2;

const int HUMANO = 0; const int ZOMBI = 1; const int VAMPIRO = 2; const int AGUA = 3;
const int CRUZ = 4; const int ESTACA = 5; const int ESCOPETA = 6; const int BALA = 7;

typedef int vec_coord[X_Y];

struct Dato{
    string nombre;
    vec_coord pos_xy;
    float cantidad;
    string cardinal;
    char simbolo;
};

#endif //BETA_TP2_UTILES_H