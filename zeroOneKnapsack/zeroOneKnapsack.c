#include <stdio.h>
#include <stdlib.h>
#define MAX(a, b) ((a) > (b) ? (a) : (b))

typedef struct {
    double profit;
    double weight;
} Item;

double **knapsack(size_t, size_t, Item []);
void printItems(size_t, size_t, Item [], double **);

int main(void)
{
    // n: number of items
    // m: knapsack size
    size_t n, m;
    scanf("%lu%lu", &n, &m);
    
    // Bag is an array of `Item`
    // of size n
    Item bag[n];
    for (size_t i = 0; i < n; ++i) {
        double profit, weight;
        scanf("%lf%lf", &profit, &weight);
        
        bag[i].profit = profit;
        bag[i].weight = weight;
    }
    
    double **dp = knapsack(n, m, bag);
    printItems(n, m, bag, dp);
    
    // free dp table
    for (size_t i = 0; i <= n; ++i)
        free(dp[i]);
    free(dp);
    return 0;
}


double **knapsack(size_t n, size_t m, Item bag[])
{
    // Create dp table having `m + 1` columns and
    // `n` rows. The column represents the size 
    // of knapsack and the row represent the items.
    //
    // Initialize all the values in 2D array to 0.
    double **dp = malloc((n + 1) * sizeof(double *));
    for (size_t i = 0; i <= n; ++i)
        dp[i] = calloc((m + 1), sizeof(double));
        
    for (size_t i = 1; i <= n; ++i) {
        double weight = bag[i - 1].weight;
        double profit = bag[i - 1].profit;
        
        for (size_t j = 1; j <= m; ++j) {
            // If the weight of the item is greater than the
            // knapsack size then set the current profit of
            // knapsack to the profit obtained of the same 
            // knapsack while considering the previous item.
            //
            // Else set the maximum of the above obtained profit
            // and the profit obtained by considering the item
            // taken inside knapsack + the profit of the remaining 
            // weight of the knapsack considering the previous item.
            dp[i][j] = weight > j ? 
                dp[i - 1][j] : 
                MAX(dp[i - 1][j], profit + dp[i - 1][(size_t) (j - weight)]);
        }
    }
    
    return dp;
}


void printItems(size_t n, size_t m, Item bag[], double **dp)
{
    double knapsackSize = m;
    double totalProfit = dp[n][m];
    
    for (size_t i = n; i > 0 && totalProfit > 0; --i) {
        // If the total profit is not equal to the profit
        // obtained while considering the previous item at
        // same knapsack capacity, then the current item
        // is taken inside the knapsack.
        if (totalProfit != dp[i - 1][(size_t) knapsackSize]) {
            double profit = bag[i - 1].profit;
            double weight = bag[i - 1].weight;
            
            printf("Item-%lu\tProfit: %.2f\tWeight: %.2f\n", 
                    i, profit, weight);
                    
            // Update the knapsack size and the total
            // profit left after including the item
            // inside knapsack.
            knapsackSize -= weight;
            totalProfit -= profit;
        }
    }
    
    printf("\nTotal Profit: %.2f\n", dp[n][m]);
}
