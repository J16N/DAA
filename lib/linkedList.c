#include <stdlib.h>
#include "./linkedList.h"


NODE *createNode(int v, double wt)
{
    NODE *temp = malloc(sizeof(NODE));
    
    if (temp != NULL) {
        temp->vertex = v;
        temp->weight = wt;
        temp->next = NULL;
        temp->prev = NULL;
    }
    
    return temp;
}


List *initList()
{
    List *list = malloc(sizeof(List));
    
    if (list != NULL) {
        list->head = NULL;
        list->tail = NULL;
        list->nodes = 0;
    }
    
    return list;
}


int insert(List *list, int v, double wt) {
    if (list == NULL) return -1;
    
    NODE *temp = createNode(v, wt);
    if (temp == NULL) return -1;
    
    if (list->nodes > 0) {
        temp->prev = list->tail;
        list->tail->next = temp;
        list->tail = temp;
    } else {
        list->head = temp;
        list->tail = temp;
    }
    
    (list->nodes)++;
    return 0;
}


int deleteHead(List *list)
{
    if (list == NULL || list->nodes == 0) return -1;
    
    NODE *temp = list->head;
    list->head = list->head->next;
    
    if (list->head)
        list->head->prev = NULL;
    else
        list->tail = NULL;
        
    (list->nodes)--;
    
    int data = temp->vertex;
    free(temp);
    return data;
}


int deleteTail(List *list)
{
    if (list == NULL || list->nodes == 0) return -1;
    
    NODE *temp = list->tail;
    list->tail = list->tail->prev;
    
    if (list->tail)
        list->tail->next = NULL;
    else
        list->head = NULL;
    
    (list->nodes)--;
    
    int data = temp->vertex;
    free(temp);
    return data;
}


int len(List *list)
{
    return list->nodes;
}


void destroyList(List *list)
{
    while (list->head) {
        deleteHead(list);
    }
    
    free(list);
}
