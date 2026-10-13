#ifndef MATRICES_H_INCLUDED
#define MATRICES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COL 500
int SumaMatrizDiagSup(unsigned f,unsigned c,int mat[f][c]);
int SumaMatrizDiagInf(unsigned f,unsigned c,int mat[f][c]);
int SumaMatrizConDiagSup(unsigned f,unsigned c,int mat[f][c]);
int SumaMatrizSegSup(unsigned f,unsigned c,int mat[f][c]);
int SumaMatrizSegInf(unsigned f,unsigned c,int mat[f][c]);
int SumaMatrizConSegSup(unsigned f,unsigned c,int mat[f][c]);
int sumatoriaDiagonal(int **mat,unsigned fc);
int sumatoriaSecundaria(int **mat,unsigned fc);
void **crearMatriz(size_t tam, size_t columna, size_t fila);
int EsSimetrico(int mat[][MAX_COL],unsigned fc);
int multiplicarMatriz(int mat1[][MAX_COL],int mat2[][MAX_COL],int new[][MAX_COL],size_t f1,size_t c1,size_t f2, size_t c2);
int sumaEntreDiagSup(int mat[][MAX_COL],size_t fc);
int sumaEntreDiagInf(int mat[][MAX_COL],size_t fc);
int sumaEntreDiagIzq(int mat[][MAX_COL],size_t fc);
int sumaEntreDiagDer(int mat[][MAX_COL],size_t fc);
#endif // MATRICES_H_INCLUDED
