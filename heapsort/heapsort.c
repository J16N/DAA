#include <stdio.h>
#define MAX(a, b) ((arr[a]) > (arr[b]) ? (a) : (b))


void display(int, int[]);
void heapify(int, int []);
void heapSort(int, int []);
void interchange(int, int, int[]);


int main(void)
{
    int size;
    scanf("%d", &size);
    
    int arr[size];
    
    for (size_t i = 0; i < size; ++i)
        scanf("%d", &arr[i]);
    
    heapSort(size, arr);
    display(size, arr);
    return 0;
}


void display(int size, int arr[])
{
    for (size_t i = 0; i < size; ++i)
        printf("%d ", arr[i]);

    printf("\n");
}


void heapify(int size, int arr[])
{
    for (int i = size / 2 - 1; i >= 0; --i) {
        int left = 2 * i + 1;
        int right = left + 1;
        int maxIdx = right < size ? MAX(left, right) : left;
        
        if (arr[i] < arr[maxIdx])
            interchange(i, maxIdx, arr);
    }
}


void heapSort(int size, int arr[])
{
    if (size) {
        heapify(size, arr);
        interchange(0, size - 1, arr);
        heapSort(size - 1, arr);
    }
}


void interchange(int i, int j, int arr[])
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
