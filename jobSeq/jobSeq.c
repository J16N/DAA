#include <stdio.h>
#include <stdlib.h>
#define MIN(a, b) ((a) < (b) ? (a) : (b))


typedef struct {
    int id;
    int deadline;
    float profit;
} Job;


int compare(const void *, const void *);
int JSD(int, Job [], Job *);
void display(int n, Job *);


int main(void)
{
    int n;
    scanf("%d", &n);
    
    Job arr[n];
    for (int i = 0; i < n; ++i) {
        arr[i].id = i + 1;
        scanf("%f%d", &arr[i].profit, &arr[i].deadline);
    }
    
    qsort(arr, n, sizeof(Job), compare);
    
    Job *slot = malloc(n * sizeof(Job));
    int jobs = JSD(n, arr, slot);
    display(jobs, slot);
    
    free(slot);
    return 0;
}


int compare(const void *a, const void *b)
{
    float result = (((Job *)b)->profit) - (((Job *)a)->profit);
    return result > 0 ? 1 : result < 0 ? -1 : 0;
}


int JSD(int n, Job arr[], Job *slot)
{
    int jobs = 0;
    int *sequenced = calloc(n, sizeof(int));
    
    for (int i = 0; i < n; ++i) {
        for (int j = MIN(n - 1, arr[i].deadline) - 1; j >= 0; --j) {
            if (sequenced[j])
                continue;
                
            slot[j] = arr[i];
            sequenced[j] = 1;
            ++jobs;
            break;
        }
    }
    
    return jobs;
}


void display(int n, Job *slot)
{
    while (--n >= 0) {
        printf("ID - %d    PROFIT - %.2f    DEADLINE - %d\n", 
            slot[n].id, slot[n].profit, slot[n].deadline);
    }
}
