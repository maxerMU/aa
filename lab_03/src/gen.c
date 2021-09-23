#include "gen.h"

int *gen_best(size_t length)
{
    int *a = malloc(length * sizeof(int));
    if (!a)
        return NULL;
    
    int cur = 10;
    for (size_t i = 0; i < length; ++i)
    {
        a[i] = cur;
        cur += 500;
    }

    return a;
}

int *gen_random(size_t length)
{
    int *a = malloc(length * sizeof(int));
    if (!a)
        return NULL;
    
    for (size_t i = 0; i < length; ++i)
        a[i] = rand() % 1000;
    
    return a;
}

int *gen_worst(size_t length)
{
    int *a = malloc(length * sizeof(int));
    if (!a)
        return NULL;

    int cur = 500 * length;
    for (size_t i = 0; i < length; ++i)
    {
        a[i] = cur;
        cur -= 500;
    }

    return a;
}