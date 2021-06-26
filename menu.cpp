#include "menu.h"

Menu::Menu(int fil, int col) {
    fila = fil;
    columna = col;
}

void Menu::mostrar_menu(Lista& list_dato) {
    if(!list_dato.vacia()){
        titulo();
        Tablero mapa(fila, columna);
        do{
            cout << "\n────────────────────────────────────────────────────────────";
            cout << "\n                   ──| MENU PRINCIPAL |──" << endl;
            cout << "────────────────────────────────────────────────────────────";
            cout << "\n Seleccione la opcion deseada con un numero: " << endl;
            cout << "────────────────────────────────────────────────────────────";
            cout << "\n  »  1 · VER CUADRO RESUMEN." << endl << "\n  »  2 · VER TABLERO." << endl;
            cout << "\n  »  3 · CONSULTAR OBJETO." << endl << "\n  »  4 · AGREGAR OBJETO." << endl;
            cout << "\n  »  5 · QUITAR OBJETO." << endl << "\n  »  6 · VER DATOS." << endl;
            cout << "\n  »  7 · SALIR." << endl;
            cout << "────────────────────────────────────────────────────────────";
            cout << "\n---→ ";
            cin >> opcion;
            validar_opcion('1', '7');
            procesar_opcion(list_dato, mapa);
        }while(opcion != '7');
        mostrar_creditos();
        cout << "\n─────────────| Gracias por probar este juego |──────────────" << endl;
    }
}

void Menu::validar_opcion(char min, char max) {
    while(opcion < min || opcion > max){
        cout <<"\n  -- Error, opcion invalida, ingrese un numero valido --" << endl;
        cout << "--→ Indique opcion (numerica) : ";
        cin >> opcion;
    }
}

void Menu::procesar_opcion(Lista &list_dato, Tablero &mapa) {
    if(opcion == '1') mapa.mostrar_cuadro(list_dato);
    else if(opcion == '2') mapa.mostrar_tablero(list_dato);
    else if(opcion == '3') consulta.menu_consulta(list_dato);
    else if(opcion == '4') alta.menu_alta(list_dato, fila, columna);
    else if(opcion == '5') baja.menu_baja(list_dato, fila, columna);
    else if(opcion == '6') mostrar_lista_de_datos(list_dato);
}

void Menu::mostrar_lista_de_datos(Lista& list) {
    char pausa;
    unsigned i = 1;
    cout << "─────────────────────────── · DATOS DE JUEGO · ─────────────" << endl;
    while(i <= list.obtenerTam()){
        cout << "» Nombre: " << list.consultar(i).nombre << endl;
        cout << fixed << setprecision(1) << "» Cantidad: " << list.consultar(i).cantidad << endl;
        cout << "» Posicion: " << list.consultar(i).pos_xy[X] << ", ";
        cout << list.consultar(i).pos_xy[Y] << endl;
        cout << "» Cuadrante: " << list.consultar(i).cardinal << endl << endl;
        i++;
    }
    cout << "────────────────────────────────────────────────────────────" << endl;
    cout << endl << "ingrese una letra o numero y presione enter... ";
    cin >> pausa;
}

void Menu::titulo() {
    cout << "────────────────────────────────────────────────────────────" << endl;
    cout << "||\\  ||  ____  ____   ____   ____  ____     _  ______  _  _   " << endl;
    cout << R"(|| \ || ||  || \___  ||___  ||___ ||___|  //_\   ||   ||  ||)" << endl;
    cout << R"(||  \|| ||__|| ___|| ||     ||___ ||  \  //   \  ||   ||__||)";
}

void Menu::mostrar_creditos(){
    cout <<   "   ────────── · CREDITOS · ──────────────────────────────" << endl;
    cout <<   "                  Titulo.....NOSFERATUM" << endl;
    cout << "\n                    Genero     Arcade" << endl;
    cout << "\n              Clasificacion     PG/(+8 años)" << endl;
    cout << "\n                  Creador........FIUBA" << endl;
    cout << "\n           Desarrollador........Nicolas Porcel" << endl;
    cout <<   "   ──────────────────────────────────────────────────────" << endl;
}