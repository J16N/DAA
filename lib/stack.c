#include "./linkedList.h"

typedef List Stack;


Stack *initStack(void)
{
    return initList();
}


int push(Stack *s, int data)
{
    return insert(s, data);
}


int pop(Stack *s)
{
    return deleteHead(s);
}


void destroyStack(Stack *s)
{
    return destroyList(s);
}
