#include "myString.h"

void *my_memchr(const void *s, int c, size_t n);
int my_memcmp(const void *s1, const void *s2, size_t n);
void *my_memcpy(void *s1, const void *s2, size_t n);
void *my_memmove(void *s1, const void *s2, size_t n);
void *my_memset(void *s, int c, size_t n);
char *my_strcat(char*s1, const char *s2);
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
char *my_strncat(char*s1, const char *s2, size_t n);
int my_strncmp(const char *s1, const char *s2, size_t n);
char *my_strncpy(char *s1, const char *s2, size_t n);
char *my_strrchr(char *s, int c);
char *my_strstr(const char *s1, const char *s2);
char *my_strtok(char *s1, const char *s2);
