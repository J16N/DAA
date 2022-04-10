#ifndef STACK_H
    #define STACK_H
    
    typedef List Stack;
    
    Stack *initQueue(void);
    int push(Stack *, int);
    int pop(Stack *);
    void destroyStack(Stack *);
#endif
