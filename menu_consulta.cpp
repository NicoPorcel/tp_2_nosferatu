#include "menu_consulta.h"

void Menu_consulta::menu_consulta(Lista& list) {
    char pausa;
    opcion_objeto = '0';
    cout << "\n────────────────────────────────────────────────────────────";
    cout << "\n                    ──| MENU CONSULTA |──" << endl;
    cout << "────────────────────────────────────────────────────────────";
    elegir_cuadrante();
    cout << "────────────────────────────────────────────────────────────";
    cout << "\n Seleccione el objeto con un numero: " << endl;
    cout << "────────────────────────────────────────────────────────────";
    cout << "\n  »  1 · Ser Humano" << endl << "  »  2 · Vampiros" << endl;
    cout << "  »  3 · Zombi" << endl << "  »  4 · Agua Bendita" << endl;
    cout << "  »  5 · Cruz" << endl << "  »  6 · Estaca" << endl;
    cout << "  »  7 · Escopeta" << endl << "  »  8 · Balas" << endl;
    cout << "────────────────────────────────────────────────────────────";
    cout << "\n---→ ";
    cin >> opcion_objeto;
    validar_opcion(opcion_objeto, '1', '8');
    if(opcion_objeto == '1') procesar_opcion_humano(list);
    else if(opcion_objeto == '2') procesar_opcion_vampiro(list);
    else procesar_opcion(list);
    cout << endl << "ingrese una letra o numero y presione enter... ";
    cin >> pausa;
}

void Menu_consulta::validar_opcion(char& eleccion, char min, char max) {
    while(eleccion < min || eleccion > max){
        cout <<"\n  -- Error, opcion invalida, ingrese un numero valido --" << endl;
        cout << "--→ Indique opcion (numerica) : ";
        cin >> eleccion;
    }
}

void Menu_consulta::procesar_opcion(Lista& list) {
    cout << endl;
    if (opcion_objeto == '3'){ Zombi zombi("zombi", cuadrante_elegido);
        zombi.buscar_objeto(list);
    }
    else if (opcion_objeto == '4'){ Agua_bendita agua("agua", cuadrante_elegido);
        agua.buscar_objeto(list);
    }
    else if (opcion_objeto == '5'){ Cruz cruz("cruz", cuadrante_elegido);
        cruz.buscar_objeto(list);
    }
    else if (opcion_objeto == '6'){ Estaca estaca("estaca", cuadrante_elegido);
        estaca.buscar_objeto(list);
    }
    else if (opcion_objeto == '7'){ Escopeta escopeta("escopeta", cuadrante_elegido);
        escopeta.buscar_objeto(list);
    }
    else{ Bala bala("bala", cuadrante_elegido);
        bala.buscar_objeto(list);
    }
}

void Menu_consulta::procesar_opcion_humano(Lista& list) {
    opcion_objeto = '0';
    cout << "────────────────────────────────────────────────────────────";
    cout << "\n Seleccione el objeto con un numero: " << endl;
    cout << "────────────────────────────────────────────────────────────";
    cout << "\n  »  1 · Humano" << endl << "  »  2 · Vanesa" << endl;
    cout << "  »  3 · Caza-vampiro" << endl;
    cout << "────────────────────────────────────────────────────────────" << endl;
    cout << "\n---→ ";
    cin >> opcion_objeto;
    validar_opcion(opcion_objeto, '1', '3');
    if(opcion_objeto == '1'){ Humano humano("humano", cuadrante_elegido);
        humano.buscar_objeto(list);
    }
    else if(opcion_objeto == '2'){ Vanesa vanesa("Vanesa", cuadrante_elegido);
        vanesa.buscar_objeto(list);
    }
    else{ Cazavampiro humano_cv("humano CV", cuadrante_elegido);
        humano_cv.buscar_objeto(list);
    }
}

void Menu_consulta::procesar_opcion_vampiro(Lista& list) {
    opcion_objeto = '0';
    cout << "────────────────────────────────────────────────────────────";
    cout << "\n Seleccione el objeto con un numero: " << endl;
    cout << "────────────────────────────────────────────────────────────";
    cout << "\n  »  1 · Vampiro" << endl << "  »  2 · Vampirella" << endl;
    cout << "  »  3 · Nosferatu" << endl;
    cout << "────────────────────────────────────────────────────────────" << endl;
    cout << "\n---→ ";
    cin >> opcion_objeto;
    validar_opcion(opcion_objeto, '1', '3');
    if(opcion_objeto == '1'){ Vampiro vampiro("vampiro", cuadrante_elegido);
        vampiro.buscar_objeto(list);
    }
    else if(opcion_objeto == '2'){ Vampirella vampirella("Vampirella", cuadrante_elegido);
        vampirella.buscar_objeto(list);
    }
    else{ Nosferatu nosferatu("Nosferatu", cuadrante_elegido);
        nosferatu.buscar_objeto(list);
    }
}

void Menu_consulta::elegir_cuadrante() {
    opcion_cuadrante = '0';
    cout << "\n────────────────────| CUADRANTE |─────────────────────────";
    cout << "\n      Seleccione el cuadrante con un numero: " << endl;
    cout << "────────────────────────────────────────────────────────────";
    cout << "\n  »  1 · NorOeste" << endl;
    cout << "\n  »  2 · NorEste" << endl;
    cout << "\n  »  3 · SurOeste" << endl;
    cout << "\n  »  4 · SurEste" << endl;
    cout << "────────────────────────────────────────────────────────────" << endl;
    cout << "\n---→ ";
    cin >> opcion_cuadrante;
    cout << "────────────────────────────────────────────────────────────" << endl;
    validar_opcion(opcion_cuadrante, '1', '4');
    if (opcion_cuadrante == '1') cuadrante_elegido = "NO";
    else if (opcion_cuadrante == '2') cuadrante_elegido = "NE";
    else if (opcion_cuadrante == '3') cuadrante_elegido = "SO";
    else cuadrante_elegido = "SE";
}
