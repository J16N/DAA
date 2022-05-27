#include <stdio.h>
#include <stdbool.h>

void mColoring(int, int, int n, int [][n], int[]);
void doColor(int, int, int n, int [][n], int []);

int main(void)
{
    int n, m;
    scanf("%d%d", &n, &m);
    
    int colors[n];
    for (size_t i = 0; i < n; ++i) {
        // 0 indicates no color.
        colors[i] = 0;
    }
    
    int graph[n][n];
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j)
            scanf("%d", &graph[i][j]);
    }
    
    char start = 'A';
    mColoring(start - 'A', m, n, graph, colors);
    
    return 0;
}


// v      - current vertex
// m      - number of colors
// n      - total number of vertex
// graph  - adjacency matrix of n and edges
// colors - array containing the colors of the n 
void doColor(int v, int m, int n, int graph[][n], int colors[])
{   
    while (true) {
        colors[v] = (colors[v] + 1) % (m + 1);
        if (!colors[v]) return;
        
        int j = 0;
        while (j < v) {
            if (graph[v][j] && colors[v] == colors[j])
                break;
            ++j;
        }
        
        if (j == v) return;
    }
}


void mColoring(int v, int m, int n, int graph[][n], int colors[])
{
    static int count;
        
    while (true) {
        doColor(v, m, n, graph, colors);
        if (colors[v] == 0) return;
        
        if (v + 1 == n) {
            // print one of the solutions
            printf("%02d) ", ++count);
            for (size_t i = 0; i < n; ++i)
                printf("%c: %d        ", 'A' + i, colors[i]);
            printf("\n");
        }
        
        mColoring(v + 1, m, n, graph, colors);
    }
}
