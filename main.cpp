#include <iostream>
#include "Problemas.h"
using namespace std;

int main() {
    int opcion;
    char continuar;

    do {
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cout << endl;

        switch (opcion) {
            case 1:  P1();  break;
            case 3:  P3();  break;
            case 5:  P5();  break;
            case 7:  P7();  break;
            case 9:  P9();  break;
            case 11: P11(); break;
            case 13: P13(); break;
            case 15: P15(); break;
            case 17: P17(); break;
            default: cout << "Opcion invalida" << endl;
        }

        cout << "\nEjecutar otro problema (s/n): ";
        cin >> continuar;

    } while (continuar == 's' || continuar == 'S');

    return 0;
}
