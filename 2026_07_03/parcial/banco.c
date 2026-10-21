#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "banco.h"
#include "utilitarias.h"


/**
	Haga todo su código en este fuente.

	Para la resolución puede valerse de las funciones provistas
	- void actualizar_cuentas_res(const char *path_arch_ctas, const char *path_arch_movs, const char *path_arch_err);
	- int texto_a_movimiento(FILE *arch_movs, t_movimiento *pmov);
	- int validar_nro_cuenta(const char *nro_cta);

	Escribir su versión de las funciones siguientes (Puede crear cualquier otra función necesaria para resolver el ejercicio).
*/

/******************************************************************************/
/* Actualiza el archivo binario de cuentas aplicando los movimientos del      */
/* archivo de texto. Los movimientos con DV inválido se descartan y se        */
/* registran en el archivo de errores.                                        */
/******************************************************************************/
void actualizar_cuentas(const char *path_arch_ctas, const char *path_arch_movs, const char *path_arch_err)
{
    FILE *archCta =  fopen(path_arch_ctas,"r+b");
    FILE *archMovs = fopen(path_arch_movs,"rt");
    FILE *archErr = fopen(path_arch_err,"wt");

    t_cuenta cta;
    t_movimiento mov;
    int lee_mov, cmp;

    /// SI ALGUN ARCHIVOS FALLA SE CORTA LA FUNCION
    if(!archCta ||!archErr || !archMovs) return;

    ///LECTURA DE ARCH CTA Y MOVS
    lee_mov = texto_a_movimiento(archMovs,&mov);
    fread(&cta,sizeof(t_cuenta),1,archCta);


    while(!feof(archCta)&& lee_mov)
    {
        if(!validar_nro_cuenta(mov.cod_cta))
        {
            fprintf(archErr,"%s|%c|%.2f\n",mov.cod_cta,mov.tipo_mov,mov.importe);
            lee_mov = texto_a_movimiento(archMovs,&mov);
        }else
        {
            cmp = strcmp(cta.cod_cta,mov.cod_cta);
            if(cmp == 0)
            {
                if(mov.tipo_mov =='C')
                {
                    cta.saldo += mov.importe;
                }
                else
                {
                    cta.saldo -= mov.importe;
                }
                fseek(archCta,-(long)sizeof(t_cuenta),SEEK_CUR);
                fwrite(&cta,sizeof(t_cuenta),1,archCta);
                fseek(archCta,0L,SEEK_CUR);

                fread(&cta,sizeof(t_cuenta),1,archCta);
                lee_mov = texto_a_movimiento(archMovs,&mov);
            }
            else
            {
                if(cmp < 0)
                {
                    fread(&cta,sizeof(t_cuenta),1,archCta);

                }
                else
                {
                    lee_mov = texto_a_movimiento(archMovs,&mov);
                }
            }

        }
    }

    /// CIERRE DE ARCHIVOS

    fclose(archCta);
    fclose(archErr);
    fclose(archMovs);

    ///Inserte el código aquí
}

/******************************************************************************/
/* Lee una línea del archivo de movimientos (formato "cod|tipo|importe\n") y  */
/* la convierte en un struct t_movimiento.                                    */
/* Devuelve 1 si la lectura fue exitosa, 0 si se alcanzó el EOF.              */
/******************************************************************************/
int texto_a_movimiento(FILE *arch_movs, t_movimiento *pmov)
{
    char cad[TAM_LINEA];
    if(!fgets(cad,sizeof(cad),arch_movs)) return 0;

    if(sscanf(cad,"%[^|]|%c|%f",pmov->cod_cta,&pmov->tipo_mov,&pmov->importe)!=3) return 0;

    return 1;
}

/******************************************************************************/
/* Valida el número de cuenta con formato "NNNNNN/D".                         */
/* Devuelve 1 si el DV calculado coincide con el DV del string, 0 si no.      */
/******************************************************************************/
int validar_nro_cuenta(const char *nro_cta)
{
    ///SACO LA POSICION DONDE SE ENCUENTRA EL DIGITO VERIFICADOR
    size_t tam = strlen(nro_cta);
    char *verificador = (char*)nro_cta + tam-1;

    size_t i;
    int Digitos[6];

    int par = 0,impar = 0,rta = 0;
    ///PASO DE CHAR A UNSIGNED
    for(i=0;i< tam-2;i++) Digitos[i] = nro_cta[i]-'0';
    /// SEPARO POSICIONES PARES Y IMPARES
    impar = Digitos[0]*100 + Digitos[2]*10 + Digitos[4];
    par = Digitos[1]*100 + Digitos[3]*10 + Digitos[5];

    /// APLICO LA DIFERENCIA
    rta = impar-par;
    if(rta < 0) rta = -rta;

    while(rta > 9) rta = descomponer_y_sumar(rta);


    ///Inserte el código aquí
    return rta == (*verificador -'0');
}
unsigned descomponer_y_sumar(unsigned rta)
{
    unsigned suma=0;

    while(rta > 0)
    {
        suma += rta % 10;
        rta /= 10;
    }
    return suma;
}
