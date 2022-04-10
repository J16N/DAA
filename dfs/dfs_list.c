#include <stdio.h>
#include <stdlib.h>
#include "../lib/linkedList.h"


void DFS(int, int size, List * [size]);
void DFSR(int, int size, List * [size], int *);


int main(void)
{
    int nodes;
    scanf("%d", &nodes);
    
    List *relations[nodes];
    for (size_t i = 0; i < nodes; ++i) {
        relations[i] = initList();
        
        for (size_t j = 0; j < nodes; ++j) {
            int relation;
            scanf("%d", &relation);
            
            if (relation)
                insert(relations[i], j);
        }
    }
    
    DFS(0, nodes,relations);
    
    for (size_t i = 0; i < nodes; ++i) {
        destroyList(relations[i]);
    }
    
    return 0;
}


void DFS(int v, int size, List *relations[size])
{
    int *visited = calloc(size, sizeof(int));
    DFSR(v, size, relations, visited);
    free(visited);
}


void DFSR(int v, int size, List *relations[size], int *visited)
{
    printf("%c ", 'A' + v);
    visited[v] = 1;
    
    NODE *curr = relations[v]->head;
    
    while (curr) {
        if (!visited[curr->data])
            DFSR(curr->data, size, relations, visited);
        
        curr = curr->next;
    }
}
