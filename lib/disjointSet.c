#include <stdlib.h>
#include "./disjointSet.h"


DJS *initDJS(size_t length)
{
    DJS *djs = malloc(sizeof(DJS));
    djs->length = length;
    djs->arr = malloc(length * sizeof(int));
    
    for (size_t i = 0; i < length; ++i)
        djs->arr[i] = -1;
        
    return djs;
}


size_t unionDJS(size_t i, size_t j, DJS *djs)
{
    if (i >= djs->length || j >= djs->length)
        return -1;
    
    i = findDJS(i, djs);
    j = findDJS(j, djs);
    int count = djs->arr[i] + djs->arr[j];
    
    if (djs->arr[i] <= djs->arr[j]) {
        djs->arr[j] = i;
        djs->arr[i] = count;
    }
    else {
        djs->arr[i] = j;
        djs->arr[j] = count;
    }
    
    return 0;
}


int findDJS(size_t i, DJS *djs)
{
    if (i >= djs->length)
        return -1;
    
    int r = i;
    
    while (djs->arr[r] > 0)
        r = djs->arr[r];
        
    while (i != r) {
        int temp = djs->arr[i];
        djs->arr[i] = r;
        i = temp;
    }
    
    return r;
}


void destroyDJS(DJS *djs)
{
    free(djs->arr);
    free(djs);
}
