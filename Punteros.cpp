#include <iostream>
#include "Punteros.h"
using namespace std;

//1
void calcularDenominaciones(const int *denominaciones, int cantidad,
                             long *restante, int *resultados) {
    for (int i = 0; i < cantidad; i++) {

        *(resultados + i) = *restante / *(denominaciones + i);
        *restante = *restante % *(denominaciones + i);
    }
}

//3
int longitudCadena(const char *cadena) {
    const char *p = cadena;
    int longitud = 0;
    while (*p != '\0') {
        longitud++;
        p++; //siguiente byte
    }
    return longitud;
}

bool compararCadenas(const char *cad1, const char *cad2) {
    const char *p1 = cad1;
    const char *p2 = cad2;

    while (*p1 != '\0' && *p2 != '\0') {
        if (*p1 != *p2) return false;
        p1++;
        p2++;
    }

    return *p1 == *p2;
}

//5
void enteroACadena(int numero, char *cadena) {
    bool negativo = false;
    int valor = numero;
    if (valor < 0) {
        negativo = true;
        valor = -valor;
    }

    int temp = valor;
    int digitos = 0;
    if (temp == 0) digitos = 1;
    while (temp != 0) {
        temp /= 10;
        digitos++;
    }

    char *p = cadena;
    if (negativo) {
        *p = '-';
        p++;
    }

    for (int i = digitos - 1; i >= 0; i--) {
        *(p + i) = (valor % 10) + '0';
        valor /= 10;
    }
    *(p + digitos) = '\0';
}

//7
void eliminarRepetidos(const char *original, char *resultado) {
    const char *pOrig = original;
    char *pRes = resultado;

    while (*pOrig != '\0') {
        bool repetido = false;
        char *pAux = resultado;
        while (pAux < pRes) {
            if (*pAux == *pOrig) {
                repetido = true;
                break;
            }
            pAux++;
        }
        if (!repetido) {
            *pRes = *pOrig;
            pRes++;
        }
        pOrig++;
    }
    *pRes = '\0';
}

//9
long sumaGrupos(const char *cadena, int n) {
    int len = longitudCadena(cadena);

    int primerGrupo = len % n;
    if (primerGrupo == 0) primerGrupo = n;

    const char *p = cadena;
    long suma = 0;
    long valor = 0;

    for (int i = 0; i < primerGrupo; i++) {
        valor = valor * 10 + (*p - '0');
        p++;
    }
    suma += valor;

    while (*p != '\0') {
        valor = 0;
        for (int i = 0; i < n; i++) {
            valor = valor * 10 + (*p - '0');
            p++;
        }
        suma += valor;
    }

    return suma;
}

//11
void inicializarSala(char *sala, int totalCeldas) {
    char *p = sala;
    for (int i = 0; i < totalCeldas; i++) {
        *(p + i) = '-'; //disponible cada asiento
    }
}

void imprimirSala(const char *sala, int filas, int asientos) {
    const char *p = sala;
    for (int i = 0; i < filas; i++) {
        cout << (char)('A' + i) << ": ";
        for (int j = 0; j < asientos; j++) {

            cout << *(p + i * asientos + j) << " ";
        }
        cout << endl;
    }
}

bool cambiarEstadoAsiento(char *sala, int fila, int asiento, int asientosPorFila, char estadoRequerido, char nuevoEstado) {
    char *celda = sala + fila * asientosPorFila + asiento;
    if (*celda != estadoRequerido) return false;
    *celda = nuevoEstado;
    return true;
}

//13
int contarEstrellas(const int *imagen, int filas, int columnas) {
    int contador = 0;

    for (int i = 1; i < filas - 1; i++) {
        for (int j = 1; j < columnas - 1; j++)//exclui bordes
        {
            const int *centro = imagen + i * columnas + j;

            int suma = *centro
                     + *(centro - 1)          // vecino izquierdo
                     + *(centro + 1)          // vecino derecho
                     + *(centro - columnas)   // vecino de arriba
                     + *(centro + columnas);  // vecino de abajo

            double promedio = suma / 5.0;
            if (promedio > 6) contador++;
        }
    }

    return contador;
}

//15
void interseccionRectangulos(const int *A, const int *B, int *C) {
    int x1;// inicio de C
    if (*(A + 0) > *(B + 0)) {
        x1 = *(A + 0);
    } else {
        x1 = *(B + 0);
    }

    int y1;
    if (*(A + 1) > *(B + 1)) {
        y1 = *(A + 1);
    } else {
        y1 = *(B + 1);
    }

    int finXA = *(A + 0) + *(A + 2);//derecha
    int finXB = *(B + 0) + *(B + 2);
    int finYA = *(A + 1) + *(A + 3);//abajo
    int finYB = *(B + 1) + *(B + 3);

    int x2;
    if (finXA < finXB) {
        x2 = finXA;
    } else {
        x2 = finXB;
    }

    int y2;
    if (finYA < finYB) {
        y2 = finYA;
    } else {
        y2 = finYB;
    }

    if (x2 > x1 && y2 > y1) {
        *(C + 0) = x1;
        *(C + 1) = y1;
        *(C + 2) = x2 - x1; //ancho de C
        *(C + 3) = y2 - y1; // Alto de C
    } else {
        *(C + 0) = 0;
        *(C + 1) = 0;
        *(C + 2) = 0;
        *(C + 3) = 0;
    }
}

//17
void calcularSumaDivisores(int n, long *resultado) {
    long suma = 0;
    for (int i = 1; i <= n / 2; i++) {
        if (n % i == 0) suma += i;
    }
    *resultado = suma;
}
