#include <stdio.h>
#include <stdlib.h>
#include "../lib/vector.h"
#include "../lib/disjointSet.h"

typedef struct {
    int v1;
    int v2;
    int weight;
} Edge;

int compare(const void *, const void *);
Vector *kruskal(size_t, Vector *);
void display(Vector *);


int main(void)
{
    size_t vertices;
    scanf("%lu", &vertices);
    
    // This array keeps track of the
    // edge between two vertices that
    // is already taken.
    int visitedEdges[vertices][vertices];
    
    // Initialize all the elements in this
    // matrix to 0. That is no edges are taken.
    for (size_t i = 0; i < vertices; ++i)
        for (size_t j = 0; j < vertices; ++j)
            visitedEdges[i][j] = 0;
    
    // Initialize empty vector that will hold
    // all the edges between vertices and their 
    // corresponding weight.
    Vector *graph = initV(0, sizeof(Edge));
    
    // read the graph from stdin
    for (size_t i = 0; i < vertices; ++i) {
        for (size_t j = 0; j < vertices; ++j) {
            int weight;
            scanf("%d", &weight);
            
            // if weight not equals zero
            if (weight && visitedEdges[i][j] == 0) {
                Edge *e = malloc(sizeof(Edge));
                e->v1 = i;
                e->v2 = j;
                e->weight = weight;
                
                // push the edge to the vector
                vpush(graph, e, sizeof(Edge));
                
                // We have already taken the edge between
                // the two vertices. So we updated corresponding
                // entries in our `visitedEdges`.
                visitedEdges[i][j] = 1;
                visitedEdges[j][i] = 1;
            }
        }
    }
    
    Vector *result = kruskal(vertices, graph);
    display(result);
    
    destroyV(result);
    destroyV(graph);
    return 0;
}


int compare(const void *a, const void *b)
{
    return ((Edge *) b)->weight - ((Edge *) a)->weight;
}


Vector *kruskal(size_t vertices, Vector *graph)
{
    Vector *result = initV(0, sizeof(Edge));
    DJS *dset = initDJS(vertices);
    // Generally in Kruskal algorithm we sort all the
    // edges in non-decreasing order by their weight.
    // But here we will sort all the edges in non-
    // increasing order because we are going to pop
    // each edge from the back of the graph.
    qsort(graph->arr, graph->length, graph->elem_sz, compare);
    
    while (graph->length) {
        Edge *e = vpop(graph);
        
        if (findDJS(e->v1, dset) != findDJS(e->v2, dset)) {
            vpush(result, e, sizeof(Edge));
            unionDJS(e->v1, e->v2, dset);
        }
    }
    
    destroyDJS(dset);
    return result;
}


void display(Vector *result)
{
    int total_wt = 0;
    
    while (result->length) {
        Edge *e = vpop(result);
        
        printf("%c <-> %c = %d\n", 
            'A' + e->v1, 'A' + e->v2, e->weight);
        
        total_wt += e->weight;
    }
    
    printf("\nTotal Weight = %d\n", total_wt);
}
