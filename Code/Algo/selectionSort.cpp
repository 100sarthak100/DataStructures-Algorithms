// The selection sort algorithm sorts an array by repeatedly finding 
// the minimum element (considering ascending order) from unsorted 
// part and putting it at the beginning.

// Time Complexity: O(n^2) as there are two nested loops.

// Auxiliary Space: O(1)
// The good thing about selection sort is it never makes more than 
// O(n) swaps and can 
// be useful when memory write is a costly operation.

// Stability : The default implementation is not stable. However 
// it can be made stable. 

// In Place : Yes, it does not require extra space.

#include <bits/stdc++.h>
using namespace std;

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selection(int arr[], int n)
{
    for(int i=0; i<n-1; i++)
    {
        int minIndex = i;
        for(int j=i+1; j<n; j++)
        {
            if(arr[j] < arr[i])
                minIndex = j;
            
            swap(&arr[i], &arr[minIndex]);
        }
    }
    return;
}

void printArray(int arr[], int n)
{
    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

int main()
{
    int arr[] = {64, 25, 12, 22, 11};  
    int n = sizeof(arr)/sizeof(arr[0]); 
    selection(arr, n);
    printArray(arr, n);
}