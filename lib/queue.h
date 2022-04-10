#ifndef QUEUE_H
    #define QUEUE_H
    #include <stdbool.h>
    #include "./linkedList.h"
    
    typedef List Queue;
    
    Queue *initQueue(void);
    int enque(Queue *, int);
    int deque(Queue *);
    bool isEmpty(Queue *);
    void destroyQ(Queue *);
#endif
