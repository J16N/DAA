#include <stdio.h>
#include <stdlib.h>
#include "../lib/linkedList.h"
#include "../lib/queue.h"


void BFS(int, int size, List * [size]);


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
    
    BFS(0, nodes, relations);
    
    for (size_t i = 0; i < nodes; ++i) {
        destroyList(relations[i]);
    }
    
    return 0;
}


void BFS(int v, int size, List *relations[size])
{
    int *visited = calloc(size, sizeof(int));
    Queue *q = initQueue();
    enque(q, v);
    visited[v] = 1;
    
    while (!isEmpty(q)) {
        int node = deque(q);
        printf("%c ", 'A' + node);
        
        NODE *curr = relations[node]->head;
        
        while (curr) {
            if (!visited[curr->data]) {
                enque(q, curr->data);
                visited[curr->data] = 1;
            }
            curr = curr->next;
        }
    }
    
    destroyQ(q);
    free(visited);
}
