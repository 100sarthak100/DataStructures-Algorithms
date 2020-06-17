// it is a divide & conquer algorithm
// It picks an element as pivot and partitions the given array around the picked 
// pivot. There are many different versions of quickSort that pick pivot in different 
// ways.

// Always pick first element as pivot.
// Always pick last element as pivot (implemented below)
// Pick a random element as pivot.
// Pick median as pivot.

// The key process in quickSort is partition(). Target of partitions is, given an 
// array and an element x of array as pivot, put x at its correct position in sorted 
// array and put all smaller elements (smaller than x) before x, and put all greater 
// elements (greater than x) after x. All this should be done in linear time.

// recursive 
// time -> T(n) = T(k) + T(n-k-1) + \theta(n)
// T(k) and T(n - k - 1) for two recurssive calls
// theta(n) is for partition process
// k is the number of element which are smaller than pivot

// worst case -> algo picks smallest or largest element as pivot theta(n^2);
// best case -> algo picks middle elements as pivot; theta(nlogn);
// avergae case -> O(nlogn);

// Is QuickSort stable?
// The default implementation is not stable. However any sorting algorithm can be 
// made stable by considering indexes as comparison parameter.
// Is QuickSort In-place?
// As per the broad definition of in-place algorithm it qualifies as an in-place 
// sorting algorithm as it uses extra space only for storing recursive 
// function calls but not for manipulating the input.

// for arrays quick sort
// Quick Sort in its general form is an in-place sort (i.e. it doesn’t require any 
// extra storage) whereas merge sort requires 
// O(N) extra storage, N denoting the array size which may be quite expensive.

// for linked list merge sort
// In linked list, we can insert items in the middle in O(1) extra space and O(1) time. 
// Therefore merge operation of merge sort can be implemented 
// without extra space for linked lists.

//  QuickSort using Lomuto partition scheme
#include <bits/stdc++.h>
using namespace std;

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for(int j = low; j<=high -1; j++)
    {
        if(arr[j] < pivot)
        {
            i++;
            swap(&arr[j], &arr[i]);
        }
    }
    swap(&arr[i+1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if(low < high)
    {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printArray(int arr[], int n)
{
    for(int i = 0; i<n ; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

int main()
{
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    quickSort(arr, 0, n-1);
    cout<<"Sorted array: \n";
    printArray(arr, n);
    return 0;
}

// Hoare’s Partition Scheme
