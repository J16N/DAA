#include <stdio.h>
#include <stdlib.h>


void DFS(int, int size, int [][size]);
void DFSR(int, int size, int [][size], int *);


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
    
    DFS(0, nodes,relations);
    return 0;
}


void DFS(int v, int size, int relations[][size])
{
    int *visited = calloc(size, sizeof(int));
    DFSR(v, size, relations, visited);
    free(visited);
}


void DFSR(int v, int size, int relations[][size], int *visited)
{
    printf("%c ", 'A' + v);
    visited[v] = 1;
    
    for (size_t i = 0; i < size; ++i) {
        if (relations[v][i] && !visited[i]) {
            DFSR(i, size, relations, visited);
        }
    }
}
