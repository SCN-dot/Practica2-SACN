#ifndef PUNTEROS_H
#define PUNTEROS_H

void calcularDenominaciones(const int *denominaciones, int cantidad,
                            long *restante, int *resultados);

int longitudCadena(const char *cadena);
bool compararCadenas(const char *cad1, const char *cad2);

void enteroACadena(int numero, char *cadena);

void eliminarRepetidos(const char *original, char *resultado);

long sumaGrupos(const char *cadena, int n);

void inicializarSala(char *sala, int totalCeldas);
void imprimirSala(const char *sala, int filas, int asientos);
bool cambiarEstadoAsiento(char *sala, int fila, int asiento, int asientosPorFila,
                          char estadoRequerido, char nuevoEstado);

int contarEstrellas(const int *imagen, int filas, int columnas);

void interseccionRectangulos(const int *A, const int *B, int *C);

void calcularSumaDivisores(int n, long *resultado);

#endif // PUNTEROS_H
