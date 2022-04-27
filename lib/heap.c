#include <string.h>
#include <stdlib.h>
#include "./heap.h"
#include "./vector.h"

void interchange(size_t, size_t, void *, size_t);


void heapify(void *arr, size_t length, size_t el_size, int (*compare)(const void *, const void *))
{
    for (long i = length / 2 - 1; i >= 0; --i) {
        size_t left = 2 * i + 1;
        size_t right = left + 1;
        size_t maxIdx;
        
        if (right < length)
            maxIdx = (*compare)(arr + left * el_size, arr + right * el_size) > 0 ? left : right;
        else
            maxIdx = left;
          
        if ((*compare)(arr + maxIdx * el_size, arr + i * el_size) > 0)  
            interchange(i, maxIdx, arr, el_size);
    }
}


int heappush(Vector *v, void *data, size_t data_sz, int (*compare)(const void *, const void *))
{
    vpush(v, data, data_sz);
    heapify(v->arr, v->length, v->elem_sz, compare);
}


void *heappop(Vector *v, int (*compare)(const void *, const void *))
{
    interchange(0, v->length - 1, v->arr, v->elem_sz);
    void *data = vpop(v);
    heapify(v->arr, v->length, v->elem_sz, compare);
    return data;
}


void *heappushpop(Vector *v, void *data, int (*compare)(const void *, const void *))
{
    interchange(0, v->length - 1, v->arr, v->elem_sz);
    
    void *temp = malloc(v->elem_sz);
    memcpy(temp, v->arr + (v->length - 1) * v->elem_sz, v->elem_sz);
    memcpy(v->arr + (v->length - 1) * v->elem_sz, data, v->elem_sz);

    heapify(v->arr, v->length, v->elem_sz, compare);
    return temp;
}


void decreaseKey(void *arr, size_t el_size, size_t i, void *value, 
                 void (*decrease)(void *, void *),
                 int (*compare)(const void *, const void *))
{
    void *el = arr + i * el_size;
    decrease(el, value);
    heapify(arr, i + 1, el_size, compare);
}


void interchange(size_t i, size_t j, void *arr, size_t el_size)
{
    void *temp = malloc(el_size);
    
    memcpy(temp, arr + el_size * i, el_size);
    memcpy(arr + el_size * i, arr + el_size * j, el_size);
    memcpy(arr + el_size * j, temp, el_size);
    
    free(temp);
}
