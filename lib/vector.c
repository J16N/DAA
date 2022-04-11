#include <stdlib.h>
#include "./vector.h"


Vector *initV(void)
{
    Vector *v = malloc(sizeof(Vector));
    v->size = 0;
    v->length = 0;
    v->arr = NULL;
    return v;
}


int vpush(Vector *v, int data)
{
    if (v->length == v->size) {
        v->size = 2 * v->size + 1;
        v->arr = malloc(v->size * sizeof(int));
        
        if (v->arr == NULL)
            return -1;
    }
    
    v->arr[v->length++] = data;
    return 0;
}


int vpop(Vector *v)
{
    int data = v->arr[--(v->length)];
    
    if (2 * v->length == v->size - 1) {
        v->size = v->length;
        v->arr = malloc(v->size * sizeof(int));
        
        if (v->arr == NULL)
            return -1;
    }
    
    return data;
}


void destroyV(Vector *v)
{
    free(v->arr);
    free(v);
}
