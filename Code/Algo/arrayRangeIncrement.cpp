// Given an array containing n integers and a value d. m queries 
// are given. Each query has two values start and end. For each 
// query, the problem is to increment the values from 
// the start to end index in the given array by the given value d.

// Original Array:
// 3 5 4 8 6 1
// Modified Array:
// 7 11 10 14 12 5

// Time Complexity: O(m+n)
// Auxiliary Space: O(n)

#include <bits/stdc++.h>
using namespace std;

struct query
{
    int l, r;
};

void incrementByD(int arr[], query q[], int n, int m, int d)
{
    int temp[n];
    for(int i=0; i<n; i++)
        temp[i] = 0;

    for(int i=0; i<m; i++)
    {
        temp[q[i].l] += d;
        if((q[i].r + 1) < n)
            temp[q[i].r + 1] -= d;
    }
    for(int i=1; i<n; i++)
        temp[i] += temp[i-1];
    
    for(int i = 0; i<n; i++)
        arr[i] += temp[i];
}

void printArray(int arr[], int n)
{
    for(int i = 0; i<n; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

int main()
{
    int arr[] = { 3, 5, 4, 8, 6, 1 };
    query q[] = { { 0, 3 }, { 4, 5 }, { 1, 4 },  
                                       { 0, 1 }, { 2, 5 } };
    int n = sizeof(arr) / sizeof(arr[0]); 
    int m = sizeof(q) / sizeof(q[0]); 
    int d = 2; //increment the value in the range by d

    cout << "Original Array:\n"; 
    printArray(arr, n); 
  
    // modifying the array for multiple queries 
    incrementByD(arr, q, n, m, d); 
  
    cout << "\nModified Array:\n"; 
    printArray(arr, n); 
  
    return 0; 
}