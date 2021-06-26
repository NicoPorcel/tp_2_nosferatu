#include "menu_baja.h"

void Menu_baja::menu_baja(Lista& list, int f, int c) {
    char pausa;
    opcion_objeto = '0';
    cout << "────────────────────────────────────────────────────────────";
    cout << "\n                        ──| MENU ALTA |──" << endl;
    cout << "────────────────────────────────────────────────────────────";
    cout << "\n Seleccione el tipo de objeto a agregar con un numero: " << endl;
    cout << "────────────────────────────────────────────────────────────";
    cout << "\n  »  1 · HUMANO" << endl << "  »  2 · MONSTRUO" << endl << "  »  3 · ELEMENTO" << endl;
    cout << "────────────────────────────────────────────────────────────";
    cout << "\n---→ ";
    cin >> opcion_objeto;
    validar_opcion(opcion_objeto, '1', '3');
    if(opcion_objeto == '1') elegir_tipo_humano(list, f, c);
    else if(opcion_objeto == '2') elegir_tipo_monstruo(list, f, c);
    else elegir_tipo_elemento(list, f, c);
    cout << endl << "────────────| ESTADO |──────────────────────────────────────" << endl;
    cout << endl << "El objeto se elimino correctamente..." << endl;
    cout << endl << "────────────────────────────────────────────────────────────" << endl;
    cout << "ingrese una letra o numero y luego presione enter... ";
    cin >> pausa;
}

void Menu_baja::elegir_tipo_humano(Lista& list, int f, int c) {
    opcion_ser = '0';
    cout << "────────────────────────────────────────────────────────────";
    cout << "\n Seleccione el objeto con un numero: " << endl;
    cout << "────────────────────────────────────────────────────────────";
    cout << "\n  »  1 · Humano" << endl << "  »  2 · Vanesa" << endl;
    cout << "  »  3 · Caza-vampiro" << endl;
    cout << "────────────────────────────────────────────────────────────";
    cout << "\n---→ ";
    cin >> opcion_ser;
    validar_opcion(opcion_ser, '1', '3');
    if(opcion_ser == '1') dato.nombre = "humano";
    else if(opcion_ser == '2') dato.nombre = "Vanesa";
    else dato.nombre = "humano CV";
    elegir_posicion(list, f, c);
    Objeto::eliminar_objeto(list, baja);
}

void Menu_baja::elegir_tipo_monstruo(Lista &list, int f, int c) {
    opcion_ser = '0';
    cout << "────────────────────────────────────────────────────────────";
    cout << "\n Seleccione el objeto con un numero: " << endl;
    cout << "────────────────────────────────────────────────────────────";
    cout << "\n  »  1 · Vampiro" << endl << "  »  2 · Vampirella" << endl;
    cout << "  »  3 · Nosferatu" << endl << "  »  4 · Zombi" << endl;
    cout << "────────────────────────────────────────────────────────────";
    cout << "\n---→ ";
    cin >> opcion_ser;
    validar_opcion(opcion_ser, '1', '4');
    if(opcion_ser == '1') dato.nombre = "vampiro";
    else if(opcion_ser == '2') dato.nombre = "Vampirella";
    else if(opcion_ser == '3') dato.nombre = "Nosferatu";
    else dato.nombre = "zombi";
    elegir_posicion(list, f, c);
    Objeto::eliminar_objeto(list, baja);
}

void Menu_baja::elegir_tipo_elemento(Lista& list, int f, int c) {
    opcion_elemento = '0';
    cout << "────────────────────────────────────────────────────────────";
    cout << "\n Seleccione el elemento con un numero: " << endl;
    cout << "────────────────────────────────────────────────────────────";
    cout << "\n  »  1 · Agua bendita" << endl << "  »  2 · Cruz";
    cout << "\n  »  3 · Estaca" << endl << "  »  4 · Escopeta";
    cout << "\n  »  5 · Bala" << endl;
    cout << "────────────────────────────────────────────────────────────";
    cout << "\n---→ ";
    cin >> opcion_elemento;
    validar_opcion(opcion_elemento, '1', '5');
    if(opcion_elemento == '1') dato.nombre = "agua";
    else if(opcion_elemento == '2') dato.nombre = "cruz";
    else if(opcion_elemento == '3') dato.nombre = "estaca";
    else if(opcion_elemento == '4') dato.nombre = "escopeta";
    else dato.nombre = "bala";
    elegir_posicion(list, f, c);
    Objeto::eliminar_objeto(list, baja);
}

void Menu_baja::elegir_posicion(Lista& list, int fil, int col) {
    bool valido = true;
    do{
        if(!valido)
            cout << endl << "Error, no se encuentra el objeto en la posicion ingresada" << endl;
        cout << endl << "» Ingrese posicion en 'x' : ";
        cin >> dato.pos_xy[X];
        cout << "» Ingrese posicion en 'y' : ";
        cin >> dato.pos_xy[Y];
        if(dato.pos_xy[X] <= col && dato.pos_xy[Y] <= fil && dato.pos_xy[X] >= 0 && dato.pos_xy[Y] >= 0)
            valido = validar_posicion(list);
        else valido = false;
    }while(!valido);
}

bool Menu_baja::validar_posicion(Lista &list) {
    unsigned i = 1;
    bool encontrado = false;
    while(i <= list.obtenerTam() && !encontrado){
        if(list.consultar(i).nombre == dato.nombre && list.consultar(i).pos_xy[X] == dato.pos_xy[X] && list.consultar(i).pos_xy[Y] == dato.pos_xy[Y])
            encontrado = true;
        i++;
    }
    baja = i - 1;
    return encontrado;
}