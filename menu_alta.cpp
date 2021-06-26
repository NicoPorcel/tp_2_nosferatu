#include "menu_alta.h"

void Menu_alta::menu_alta(Lista& list, int f, int c) {
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
    cout << endl << "El objeto se agrego correctamente..." << endl;
    cout << endl << "────────────────────────────────────────────────────────────" << endl;
    cout << "ingrese una letra o numero y luego presione enter... ";
    cin >> pausa;
}

void Menu_alta::dar_alta_humano(Lista &list) {
    if(opcion_ser == '1'){ dato.nombre = "humano"; dato.simbolo = 'h'; }
    else if(opcion_ser == '2'){ dato.nombre = "Vanesa"; dato.simbolo = 'W'; }
    else{ dato.nombre = "humano CV"; dato.simbolo = 'H'; }
    Objeto::agregar_objeto(list, dato);
}

void Menu_alta::dar_alta_monstruo(Lista &list) {
    if(opcion_ser == '1'){ dato.nombre = "vampiro"; dato.simbolo = 'v'; }
    else if(opcion_ser == '2'){ dato.nombre = "Vampirella"; dato.simbolo = 'V'; }
    else if(opcion_ser == '3'){ dato.nombre = "Nosferatu"; dato.simbolo = 'N'; }
    else{ dato.nombre = "zombi"; dato.simbolo = 'z'; }
    Objeto::agregar_objeto(list, dato);
}

void Menu_alta::dar_alta_elemento(Lista &list) {
    if(opcion_elemento == '1'){ dato.nombre = "agua"; dato.simbolo = 'a'; }
    else if(opcion_elemento == '2'){ dato.nombre = "cruz"; dato.simbolo = 'c'; }
    else if(opcion_elemento == '3'){ dato.nombre = "estaca"; dato.simbolo = 'e'; }
    else if(opcion_elemento == '4'){ dato.nombre = "escopeta"; dato.simbolo = 'E'; }
    else{ dato.nombre = "bala"; dato.simbolo = 'b'; }
    Objeto::agregar_objeto(list, dato);
}

void Menu_alta::elegir_tipo_humano(Lista& list, int f, int c) {
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
    elegir_posicion(list, f, c);
    dato.cantidad = 1;
    dar_alta_humano(list);
}

void Menu_alta::elegir_tipo_monstruo(Lista &list, int f, int c) {
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
    elegir_posicion(list, f, c);
    dato.cantidad = 1;
    dar_alta_monstruo(list);
}

void Menu_alta::elegir_tipo_elemento(Lista& list, int f, int c) {
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
    if(opcion_elemento == '1' || opcion_elemento == '5')
        elegir_cantidad(list);
    elegir_posicion(list, f, c);
    dar_alta_elemento(list);
}

void Menu_alta::elegir_cantidad(Lista &list) {
    cout << endl << "» Ingrese la cantidad: ";
    cin >> dato.cantidad;
}

void Menu_alta::elegir_posicion(Lista& list, int fil, int col) {
    bool valido = true;
    do{
        if(!valido)
            cout << endl << "Error, no se puede ubicar el objeto en la posicion ingresada" << endl;
        cout << endl << "» Ingrese posicion en 'x' : ";
        cin >> dato.pos_xy[X];
        cout << "» Ingrese posicion en 'y' : ";
        cin >> dato.pos_xy[Y];
        if(dato.pos_xy[X] <= col && dato.pos_xy[Y] <= fil && dato.pos_xy[X] >= 0 && dato.pos_xy[Y] >= 0)
            valido = validar_posicion(list);
        else valido = false;
    }while(!valido);
    asignar_cuadrante(fil, col);
}

bool Menu_alta::validar_posicion(Lista &list) const {
    unsigned i = 1;
    bool valido = true;
    while(i <= list.obtenerTam() && valido){
        if(list.consultar(i).pos_xy[X] == dato.pos_xy[X] && list.consultar(i).pos_xy[Y] == dato.pos_xy[Y])
            valido = false;
        i++;
    }
    return valido;
}

void Menu_alta::asignar_cuadrante(int fil, int col) {
    if(dato.pos_xy[X] <= (col/2) && dato.pos_xy[Y] <= (fil/2))
        dato.cardinal = "NO";
    else if (dato.pos_xy[X] > (col / 2) && dato.pos_xy[Y] <= (fil / 2))
        dato.cardinal = "NE";
    else if (dato.pos_xy[X] <= (col / 2) && dato.pos_xy[Y] > (fil / 2))
        dato.cardinal = "SO";
    else dato.cardinal = "SE";
}