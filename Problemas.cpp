#include <iostream>
#include "Punteros.h"
#include "Problemas.h"
using namespace std;

//1
void P1() {
    long monto;
    int billetes[] = {50000, 20000, 10000, 5000, 2000, 1000};
    int monedas[] = {500, 200, 100, 50};
    int resultadosBilletes[6];
    int resultadosMonedas[4];

    cout << "Ingrese la cantidad de dinero: ";
    cin >> monto;

    long restante = monto;

    calcularDenominaciones(billetes, 6, &restante, resultadosBilletes);
    calcularDenominaciones(monedas, 4, &restante, resultadosMonedas);

    cout << endl;
    for (int i = 0; i < 6; i++) {
        cout << billetes[i] << " : " << resultadosBilletes[i] << endl;
    }
    for (int i = 0; i < 4; i++) {
        cout << monedas[i] << " : " << resultadosMonedas[i] << endl;
    }

    cout << "Faltante: " << restante << endl;
}

//3
void P3() {
    char cad1[100], cad2[100];

    cout << "Ingrese la primera cadena: ";
    cin >> cad1;
    cout << "Ingrese la segunda cadena: ";
    cin >> cad2;

    if (compararCadenas(cad1, cad2))
        cout << "Las cadenas son iguales." << endl;
    else
        cout << "Las cadenas son diferentes." << endl;
}

//5
void P5() {
    int numeroOriginal;
    char cadena[20];

    cout << "Ingrese un numero entero: ";
    cin >> numeroOriginal;

    enteroACadena(numeroOriginal, cadena);

    cout << "Numero original: " << numeroOriginal << endl;
    cout << "Cadena resultante: " << cadena << endl;
}

//7
void P7() {
    char original[100], resultado[100];

    cout << "Ingrese una cadena: ";
    cin >> original;

    eliminarRepetidos(original, resultado);

    cout << "Original: " << original << ". Sin repetidos: " << resultado << "." << endl;
}

//9
void P9() {
    int n;
    char cadena[100];

    cout << "Ingrese el valor de n: ";
    cin >> n;
    cout << "Ingrese la cadena de numeros: ";
    cin >> cadena;

    long suma = sumaGrupos(cadena, n);

    cout << "Original: " << cadena << "." << endl;
    cout << "Suma: " << suma << "." << endl;
}

//11
void P11() {
    const int FILAS = 15;
    const int ASIENTOS = 20;

    char sala[FILAS * ASIENTOS];

    inicializarSala(sala, FILAS * ASIENTOS);

    int opcion;

    do {
        cout << "\n--- Sala de Cine ---" << endl;
        cout << "1. Ver sala" << endl;
        cout << "2. Reservar asiento" << endl;
        cout << "3. Cancelar reserva" << endl;
        cout << "4. Volver al menu principal" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        if (opcion == 1) {
            cout << endl;
            imprimirSala(sala, FILAS, ASIENTOS);
        } else if (opcion == 2 || opcion == 3) {
            char filaChar;
            int asiento;

            cout << "Ingrese la fila (A-O): ";
            cin >> filaChar;
            cout << "Ingrese el numero de asiento (1-20): ";
            cin >> asiento;

            if (filaChar >= 'a' && filaChar <= 'z') {
                filaChar = filaChar - 'a' + 'A';
            }

            int f = filaChar - 'A';
            int a = asiento - 1;

            if (f < 0 || f >= FILAS || a < 0 || a >= ASIENTOS) {
                cout << "Fila o asiento invalido." << endl;
            } else if (opcion == 2) {
                bool exito = cambiarEstadoAsiento(sala, f, a, ASIENTOS, '-', '+');
                if (exito)
                    cout << "Asiento reservado con exito." << endl;
                else
                    cout << "El asiento ya esta reservado." << endl;
            } else {
                bool exito = cambiarEstadoAsiento(sala, f, a, ASIENTOS, '+', '-');
                if (exito)
                    cout << "Reserva cancelada con exito." << endl;
                else
                    cout << "El asiento no tiene reserva." << endl;
            }
        } else if (opcion != 4) {
            cout << "Opcion invalida." << endl;
        }

    } while (opcion != 4);
}

//13
void P13() {
    const int FILAS = 6;
    const int COLUMNAS = 8;

    int imagen[FILAS][COLUMNAS] = {
        {0, 3, 4, 0, 0, 0, 6, 8},
        {5, 13, 6, 0, 0, 0, 2, 3},
        {2, 6, 2, 7, 3, 0, 10, 0},
        {0, 0, 4, 15, 4, 1, 6, 0},
        {0, 0, 7, 12, 6, 9, 10, 4},
        {5, 0, 6, 10, 6, 4, 8, 0}
    };

    int cantidad = contarEstrellas(&imagen[0][0], FILAS, COLUMNAS);

    cout << "Numero de estrellas encontradas: " << cantidad << endl;
}

//15
void P15() {
    int A[4], B[4], C[4];

    cout << "Ingrese el rectangulo A (x y ancho alto): ";
    cin >> A[0] >> A[1] >> A[2] >> A[3];

    cout << "Ingrese el rectangulo B (x y ancho alto): ";
    cin >> B[0] >> B[1] >> B[2] >> B[3];

    interseccionRectangulos(A, B, C);

    if (C[2] > 0 && C[3] > 0) {
        cout << "Rectangulo interseccion C: {" << C[0] << ", " << C[1]
             << ", " << C[2] << ", " << C[3] << "}" << endl;
    } else {
        cout << "Los rectangulos no se intersectan." << endl;
    }
}

//17
void P17() {
    int limite;
    cout << "Ingrese un numero: ";
    cin >> limite;

    long sumaTotal = 0;

    for (int a = 1; a < limite; a++) {
        long sumaA;
        calcularSumaDivisores(a, &sumaA);

        int b = (int)sumaA;
        if (b != a && b > a && b < limite) {
            long sumaB;
            calcularSumaDivisores(b, &sumaB);
            if (sumaB == a) {
                sumaTotal += a + b;
            }
        }
    }

    cout << "El resultado de la suma es: " << sumaTotal << endl;
}
