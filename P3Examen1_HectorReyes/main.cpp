/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Onasis Reyes
 *
 * Created on 20 de noviembre de 2020, 01:38 PM
 */

#include <cstdlib>
#include <iostream>
#include <ctime>

using std::cin;
using std::cout;
using std::endl;

using namespace std;

void imprimir_Matriz(int, int, int**&);
void generar_Matriz_Predeterminada(int, int, int**&);
void generar_Matriz_Aleatoria(int, int, int, int**&);
void conway(int, int, int, int**&);
void nueva_Generacion(int, int, int**&);
void liberarMatriz(int, int**&);

/*
 * 
 */
int main(int argc, char** argv) {
    bool continuar = true;
    int opcion = 0;
    while (continuar) {
        cout << "Menu\n"
                "0. Salir\n"
                "1. Jugar con Tablero Aleatorio\n"
                "2. Jugar con Tablero Predefinido\n"
                "-> Escoja su opción: ";
        cin >> opcion;
        cout << endl;
        switch (opcion) {
            case 1:
            {
                int filas = 0, columnas = 0, celulas_vivas = 0, turnos = 0;
                cout << "Ingrese número de filas del tablero: ";
                cin >> filas;
                while (filas < 1) {
                    cout << "El número de filas debe ser mayor a 0: ";
                    cin >> filas;
                }
                cout << "Ingrese número de columnas del tablero: ";
                cin >> columnas;
                while (columnas < 1) {
                    cout << "El número de columnas debe ser mayor a 0: ";
                    cin >> columnas;
                }//fin while
                cout << "Ingrese número de celulas iniciales: ";
                cin >> celulas_vivas;
                while (celulas_vivas > filas * columnas) {
                    cout << "El número de células iniciales excede las celdas del tablero\n"
                            "Porfavor ingrese un número menor que " << (filas * columnas);
                    cin >> celulas_vivas;
                }
                while (celulas_vivas < 1) {
                    cout << "El número de células iniciales debe ser mayor a 0: ";
                    cin >> celulas_vivas;
                }//fin while
                cout << "Ingrese número de generaciones: ";
                cin >> turnos;
                while (turnos < 0) {
                    cout << "El número de generaciones debe ser mayor a 0: ";
                    cin >> turnos;
                }//fin while
                int ** tablero = new int*[columnas];
                generar_Matriz_Aleatoria(filas, columnas, celulas_vivas, tablero);
                imprimir_Matriz(filas, columnas, tablero);
                cout << endl;
                conway(filas, columnas, turnos - 1, tablero);
                liberarMatriz(filas, tablero);
                break;
            }
            case 2:
            {
                int filas = 20,
                        columnas = 20, turnos = 0;
                int ** tablero = new int*[columnas];
                cout << "Ingrese cantidad de turnos: ";
                cin >> turnos;
                while (turnos < 1) {
                    cout << "Ingrese cantidad de turnos mayor o igual a 1: ";
                    cin >> turnos;
                }//fin while
                generar_Matriz_Predeterminada(filas, columnas, tablero);
                imprimir_Matriz(filas, columnas, tablero);
                cout << endl;
                conway(filas, columnas, turnos - 1, tablero);
                liberarMatriz(filas, tablero);
                break;
            }
            case 0:
            {
                cout << "Fin de la ejecución.";
                continuar = false;
                break;
            }
            default:
            {
                cout << "Opción inexistente.";
            }
        }//fin switch
        cout << endl;
    }//fin while
    return 0;
}//fin main

void imprimir_Matriz(int filas, int columnas, int**& matriz) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            if (matriz[i][j] == 0) {
                cout << "- ";
            } else {
                cout << "* ";
            }
        }//fin for
        cout << endl;
    }//fin for
}//fin método

void generar_Matriz_Predeterminada(int filas, int columnas, int**& tablero) {
    int temp_mat [filas][columnas] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0},
        {0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 0, 1, 0},
        {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };
    for (int i = 0; i < filas; i++) {
        tablero[i] = new int[filas];
        for (int j = 0; j < columnas; j++) {
            tablero[i][j] = temp_mat[i][j];
        }//fin for
    }//fin for
}//fin método

void conway(int filas, int columnas, int turnos, int**& tablero) {
    if (turnos > 0) {
        /*cout << "Presione ENTER para continuar: " << endl << endl;
        cin.ignore();*/
        int** nueva_generacion = tablero;
        int vecinos = 0;
        for (int i = 0; i < filas; i++) {
            for (int j = 0; j < columnas; j++) {
                //estos if son para revisar las celulas vivas
                if (i - 1 >= 0 && j - 1 >= 0) {
                    if (tablero[i - 1][j - 1] == 1) {
                        vecinos++;
                    }
                }
                if (i - 1 >= 0) {
                    if (tablero[i - 1][j] == 1) {
                        vecinos++;
                    }
                }
                if (i - 1 >= 0 && j + 1 < columnas) {
                    if (tablero[i - 1][j + 1] == 1) {
                        vecinos++;
                    }
                }
                if (j - 1 >= 0) {
                    if (tablero[i][j - 1] == 1) {
                        vecinos++;
                    }
                }
                if (j + 1 < columnas) {
                    if (tablero[i][j + 1] == 1) {
                        vecinos++;
                    }
                }
                if (i + 1 < filas && j - 1 >= 0) {
                    if (tablero[i + 1][j - 1] == 1) {
                        vecinos++;
                    }
                }
                if (i + 1 < filas) {
                    if (tablero[i + 1][j] == 1) {
                        vecinos++;
                    }
                }
                if (i + 1 < filas && j + 1 < columnas) {
                    if (tablero[i + 1][j + 1] == 1) {
                        vecinos++;
                    }
                }
                //este if es el que empieza a poner celulas vivas o muertas en la nueva generacion
                if (vecinos > 3) {
                    nueva_generacion[i][j] = 0;
                } else if (vecinos < 2) {
                    nueva_generacion[i][j] = 0;
                } else {
                    if (nueva_generacion[i][j] == 0 && vecinos == 2) {
                        nueva_generacion[i][j] = 0;
                    }
                    if (vecinos == 3) {
                        nueva_generacion[i][j] = 1;
                    }//fin else if
                }//fin else
                vecinos = 0;
            }//fin for
        }//fin for
        cout << "Pesione ENTER para continuar: ";
        cin.ignore();
        imprimir_Matriz(filas, columnas, nueva_generacion);
        cout << endl;
        conway(filas, columnas, turnos - 1, nueva_generacion);
    }//fin if
}//fin método

void generar_Matriz_Aleatoria(int filas, int columnas, int celulas_vivas, int**& tablero) {
    for (int i = 0; i < filas; i++) {
        tablero[i] = new int[filas];
        for (int j = 0; j < columnas; j++) {
            tablero[i][j] = 0;
        }//fin for
    }//fin for
    while (celulas_vivas > 0) {
        for (int i = 0; i < filas; i++) {
            for (int j = 0; j < columnas; j++) {
                if (celulas_vivas > 0 && tablero[i][j] == 0) {
                    srand(time(NULL));
                    int valor_random = std::rand() % 2;
                    if (valor_random == 1) {
                        tablero[i][j] = 1;
                        celulas_vivas--;
                    } else {
                        tablero[i][j] = 0;
                    }//fin else
                }//fin if
            }//fin for
        }//fin for
    }//fin while
}//fin método

void liberarMatriz(int filas, int**& tablero) {
    for (int i = 0; i < filas; i++) {
        delete[] tablero[i];
    } // Fin For
    delete[] tablero;
}//fin método