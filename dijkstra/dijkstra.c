#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "../lib/linkedList.h"
#include "../lib/heap.h"
#include "../lib/vector.h"

typedef struct {
    int vertex;
    double dist;
} Gnode;

typedef struct {
    int v1;
    int v2;
    double dist;
} Edge;

Vector *djikstra(char, size_t, List *[]);
Gnode makeNode(int, double);
int compare(const void *, const void *);
void display(Vector *);


int main(void)
{
    size_t vertices, edges;
    scanf("%lu%lu", &vertices, &edges);
    
    List *graph[vertices];
    // Initialize all the vertices of the 
    // vertices of the adjacency list.
    for (size_t i = 0; i < vertices; ++i)
        graph[i] = initList();
        
    for (size_t i = 0; i < edges; ++i) {
        char source, dest;
        double weight;
        scanf(" %c %c%lf", &source, &dest, &weight);
        
        insert(graph[source - 'A'], dest - 'A', weight);
    }
    
    char start = 'A';
    Vector *result = djikstra(start, vertices, graph);
    display(result);
    
    // free the memory occupied by adjacent list
    // and vector
    for (size_t i = 0; i < vertices; ++i)
        destroyList(graph[i]);
        
    destroyV(result);
    return 0;
}


Vector *djikstra(char start, size_t vertices, List *graph[])
{
    // keep track of the visited node
    int *visited = calloc(vertices, sizeof(int));
    // minimum distance from the starting node. initially
    // initialized to infinity.
    double *distance = malloc(vertices * sizeof(double));
    for (size_t i = 0; i < vertices; ++i)
        distance[i] = INFINITY;
    
    distance[start - 'A'] = 0;
    // keep track of parent vertex. initially
    // initialized to -1.
    int *parent = malloc(vertices * sizeof(int));
    for (size_t i = 0; i < vertices; ++i)
        parent[i] = -1;
    
    Vector *heap = initV(vertices, sizeof(Gnode));
    Gnode startNode = makeNode(start - 'A', 0);
    vpush(heap, &startNode, sizeof(startNode));
    
    while (heap->length) {
        Gnode *u = heappop(heap, compare);
        visited[u->vertex] = 1;
        
        NODE *adjnode = graph[u->vertex]->head;
        
        while (adjnode) {
            int v = adjnode->vertex;
            double wt = adjnode->weight;
            adjnode = adjnode->next;
            
            if (visited[v] || wt > distance[v])
                continue;
                
            distance[v] = wt;
            parent[v] = u->vertex;
            // make a node and include it into the heap
            Gnode n = makeNode(v, wt);
            heappush(heap, &n, sizeof(n), compare);
        }
        // free the popped vertex;
        free(u);
    }
    
    Vector *result = initV(0, sizeof(Edge));
    
    for (size_t i = 0; i < vertices; ++i) {
        if (parent[i] != -1) {
            Edge e;
            e.v1 = start - 'A';
            e.v2 = i;
            
            e.dist = 0;
            size_t j = i;
            while (parent[j] != -1) {
                e.dist += distance[j];
                j = parent[j];
            }
            
            vpush(result, &e, sizeof(e));
        }
    }
    
    // free all the allocated memory and return
    free(distance);
    free(visited);
    free(parent);
    destroyV(heap);
    return result;
}


Gnode makeNode(int vertex, double dist)
{
    Gnode n;
    n.vertex = vertex;
    n.dist = dist;
    return n;
}


void display(Vector *result)
{   
    while (result->length) {
        Edge *e = vpop(result);
        
        printf("%c -> %c = %.2f\n", 
            'A' + e->v1, 'A' + e->v2, e->dist);
        
        free(e);
    }
}


int compare(const void *nodeA, const void *nodeB)
{
    return ((Gnode *) nodeB)->dist - ((Gnode *) nodeA)->dist;
}
