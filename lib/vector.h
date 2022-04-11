#ifndef VECTOR_H
    #define VECTOR_H
    
    typedef struct {
        size_t size;
        size_t length;
        int arr[];
    } Vector;
    
    Vector *initV(size_t);
    int vpush(Vector *, int);
    int vpop(Vector *);
    void destroyV(Vector *);
#endif
