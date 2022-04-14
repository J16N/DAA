#ifndef DISJOINTSET_H
    #define DISJOINTSET_H
    
    typedef struct {
        size_t length;
        int *arr;
    } DJS;
    
    DJS *initDJS(size_t);
    size_t unionDJS(size_t, size_t, DJS *);
    int findDJS(size_t, DJS *);
    void destroyDJS(DJS *);
#endif
