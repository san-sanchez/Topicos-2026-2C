#ifndef MATRICES_H_INCLUDED
#define MATRICES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

int SumaMatrizDiagSup(unsigned f,unsigned c,int mat[f][c]);
int SumaMatrizDiagInf(unsigned f,unsigned c,int mat[f][c]);
int SumaMatrizConDiagSup(unsigned f,unsigned c,int mat[f][c]);
int SumaMatrizSegSup(unsigned f,unsigned c,int mat[f][c]);
int SumaMatrizSegInf(unsigned f,unsigned c,int mat[f][c]);
int SumaMatrizConSegSup(unsigned f,unsigned c,int mat[f][c]);
int sumatoriaDiagonal(int **mat,unsigned fc);
int sumatoriaSecundaria(int **mat,unsigned fc);
#endif // MATRICES_H_INCLUDED
