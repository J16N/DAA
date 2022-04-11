#ifndef HEAP_H
    #define HEAP_H
    #include <stdbool.h>
    #include "./vector.h"
    
    void heapify(int, int *, bool);
    int heappush(Vector *, int, bool);
    int heappop(Vector *, bool);
    int heappushpop(Vector *, int, bool);
    void decreasekey(int, int *, int, bool);
#endif
