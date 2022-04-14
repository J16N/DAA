#include <stdio.h>
#include <stdlib.h>
#include "../lib/vector.h"
#include "../lib/heap.h"


typedef struct {
    int id;
    int deadline;
    float profit;
} Job;


int compare(const void *, const void *);
int compareH(const void *, const void *);
Vector *JSD(int, Job []);
void display(Vector *);


int main(void)
{
    int n;
    scanf("%d", &n);
    
    Job arr[n];
    for (int i = 0; i < n; ++i) {
        arr[i].id = i + 1;
        scanf("%f%d", &arr[i].profit, &arr[i].deadline);
    }
    
    // sort the array of Jobs in a non-decreasing order
    // based on their deadline
    qsort(arr, n, sizeof(Job), compare);
    
    
    Vector *jobs = JSD(n, arr);
    
    display(jobs);
    destroyV(jobs);
    return 0;
}


int compare(const void *a, const void *b)
{
    return ((Job *) b)->deadline - ((Job *) a)->deadline;
}


int compareH(const void *a, const void *b)
{
    return ((Job *) a)->profit - ((Job *) b)->profit;
}


Vector *JSD(int n, Job arr[])
{
    // maximum number of jobs that is sequenced
    int jobs = 0;
    Vector *v = initV(n, sizeof(Job));
    Vector *heap = initV(n, sizeof(Job));
    
    for (int i = 0; i < n; ++i) {
        int slots_available = i + 1 == n ? 
            arr[i].deadline : arr[i].deadline - arr[i + 1].deadline;
        
        // push the job into the heap, taking profit as
        // the priority
        heappush(heap, arr + i, sizeof(Job), compareH);
        
        // while heap is not empty and slots are available
        while (heap->length > 0 && slots_available--) {
            void *job = heappop(heap, compareH);
            vpush(v, job, v->elem_sz);
            free(job);
        }
    }
    
    // Sort the vector in decreasing order of
    // the deadline
    qsort(v->arr, v->length, v->elem_sz, compare);
    destroyV(heap);
    return v;
}


void display(Vector *jobs)
{
    for (size_t i = 0; i < jobs->length * jobs->elem_sz; i += jobs->elem_sz) {
        Job *job = jobs->arr + i;
        printf("ID - %d    PROFIT - %.2f    DEADLINE - %d\n", 
            job->id, job->profit, job->deadline);
    }
}
