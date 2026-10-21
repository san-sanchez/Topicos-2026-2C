#include <stdio.h>
#include <stdlib.h>

#include "banco.h"
#include "utilitarias.h"

#define ARCH_CUENTAS "../Archivos/cuentas.dat"
#define ARCH_MOVIMIENTOS "../Archivos/movimientos.txt"
#define ARCH_ERROR "../Archivos/error.txt"

int main()
{
    crear_archivo_cuentas(ARCH_CUENTAS);
    crear_archivo_movimientos(ARCH_MOVIMIENTOS);

    printf("\n\n*********CUENTAS***********\n");
    mostrar_archivo_cuentas(ARCH_CUENTAS);
    printf("\n*********FIN CUENTAS***********\n\n");

    printf("\n\n*********MOVIMIENTOS***********\n");
    mostrar_archivo_movimientos(ARCH_MOVIMIENTOS);
    printf("\n*********FIN MOVIMIENTOS***********\n\n");


    //actualizar_cuentas_res(ARCH_CUENTAS, ARCH_MOVIMIENTOS, ARCH_ERROR);
    actualizar_cuentas(ARCH_CUENTAS, ARCH_MOVIMIENTOS, ARCH_ERROR);


    printf("\n\n*********CUENTAS ACT***********\n");
    mostrar_archivo_cuentas(ARCH_CUENTAS);
    printf("\n*********FIN CUENTAS ACT***********\n\n");

    return 0;
}
