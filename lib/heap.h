#ifndef HEAP_H
    #define HEAP_H
    #include "./vector.h"
    
    void heapify(void *, size_t, size_t, int (*)(const void *, const void *));
    int heappush(Vector *, void *, size_t, int (*)(const void *, const void *));
    void *heappop(Vector *, int (*)(const void *, const void *));
    void *heappushpop(Vector *, void *, int (*)(const void *, const void *));
    void decreaseKey(void *, size_t, size_t, void *, 
                     void (*)(void *, void *), int (*)(const void *, const void *));
#endif
