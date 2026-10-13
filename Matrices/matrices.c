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
int Identidad(unsigned fc, int mat[fc][fc])
{
    unsigned i,j;
    for(i = 0;i<fc;i++)
    {
        for(j = 0;j<fc;j++)
        {
            if((i!=j && mat[i][j]!=0) || (i==j && mat[i][j]!=1))
                return 0;
        }
    }
    return 1;
}
void **crearMatriz(size_t tam, size_t columna, size_t fila)
{
    if (tam == 0 || columna == 0 || fila == 0)
        return NULL;

    void **mat = malloc(fila * sizeof(void *));

    if (mat == NULL)
        return NULL;

    void **col;

    for (col = mat; col < mat + fila; col++)
    {
        *col = malloc(columna * tam);

        if (*col == NULL)
        {
            for (void **error = mat; error < col; error++)
                free(*error);

            free(mat);
            return NULL;
        }
    }

    return mat;
}
int EsSimetrico(int mat[][MAX_COL],unsigned fc)
{
    unsigned i,j;
    for(i=0;i<fc;i++)
    {
        for(j=i+1;j<fc;j++)
        {
            if(mat[i][j]!=mat[j][i])
            {
                return 0;
            }
        }
    }
    return 1;
}
int multiplicarMatriz(int mat1[][MAX_COL],int mat2[][MAX_COL],int new[][MAX_COL],size_t f1,size_t c1,size_t f2, size_t c2)
{
    if(c1 != f2) return 0;
    size_t i,j,k;
    for(i=0;i<f1;i++)
    {
        for(k=0;k<f1;k++)
        {
            for(j=0;j<f2;j++)
            new[i][k]+=mat1[i][j]*mat2[j][k];
        }
    }
    return 1;
}
int sumaEntreDiagSup(int mat[][MAX_COL],size_t fc)
{
    size_t i,j;
    int acum=0;
    for(i=0;i<fc/2;i++)
    {
        for(j=i+1;j<fc-1-i;j++)
        {
            acum += mat[i][j];
        }
    }
    return acum;
}
int sumaEntreDiagInf(int mat[][MAX_COL],size_t fc)
{
    size_t i,j;
    int acum=0;
    for(i=fc-1;i>fc/2;i--)
    {
        for(j=fc-i;j<i;j++)
        {
            acum += mat[i][j];
        }
    }
    return acum;
}
int sumaEntreDiagIzq(int mat[][MAX_COL],size_t fc)
{
    int medio=fc/2;
    int centro;
    int i,j;
    int suma=0;

    centro=(fc%2)==0?medio:medio-1;

    for(i=0; i < centro+1 ;i++)
    {
        for(j=i+1; j < fc-i-1 ;j++)
        {
            suma+=mat[j][i];
        }
    }
    return suma;
}
int sumaEntreDiagDer(int mat[][MAX_COL],size_t fc)
{
        int medio=fc/2;
    int centro;
    int i,j;
    int suma=0;

    centro=(fc%2)==0?medio:medio-1;

    for(i=medio + 1; i < fc ;i++)
    {
        for(j=centro; j < i ;j++)
        {
            suma+=mat[j][i];
        }
    }
    return suma;
}
