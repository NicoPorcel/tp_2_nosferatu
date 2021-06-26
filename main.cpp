#include "menu.h"
#include "arch_estado.h"

int main() {
    Arch_estado estado;
    int fila, columna;
    Lista lista_objetos;

    estado.leer_archivo(lista_objetos);
    fila = estado.obtener_fila();
    columna = estado.obtener_columna();

    Menu juego(fila, columna);
    juego.mostrar_menu(lista_objetos);

    return 0;
}