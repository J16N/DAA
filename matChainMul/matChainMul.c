#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define  INF  99999

size_t matrixChainOrder(size_t n, size_t [][n], size_t []);
void printOptimal(size_t, size_t, size_t n, size_t [][n]);

int main(void)
{
    size_t total_matrices;
    scanf("%lu", &total_matrices);
    
    // P stores the dimensions of
    // each matrices. If A[i] be any
    // arbitrary matrix then its 
    // dimension is represented in P
    // as P[i-1] x P[i]
    size_t P[total_matrices + 1];
    for (size_t i = 0; i <= total_matrices; ++i)
        scanf("%lu", &P[i]);
    
    // S stores the index of the subsequent
    // split that achieved minimal cost of
    // the multiplication of the matrices
    size_t S[total_matrices][total_matrices];
    for (size_t i = 0; i < total_matrices; ++i) {
        for (size_t j = 0; j < total_matrices; ++j)
            S[i][j] = 0;
    }
    size_t total_ops = matrixChainOrder(total_matrices, S, P);
    
    printOptimal(0, total_matrices - 1, total_matrices, S);
    printf("\nTotal Operations = %lu\n", total_ops);
    return 0;
}


size_t matrixChainOrder(size_t n, size_t S[][n], size_t P[])
{
    // M stores the number of scalar 
    // multiplications needed to compute
    // the matrix. 
    // M[i][j] represents cost for
    // multiplying A[i] through A[j]
    size_t M[n][n];
    // cost for multiplying one matrix
    // is zero
    for (size_t i = 0; i < n; ++i)
        M[i][i] = 0;
        
    for (size_t len = 2; len <= n; ++len) {
        for (size_t i = 0; i < n - len + 1; ++i) {
            size_t j = i + len - 1;
            M[i][j] = INF;
            
            for (size_t k = i; k < j; ++k) {
                int cost = M[i][k] + M[k+1][j] + P[i] * P[k+1] * P[j+1];
                
                if (cost < M[i][j]) {
                    M[i][j] = cost;
                    S[i][j] = k;
                }
            } 
        }
    }
    
    return M[0][n-1];
}


void printOptimal(size_t i, size_t j, size_t n, size_t S[][n])
{
    if (i == j) {
        printf("A%lu", i + 1);
        return;
    }
    
    printf("(");
    printOptimal(i, S[i][j], n, S);
    printOptimal(S[i][j] + 1, j, n, S);
    printf(")");
}
