// Insertion sort is a simple sorting algorithm that works the way 
// we sort playing cards in our hands.

// Time Complexity: O(n*2)

// Auxiliary Space: O(1)

// Sorting In Place: Yes

// Stable: Yes

// Uses: Insertion sort is used when number of elements is small. 
// It can also be useful when input array is almost sorted, only few 
// elements are misplaced in complete big array.

#include <bits/stdc++.h>
using namespace std;

void insertionSort(int arr[], int n)
{
    int i, j;
    int iter = 0;
    for(int i=1; i<n; i++)
    {
        int key = arr[i];
        j = i - 1;

        while(j >= 0 && arr[j] > key)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
        iter++;
        cout<<iter<<endl;
        for(int i=0; i<n; i++)
            cout<<arr[i]<<" ";
        cout<<endl;
    }
}

void printArray(int arr[], int n)
{
    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

int main()
{
    int arr[] = { 8, 10, 2, 12, 15,3 };  
    int n = sizeof(arr) / sizeof(arr[0]);  
    insertionSort(arr, n);
    printArray(arr, n);
}