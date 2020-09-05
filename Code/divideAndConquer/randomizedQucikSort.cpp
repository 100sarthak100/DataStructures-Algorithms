// Using random pivoting we improve the expected or average time 
// complexity to O (N log N). 
// The Worst Case complexity is still O ( N^2 ).
// random pivoting using Lomuto Partitioning
#include <bits/stdc++.h>
using namespace std;

void swap(int* a, int * b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int l, int h)
{
    int pivot = arr[h];
    int i = l - 1;
    for(int j=l; j<=h-1; j++)
    {
        if(arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1], &arr[h]);
    return (i+1);
}

int partitionUtil(int arr[], int l, int h)
{
    srand(time(NULL));
    // genertate random number btw low and high
    int random = l + rand()%(h - l);
    swap(&arr[random], &arr[h]);
    return partition(arr, l, h);
}

void quickSort(int arr[], int l, int h)
{
    if(l < h)
    {
        int p = partitionUtil(arr, l, h);
        quickSort(arr, l, p-1);
        quickSort(arr, p+1, h);
    }
}

void printArray(int arr[], int n)
{
    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";
}

int main()
{
    int arr[] = { 10, 7, 8, 9, 1, 5 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    quickSort(arr, 0, n - 1);
    printArray(arr, n);
    return 0; 
}