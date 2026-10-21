#ifndef BANCO_H_INCLUDED
#define BANCO_H_INCLUDED

#include <stdio.h>

#include "tipos.h"

void actualizar_cuentas     (const char *path_arch_ctas, const char *path_arch_movs, const char *path_arch_err);
void actualizar_cuentas_res (const char *path_arch_ctas, const char *path_arch_movs, const char *path_arch_err);

int texto_a_movimiento     (FILE *arch_movs, t_movimiento *pmov);
int texto_a_movimiento_res (FILE *arch_movs, t_movimiento *pmov);

int validar_nro_cuenta      (const char *nro_cta);
int validar_nro_cuenta_res  (const char *nro_cta);

#endif // BANCO_H_INCLUDED