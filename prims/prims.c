#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../lib/heap.h"
#include "../lib/vector.h"
#include "../lib/linkedList.h"

typedef struct {
    int vertex;
    double weight;
} GraphNode;

typedef struct {
    int v1;
    int v2;
    double weight;
} Edge;

Vector *prims(char, size_t, List * []);
GraphNode makeNode(int, double);
int compare(const void *, const void *);
void display(Vector *);


int main(void)
{
    size_t vertices;
    scanf("%ld", &vertices);
    
    List *graph[vertices];
    
    for (size_t i = 0; i < vertices; ++i) {
        graph[i] = initList();
        
        for (size_t j = 0; j < vertices; ++j) {
            double weight;
            scanf("%lf", &weight);
            
            // Ignore self loops and zero weights
            // Zero weights usually means there is
            // no Vertexs between two vertices.
            if (!weight || i == j) continue;
            
            insert(graph[i], j, weight);
        }
    }
    
    char start = 'A';
    Vector *result = prims(start, vertices, graph);
    display(result);
    
    // free the memory occupied by adjacent list
    // and vector
    for (size_t i = 0; i < vertices; ++i)
        destroyList(graph[i]);
        
    destroyV(result);
    return 0;
}


Vector *prims(char start, size_t vertices, List *graph[vertices])
{
    // Store if the vertex is already visited
    int *visited = calloc(vertices, sizeof(int));
    // Store the parent of each vertex. Initialize 
    // to  -1.
    int *parent = calloc(vertices, sizeof(int));
    for (size_t i = 0; i < vertices; ++i)
        parent[i] = -1;
    // Store the weight of each vertex
    double *weights = malloc(vertices * sizeof(double));
    
    for (size_t i = 0; i < vertices; ++i)
        weights[i] = INFINITY;
        
    weights[start - 'A'] = 0;
    
    // Initialize our heap
    Vector *heap = initV(vertices, sizeof(GraphNode));
    // Initialize our starting vertex
    GraphNode startnode = makeNode(start - 'A', 0);
    // insert this GraphNode 
    vpush(heap, &startnode, sizeof(startnode));
    
    while (heap->length > 0) {
        // get the minimum node
        GraphNode *u = heappop(heap, compare);
        visited[u->vertex] = 1;
        NODE *adjnode = graph[u->vertex]->head;
        
        while (adjnode) {
            int v = adjnode->vertex;
            double wt = adjnode->weight;
            adjnode = adjnode->next;
            
            if (visited[v] || wt > weights[v])
                continue;
                
            weights[v] = wt;
            parent[v] = u->vertex;
            // make a node and include it into the heap
            GraphNode n = makeNode(v, wt);
            heappush(heap, &n, sizeof(n), compare);
        }
        // free the popped vertex;
        free(u);
    }
    
    Vector *result = initV(0, sizeof(Edge));
    
    for (size_t i = 0; i < vertices; ++i) {
        if (parent[i] != -1) {
            Edge e;
            e.v1 = parent[i];
            e.v2 = i;
            e.weight = weights[i];
            vpush(result, &e, sizeof(e));
        }
    }
    
    // free all the allocated memory and return
    free(weights);
    free(visited);
    free(parent);
    destroyV(heap);
    return result;
}


GraphNode makeNode(int vertex, double weight)
{
    GraphNode n;
    n.vertex = vertex;
    n.weight = weight;
    return n;
}


void display(Vector *result)
{
    double total_wt = 0;
    
    while (result->length) {
        Edge *e = vpop(result);
        
        printf("%c <-> %c = %.2f\n", 
            'A' + e->v1, 'A' + e->v2, e->weight);
        
        total_wt += e->weight;
    }
    
    printf("\nTotal Weight = %.2f\n", total_wt);
}


int compare(const void *nodeA, const void *nodeB)
{
    return ((GraphNode *) nodeB)->weight - ((GraphNode *) nodeA)->weight;
}
