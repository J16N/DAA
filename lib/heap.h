#ifndef HEAP_H
    #define HEAP_H
    #include "./vector.h"
    
    void heapify(int, int *, bool);
    int heappush(Vector *, int, bool);
    int heappop(Vector *, bool);
    int heappushpop(Vector *, int, bool);
#endif
