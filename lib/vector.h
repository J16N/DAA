#ifndef VECTOR_H
    #define VECTOR_H
    
    typedef struct {
        size_t size;
        size_t length;
        int arr[];
    } Vector;
    
    Vector *initV(void);
    int vpush(Vector *, int);
    int vpop(Vector *);
    void destroyV(Vector *);
#endif
