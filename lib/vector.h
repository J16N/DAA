#ifndef VECTOR_H
    #define VECTOR_H
    
    typedef struct {
        size_t size;
        size_t length;
        size_t elem_sz;
        void *arr;
    } Vector;
    
    Vector *initV(size_t, size_t);
    int vpush(Vector *, void *, size_t);
    void *vpop(Vector *);
    void destroyV(Vector *);
#endif
