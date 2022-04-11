#ifndef HEAP_H
    #define HEAP_H
    #include "./vector.h"
    
    void heapify(int *);
    int heappush(Vector *, int);
    int heappop(Vector *);
    int heappushpop(Vector *, int);
#endif
