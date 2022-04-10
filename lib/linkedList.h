#ifndef LIST_H
    #define LIST_H
    
    typedef struct node NODE;
    typedef struct list List;
    
    struct node {
        int data;
        struct node *next;
        struct node *prev;
    };
    
    struct list {
        NODE *head;
        NODE *tail;
        int nodes;
    };
    
    NODE *createNode(int);
    List *initList(void);
    int insert(List *, int);
    int deleteHead(List *);
    int deleteTail(List *);
    int len(List *);
    void destroyList(List *);
#endif
