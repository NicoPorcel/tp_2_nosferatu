#include "tablero.h"

Tablero::Tablero(int f, int c) {
    fila = f;
    columna = c;
    matriz_c = new char*[f];
    for (int i = 0; i < f; i++) {
        matriz_c[i] = new char[c];
    }
    contador = new float[TIPOS];
}

void Tablero::iniciar_tablero() {
    for (int i = 0; i < fila; i++) {
        for (int j = 0; j < columna; j++) {
            matriz_c[i][j] = '*';
        }
    }
}

void Tablero::cargar_tablero(Lista& lista) {
    unsigned i = 1;
    int x, y;
    do {
        dato = lista.consultar(i);
        x = dato.pos_xy[Y] - 1;
        y = dato.pos_xy[X] - 1;
        (matriz_c[x][y]) = dato.simbolo;
        i++;
    } while(i <= lista.obtenerTam());
}

void Tablero::mostrar_tablero(Lista& lista) {
    char pausa;
    iniciar_tablero();
    cargar_tablero(lista);
    cout << "─────────────────────────| MAPA |───────────────────────────" << endl;
    for (int i = 0; i < fila; i++) {
        for (int j = 0; j < columna; j++) {
            cout << (matriz_c[i][j]) << "    ";
        }
        cout << endl << endl;
    }
    cout << "────────────────────────────────────────────────────────────" << endl;
    cout << endl << "ingrese una letra o numero y luego presione enter... ";
    cin >> pausa;
    cout << endl;
}

void Tablero::iniciar_contador() {
    for (int i = 0; i < TIPOS; i++)
        contador[i] = 0;
}

void Tablero::cargar_contador(Lista& lista) {
    unsigned i = 1;
    do {
        dato = lista.consultar(i);
        if (dato.nombre == "humano" || dato.nombre == "humano CV" || dato.nombre == "Vanesa")
            contador[HUMANO]++;
        else if (dato.nombre == "vampiro" || dato.nombre == "Vampirella" || dato.nombre == "Nosferatu")
            contador[VAMPIRO]++;
        else if (dato.nombre == "zombi")  contador[ZOMBI]++;
        else if (dato.nombre == "agua")  contador[AGUA] += dato.cantidad;
        else if (dato.nombre == "cruz")  contador[CRUZ]++;
        else if (dato.nombre == "estaca")  contador[ESTACA]++;
        else if (dato.nombre == "escopeta")  contador[ESCOPETA]++;
        else contador[BALA] += dato.cantidad;
        i++;
    } while(i <= lista.obtenerTam());
}

void Tablero::mostrar_cuadro(Lista& lista) {
    char pausa;
    iniciar_contador();
    cargar_contador(lista);
    string indef = "indef.";
    float total_sujetos = (contador[HUMANO] + contador[ZOMBI] + contador[VAMPIRO]);
    float total_objetos = (contador[AGUA] + contador[CRUZ] + contador[ESTACA]);
    if(total_sujetos == 0) total_sujetos = 1;
    if(total_objetos == 0) total_objetos = 1;
    cout << fixed << setprecision(1) << endl;
    cout << "\n───────────────────| Cuadro de datos |──────────────────────" << endl;
    cout <<"\n Elemento     " << "    Cantidad    " << "Porcentaje" << endl;
    cout << " Humanos             " << (int)contador[HUMANO]  << "          " << (contador[HUMANO]/total_sujetos) * 100 << endl;
    cout << " Zombis              " << (int)contador[ZOMBI]   << "          " << (contador[ZOMBI]/total_sujetos) * 100 << endl;
    cout << " Vampiros            " << (int)contador[VAMPIRO] << "          " << (contador[VAMPIRO]/total_sujetos) * 100 << endl;
    cout << " Agua bendita        " << (int)contador[AGUA]    << "          " << (contador[AGUA]/total_objetos) * 100 << endl;
    cout << " Cruces              " << (int)contador[CRUZ]    << "          " << (contador[CRUZ]/total_objetos) * 100 << endl;
    cout << " Estacas             " << (int)contador[ESTACA]  << "          " << (contador[ESTACA]/total_objetos) * 100 << endl;
    if (contador[BALA] == 0 && contador[ESCOPETA] == 0) {
        cout << " Escopetas           " << (int) contador[ESCOPETA] << "          " << indef << endl;
        cout << " Balas               " << (int) contador[BALA]     << "          " << indef << endl;
    } else if (contador[BALA] == 0 && contador[ESCOPETA] != 0) {
        cout << " Escopetas           " << (int) contador[ESCOPETA] << "          " << indef << endl;
        cout << " Balas               " << (int) contador[BALA]     << "          " << contador[BALA] << endl;
    } else if (contador[BALA] != 0 && contador[ESCOPETA] == 0) {
        cout << " Escopetas           " << (int) contador[ESCOPETA] << "          " << contador[ESCOPETA] << endl;
        cout << " Balas               " << (int) contador[BALA]     << "          " << indef << endl;
    } else {
        cout << " Escopetas           " << (int) contador[ESCOPETA] << "          " << (contador[ESCOPETA] / contador[BALA]) * 100 << endl;
        cout << " Balas               " << (int)contador[BALA]      << "          " << (contador[BALA]/contador[ESCOPETA]) * 100 << endl;
    }
    cout << "────────────────────────────────────────────────────────────" << endl;
    cout << endl << "ingrese una letra o numero y luego presione enter... ";
    cin >> pausa;
    cout << endl;
}

Tablero::~Tablero() {
    for (int i = 0; i < fila; i++) {
        if(matriz_c[i] != nullptr){
            delete[] matriz_c[i];
            matriz_c[i] = nullptr;
        }
    }
    delete[] matriz_c;
    delete[] contador;
}