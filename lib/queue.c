#include <stdbool.h>
#include "./linkedList.h"
#include "./queue.h"


Queue *initQueue(void)
{
    return initList();
}


int enque(Queue *q, int data)
{
    return insert(q, data);
}


int deque(Queue *q)
{
    return deleteTail(q);
}


bool isEmpty(Queue *q)
{
    return len(q) == 0;
}


void destroyQ(Queue *q)
{
    return destroyList(q);
}
