#include "matrices.h"

int main()
{
    printf("Hello world!\n");
    int mat[4][4]={{1,1,1,1},{1,1,1,1},{1,1,1,1},{1,1,1,1}};
    int total =SumaMatrizDiagSup(4,4,mat);
    printf("total de suma:%i", total);
    return 0;
}
