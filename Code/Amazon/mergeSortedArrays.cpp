// Merge two sorted arrays with O(1) extra space

// We are given two sorted array. We need to merge these two arrays such 
// that the initial numbers (after complete sorting) are in the first 
// array and the remaining numbers are in the second array. Extra space 
// allowed in O(1).

// Example:

// Input: ar1[] = {10};
//        ar2[] = {2, 3};
// Output: ar1[] = {2}
//         ar2[] = {3, 10}  

// Input: ar1[] = {1, 5, 9, 10, 15, 20};
//        ar2[] = {2, 3, 8, 13};
// Output: ar1[] = {1, 2, 3, 5, 8, 9}
//         ar2[] = {10, 13, 15, 20} 


// Time - worst case - O(m*n)
// Space - O(1)

#include <bits/stdc++.h>
using namespace std;

void merge(int ar1[], int ar2[], int m, int n)
{
    for (int i = n - 1; i >= 0; i--)
    {
        int j, last = ar1[m - 1];
        for (j = m - 2; j >= 0 && ar1[j] > ar2[i]; j--)
            ar1[j + 1] = ar1[j];
        if (j != m - 2 || last > ar2[i])
        {
            ar1[j + 1] = ar2[i];
            ar2[i] = last;
        }
    }
}

int main()
{
    int ar1[] = {1, 5, 9, 10, 15, 20};
    int ar2[] = {2, 3, 8, 13};
    int m = sizeof(ar1) / sizeof(ar1[0]);
    int n = sizeof(ar2) / sizeof(ar2[0]);
    merge(ar1, ar2, m, n);
}