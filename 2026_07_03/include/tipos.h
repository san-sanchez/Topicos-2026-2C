#ifndef TIPOS_H_INCLUDED
#define TIPOS_H_INCLUDED

typedef struct{
    char cod_cta[9];
    char apyn[40];
    float saldo;
}t_cuenta;

typedef struct{
    char cod_cta[9];
    char tipo_mov;
    float importe;
}t_movimiento;

#endif // TIPOS_H_INCLUDED
