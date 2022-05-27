#include <stdio.h>
#include <stdbool.h>
#define  abs(n) ((n) >= 0 ? (n) : -(n))

// example of 4x4 board
//
//      0    1    2    3
//
// 0   0,0  0,1  0,2  0,3
// 1   1,0  1,1  1,2  1,3
// 2   2,0  2,1  2,2  2,3
// 3   3,0  3,1  3,2  3,3

void nQueenUtil(size_t);
void display(size_t n, bool [][n]);
void nQueen(size_t, size_t n, bool [][n], bool [], 
            bool [], bool [], size_t *);

int main(void)
{
    // no. of test case
    int t;
    scanf("%d", &t);
    
    while (t--) {
        // board size n x n
        size_t n;
        scanf("%lu", &n);
        
        printf("\tFOR N = %lu\n", n);
        nQueenUtil(n);
        printf("\n");
    }
    
    return 0;
}

void nQueenUtil(size_t n)
{
    // columns and diagonal bit arrays
    // to store the attacking positions
    bool columns[n];
    // leftDiagonal elements are those where
    // the difference of the coordinates of every
    // element is constant
    // rightDiagonal elements are those where
    // the sum of the coordinates of every element
    // is constant
    bool leftDiagonals[n], rightDiagonals[2 * n - 1];
    
    // intiialize the columns array and leftDiagonal to false
    for (size_t i = 0; i < n; ++i) {
        columns[i] = false;
        leftDiagonals[i] = false;
    }
    // initialize the diagonals array to false
    for (size_t i = 0; i < 2 * n - 1; ++i)
        rightDiagonals[i] = false;
        
    // initialize the n x n chess board
    bool board[n][n];
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j)
            board[i][j] = false;
    }
    
    // number of solutions
    size_t solution = 0;
    nQueen(0, n, board, columns, leftDiagonals, rightDiagonals, &solution);
    
    if (!solution)
        printf("Solution does not exist.\n\n\n");
}


void display(size_t n, bool board[][n])
{
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j)
            printf("%c ", board[i][j] ? 'Q' : '-');
        printf("\n");
    }
}


void nQueen(size_t k, size_t n, bool board[][n], bool columns[], 
            bool leftDiagonals[], bool rightDiagonals[], size_t *sols)
{    
    if (k == n) {
        printf("Solution-%02lu\n", ++(*sols));
        display(n, board);
        printf("\n\n");
        fflush(stdout);
    }
    
    for (size_t col = 0; col < n; ++col) {
        // if the queen is in same column or in same diagonals then
        // continue the loop.        
        if (columns[col] || rightDiagonals[k+col] || leftDiagonals[abs(k-col)]) {
            continue;
        }
        
        // place the queen and set the corresponding
        // columns and diagonals
        board[k][col] = true;
        columns[col] = true;
        rightDiagonals[k + col] = true;
        leftDiagonals[abs(k - col)] = true;
        
        nQueen(k + 1, n, board, columns, leftDiagonals, rightDiagonals, sols);
        
        // pick up the queen and try different position.
        // unset column and diagonal entries.
        board[k][col] = false;
        columns[col] = false;
        rightDiagonals[k + col] = false;
        leftDiagonals[abs(k - col)] = false;
    }
}
