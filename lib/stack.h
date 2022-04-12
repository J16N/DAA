#ifndef STACK_H
    #define STACK_H
    
    typedef List Stack;
    
    Stack *initStack(void);
    int push(Stack *, int);
    int pop(Stack *);
    void destroyStack(Stack *);
#endif
