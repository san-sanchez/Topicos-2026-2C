#ifndef UTILITARIAS_H_INCLUDED
#define UTILITARIAS_H_INCLUDED

#include "banco.h"

#define TAM_LINEA 50
#define TAM_CAD 4
#define POSICION 100

void crear_archivo_cuentas(const char * path);
void crear_archivo_movimientos(const char * path);

void mostrar_archivo_cuentas(const char * path);
void mostrar_archivo_movimientos(const char * path);


unsigned descomponer_y_sumar(unsigned rta);


#endif // UTILITARIAS_H_INCLUDED
