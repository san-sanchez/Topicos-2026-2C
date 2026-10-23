#include "generico.h"

void *Insercion(void *vec,void *elem, size_t *ce,size_t ce_max,size_t tam, cmp comparar)
{
    if(*ce==0){
        memcpy(vec,elem,tam);
        (*ce)+=1;
    }
    void *ptrIni = (char*)vec;
    vec = (*ce == ce_max) ? (vec + (((*ce)-1)*tam)) : (vec + ((*ce)*tam));

    if(*ce == ce_max && comparar(vec,elem)>0) return NULL;


    while(vec > ptrIni && comparar(elem,vec-tam)<0)
    {
        memcpy(vec,vec-tam,tam);
        vec -= tam;
    }
    memcpy(vec,elem,tam);
    *ce = *ce==ce_max?*ce:(*ce) + 1;
    return vec;
}
void *Seleccion(void *vec,void *elem, size_t *ce,size_t tam, cmp comparar)
{
    void *menor;
    size_t i;
    for(i=1;i<*ce-i;i++)
    {
        menor = buscarMenor(vec,ce,tam,comparar);
        if(menor!=vec)
        {
            Intercambio(menor,vec,tam);
        }
        vec += tam;
    }
    return vec;
}
void *buscarMenor(void *vec, size_t *ce,size_t tam,cmp comparar)
{
    void *menor = vec;
    size_t i;

    vec +=tam;

    for(i = 1;i < *ce;i++)
    {
        if(comparar(menor,vec)>0)
        {
            menor = vec;
        }
        vec += tam;
    }
    return menor;
}

int Intercambio(void *dest, void *src, size_t tam)
{
    void *aux = malloc(tam);
    if(!aux) return 0;

    memcpy(src,aux,tam);
    memcpy(dest,src,tam);
    memcpy(aux,dest,tam);

    free(aux);
    return 1;
}
int mBsearch(void *vec,void *elem, size_t *ce,size_t tam, cmp comparar)
{
    int medio = ((*ce/2) % 2 == 0)? *ce/2 : *ce/2 + 1;
    int rta;

    void *med = vec + medio*tam;

    while()
    {
        rta = comparar(elem,med);
        if(rta == 0)
        {
            return 1;
        }
        else if(rta >0)
        {
            med += medio*tam

        }else{
            med = vec + tam*medio;
        }
        medio /= 2;
    }
    return 0;
}
void * mBsearch (void * vec, size_t ce, size_t esize, void * clave, int cmp(void*, void*) )
{
    if (ce == 0)
        return NULL;

    void * pFin = vec + (ce - 1) * esize;

    while (vec <= pFin)
    {
        // 1. Calcula el punto medio exacto basado en la distancia actual de los punteros
        size_t elementos = (pFin - vec) / esize;
        void * ppm = vec + (elementos / 2) * esize;

        // 2. Se llama a cmp UNA sola vez y se almacena el resultado
        int comp = cmp(clave, ppm);

        if (comp == 0)
        {
            return ppm; // ¡Encontrado! Retorna de inmediato sin bandera de más
        }
        else if (comp < 0)
        {
            pFin = ppm - esize; // Descartar la mitad derecha
        }
        else
        {
            vec = ppm + esize;  // Descartar la mitad izquierda
        }
    }

    return NULL; // No encontrado
}
