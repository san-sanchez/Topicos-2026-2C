#include "myString.h"

void *my_memchr(const void *s, int c, size_t n);
int my_memcmp(const void *s1, const void *s2, size_t n);
void *my_memcpy(void *s1, const void *s2, size_t n);
void *my_memmove(void *s1, const void *s2, size_t n);
void *my_memset(void *s, int c, size_t n);
char *my_strcat(char*s1, const char *s2)
{
    char *aux = s1;
    while(*s1) s1++;
    while(*s2)
    {
        *s1=*s2;
        s1++;
        s2++;
    }
    *s1='\0';
    return aux;
}
char *my_strchr(char *s, int c)
{
    while(*s++ && *s !=(char)c)
    return *s == (char)c ? s : NULL ;
}
int my_strcmp(const char *s1, const char *s2)
{
    while(*s1 !='\0' && *s1++ == *s2++);
    return (unsigned char)*s1 - (unsigned char)*s2;
}
char *my_strcpy(char *s1, const char *s2)
{
    char *aux =s1;
    while(*s2++) *s1=*s2;
    s1++;
    *s1='\0';
    return aux;
}
size_t my_strlen(const char *s)
{
    size_t cant=0;
    while(*s++) cant++;
    return ++cant;
}
char *my_strncat(char*s1, const char *s2, size_t n)
{
    char *aux = s1;
    while(*s1) s1++;
    while(*s2 && n--)
    {
        *s1=*s2;
        s1++;
        s2++;
    }
    *s1='\0';
    return aux;
}
int my_strncmp(const char *s1, const char *s2, size_t n)
{
    while(*s1 && (*s1++==*s2++) && n--);
    return (unsigned char)*s1 - (unsigned char)*s2;
}
char *my_strncpy(char *s1, const char *s2, size_t n)
{
    char *aux=*s1;
    while(*s2++ && n--) *s1=*s2;
    return aux;
}
char *my_strrchr(char *s, int c)
{
    char *ini= s;
    while(*s) s++;
    while(s > ini && *s!=(char)c) s--;
    return *s==(char)c? s : NULL;
}
char *my_strstr(const char *s1, const char *s2)
{
    char *ptr;
    char *reset = s2;
    while(*s1++)
    {
        if(*s1==*s2)
        {
            ptr = s1;
           while(*s2 && (*s1==*s2))
           {
               s2++;
               s1++;
               if(*s2=='\0')
               {
                   return ptr;
               }
           }
        }
        s2=reset;
    }
    return NULL;
}
char *my_strstrV2(const char *s1, const char *s2)
{
    unsigned tam = my_strlen(s2);
    while(*s1 && my_strncmp(s1,s2,tam)) s1++;
    return *s1? (char*)s1:NULL;
}
char *my_strtok(char *s1, const char *s2);
