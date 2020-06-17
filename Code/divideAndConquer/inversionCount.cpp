// Time Complexity: O(n log n), The algorithm used is divide and conquer, 
// So in each level one full array traversal is needed and there are log n levels 
// so the time complexity is O(n log n).
// Space Compelxity:O(1), No extra space is required.

// Number of inversions are 5

// enhance merge sort
#include <bits/stdc++.h>
using namespace std;

int merge(int arr[], int temp[], int low, int mid, int high)
{
    int i,j,k;
    int inv_count = 0;
    i = low;
    j = mid;
    k = low;

    while((i <= mid - 1) && (j <= high))
    {
        if(arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
        {
            temp[k++] = arr[j++];
            inv_count = inv_count + (mid - i);
        }
    }

    while(i <= mid - 1)
        temp[k++] = arr[i++];
    
    while(j <= high)
        temp[k++] = arr[j++];

    for(int i = low; i<= high; i++)
        arr[i] = temp[i];

    return inv_count;
}

int mergeSortUtil(int arr[], int temp[], int low, int high)
{
    int inv_count = 0;
    if (low < high)
    {
        int mid = (low + high) / 2;

        inv_count += mergeSortUtil(arr, temp, low, mid);
        inv_count += mergeSortUtil(arr, temp, mid + 1, high);

        inv_count += merge(arr, temp, low, mid+1, high);
    }
    return inv_count;
}

int mergeSort(int arr[], int n)
{
    int temp[n];
    return mergeSortUtil(arr, temp, 0, n - 1);
}

int main()
{
    int arr[] = {1, 20, 6, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int ans = mergeSort(arr, n);
    cout << " Number of inversions are " << ans;
    return 0;
}