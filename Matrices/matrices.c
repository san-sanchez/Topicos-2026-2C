#include "matrices.h"

int SumaMatrizDiagSup(unsigned f,unsigned c,int mat[f][c])
{
    int acum = 0;
    int i,j;
    for(i=0;i<f;i++)
    {
        for(j=i+1;j<c;j++)
        {
            acum += mat[i][j];
        }
    }
    return acum;
}
int SumaMatrizDiagInf(unsigned f,unsigned c,int mat[f][c])
{
    int acum = 0;
    int i,j;
    for(i=f;i>0;i--)
    {
        for(j=i-1;j>0;j--)
        {
            acum += mat[i][j];
        }
    }
    return acum;
}
int SumaMatrizConDiagSup(unsigned f,unsigned c,int mat[f][c])
{
    int acum = 0;
    int i,j;
    for(i=0;i<f;i++)
    {
        for(j=i;j<c;j++)
        {
            acum += mat[i][j];
        }
    }
    return acum;
}
int SumaMatrizSegSup(unsigned f,unsigned c,int mat[f][c])
{
    int acum = 0;

    for (unsigned i = 0; i < f; i++)
    {
        for (unsigned j = 0; j < c && i + j < c - 1; j++)
        {
            acum += mat[i][j];
        }
    }
    return acum;
}
int SumaMatrizSegInf(unsigned f,unsigned c,int mat[f][c])
{
    int acum = 0;

    for (unsigned i = 0; i < f; i++)
    {
        for (unsigned j = c - i; j < c; j++)
        {
            acum += mat[i][j];
        }
    }

    return acum;
}
int SumaMatrizConSegSup(unsigned f,unsigned c,int mat[f][c])
{
    int acum = 0;

    for (unsigned i = 0; i < f; i++)
    {
        for (unsigned j = 0; j < c && i + j < c; j++)
        {
            acum += mat[i][j];
        }
    }
    return acum;
}
int sumatoriaDiagonal(int **mat,unsigned fc)
{
    int acum = 0;
    int i;
    for(i=0;i<fc;i++)
    {
        acum = mat[i][i];
    }
    return acum;
}
int sumatoriaSecundaria(int **mat,unsigned fc)
{
    int acum = 0;
    int i;
    for(i=0;i<fc;i++)
    {
        acum += mat[i][fc-i-1];
    }
    return acum;
}
