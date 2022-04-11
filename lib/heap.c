#include "./heap.h"
#include "./vector.h"
#define MAX(a, b, arr) ((arr[(a)]) > (arr[(b)]) ? (a) : (b))
#define MIN(a, b, arr) ((arr[(a)]) > (arr[(b)]) ? (b) : (a))


void heapify(size_t length, int *arr, bool flag)
{
    for (size_t i = length / 2 - 1; i >= 0; --i) {
        size_t left = 2 * i + 1;
        size_t right = left + 1;
        
        // if right node exists
        //   if the flag is set
        //     find the maximum of left and right
        //   else
        //     find the minimum of left and right
        // else
        //   set `idx` to only left
        size_t idx = right < length ? 
            flag ? MAX(left, right, arr) : 
            MIN(left, right, arr) : left;
        
        if (flag && arr[i] < arr[idx])
            interchange(i, idx, arr);
            
        if (!flag && arr[i] > arr[idx])
            interchange(i, idx, arr);
    }
}


int heappush(Vector *v, int data, bool flag)
{
    vpush(v, data);
    heapify(v->length, v->arr, flag);
}


int heappop(Vector *v, bool flag)
{
    interchange(0, v->length - 1, v->arr);
    int data = vpop(v);
    heapify(v->length, v->arr, flag);
    return data;
}


int heappushpop(Vector *v, int data, bool flag)
{
    interchange(0, v->length - 1, v->arr);
    int temp = v->arr[v->length - 1];
    v->arr[v->length - 1] = data;
    heapify(v->length, v->arr, flag);
    return temp;
}


void decreasekey(size_t length, int *arr, int value, bool flag)
{
    int idx = searchkey(length, arr, value);
    
    if (idx >= 0) {
        interchange(idx, length - 1, arr);
        heapify(length, arr, flag);
    }
}


void interchange(int i, int j, int *arr)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}


int searchkey(size_t length, int *arr, int value)
{
    for (int i = 0; i < length / 2; ++i) {
        int left = 2 * i + 1;
        int right = left + 1;
        
        if (arr[left] == value)
            return left;
            
        if (arr[right] == value)
            return right;
    }
    
    return arr[0] == value ? 0 : -1;
}
