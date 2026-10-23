#ifndef GENERICO_H_INCLUDED
#define GENERICO_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef int cmp(void *a,void *b);

void *Insercion(void *vec,void *elem, size_t *ce,size_t ce_max,size_t tam, cmp comparar);

int mBsearch(void *vec,void *elem, size_t *ce,size_t tam, cmp comparar);

void *Seleccion(void *vec,void *elem, size_t *ce,size_t tam, cmp comparar);
void *buscarMenor(void *vec, size_t *ce,size_t tam,cmp comparar);
int Intercambio(void *dest, void *src, size_t tam);

#endif // GENERICO_H_INCLUDED
