#include <stdlib.h>
#include <string.h>
#include "./vector.h"


Vector *initV(size_t size, size_t elem_sz)
{
    Vector *v = malloc(sizeof(Vector));
    v->size = size;
    v->length = 0;
    v->elem_sz = elem_sz;
    v->arr = malloc(size * elem_sz);
    return v;
}


int vpush(Vector *v, void *data, size_t data_sz)
{
    if (data_sz != v->elem_sz)
        return -1;
    
    if (v->length == v->size) {
        v->size = 2 * v->size + 1;
        v->arr = realloc(v->arr, v->size * v->elem_sz);
        
        if (v->arr == NULL)
            return -1;
    }
    
    memcpy(v->arr + v->length * v->elem_sz, data, v->elem_sz);
    v->length++;
    return 0;
}


void *vpop(Vector *v)
{
    if (!v->length)
        return NULL;
    
    v->length--;
    void *data = malloc(v->elem_sz);
    memcpy(data, v->arr + v->length * v->elem_sz, v->elem_sz);
    
    if (2 * v->length == v->size - 1) {
        v->size = v->length;
        v->arr = realloc(v->arr, v->size * v->elem_sz);
    }
    
    return data;
}


void destroyV(Vector *v)
{
    free(v->arr);
    free(v);
}
