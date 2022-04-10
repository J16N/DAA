#include <stdio.h>
#include <stdlib.h>

typedef struct {
    float profit;
    float weight;
    float ppw; // profit per unit weight;
} Item;

int compare(const void *, const void *);
float fracKnapsack(int, Item [], int);

int main(void)
{
    int n, k_size;
    scanf("%d%d", &n, &k_size);
    
    // `arr` holds the items having a
    // definite profit and weight
    Item arr[n];
    
    // Get the profits
    for (int i = 0; i < n; ++i)
        scanf("%f", &arr[i].profit);
        
    // Get the weights and calculate
    // profit per unit weight at the same time
    for (int i = 0; i < n; ++i) {
        scanf("%f", &arr[i].weight);
        arr[i].ppw = arr[i].profit / arr[i].weight;
    }
    
    // sort the array in non-decreasing order
    qsort(arr, n, sizeof(Item), compare);
    printf("%.2f\n", fracKnapsack(n, arr, k_size));
    return 0;
}

int compare(const void *a, const void *b)
{
    float result = (((Item *)b)->ppw) - (((Item *)a)->ppw);
    return result > 0 ? 1 : result < 0 ? -1 : 0;
}

float fracKnapsack(int n, Item arr[n], int k_size)
{
    float maxProfit = 0;
    
    for (int i = 0; i < n; ++i) {
        if (arr[i].weight > k_size) {
            maxProfit += (arr[i].profit * k_size / arr[i].weight);
            break;
        }
        maxProfit += arr[i].profit;
        k_size -= arr[i].weight;
    }
    
    return maxProfit;
}
