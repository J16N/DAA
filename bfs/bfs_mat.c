#include <stdio.h>
#include <stdlib.h>
#include "../lib/queue.h"


void BFS(int, int size, int [][size]);


int main(void)
{
    int nodes;
    scanf("%d", &nodes);
    
    int relations[nodes][nodes];
    
    for (size_t i = 0; i < nodes; ++i) {
        for (size_t j = 0; j < nodes; ++j) {
            scanf("%d", &relations[i][j]);
        }
    }
       
    BFS(0, nodes, relations);
    return 0;
}


void BFS(int v, int size, int relations[][size])
{
    int *visited = calloc(size, sizeof(int));
    Queue *q = initQueue();
    enque(q, v);
    visited[v] = 1;
    
    while (!isEmpty(q)) {
        int node = deque(q);
        printf("%c ", 'A' + node);
        
        for (size_t i = 0; i < size; ++i) {
            if (relations[node][i] && !visited[i]) {
                enque(q, i);
                visited[i] = 1;
            }
        }
    }
    
    destroyQ(q);
    free(visited);
}
