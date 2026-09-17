#ifndef PUNTEROS_H
#define PUNTEROS_H

void calcularDenominaciones(const int *denominaciones, int cantidad, long *restante, int *resultados);//1

int longitudCadena(const char *cadena);
bool compararCadenas(const char *cad1, const char *cad2);//3

void enteroACadena(int numero, char *cadena);//5

void eliminarRepetidos(const char *original, char *resultado);//7

long sumaGrupos(const char *cadena, int n);//9

void inicializarSala(char *sala, int totalCeldas);//11
void imprimirSala(const char *sala, int filas, int asientos);
bool cambiarEstadoAsiento(char *sala, int fila, int asiento, int asientosPorFila, char estadoRequerido, char nuevoEstado);

int contarEstrellas(const int *imagen, int filas, int columnas);//13

void interseccionRectangulos(const int *A, const int *B, int *C);//15

void calcularSumaDivisores(int n, long *resultado);//17

#endif // PUNTEROS_H
