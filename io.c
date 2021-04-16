#include <stdio.h>
#include "io.h"
char * request(const char * value)
{
    char * ret;
    printf(value);
    scanf("%s",&ret);
    printf("\n");
    return ret;
}
int request_int(const char * value)
{
    int ret;
    printf(value);
    scanf("%d",&ret);
    printf("\n");
    return ret;
}
float request_float(const char * value)
{
    float ret;
    printf(value);
    scanf("%f",&ret);
    printf("\n");
    return ret;
}