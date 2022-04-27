#ifndef LIST_H
    #define LIST_H
    
    typedef struct node NODE;
    typedef struct list List;
    
    struct node {
        int vertex;
        double weight;
        struct node *next;
        struct node *prev;
    };
    
    struct list {
        NODE *head;
        NODE *tail;
        int nodes;
    };
    
    List *initList(void);
    int insert(List *, int, double);
    int deleteHead(List *);
    int deleteTail(List *);
    int len(List *);
    void destroyList(List *);
#endif
