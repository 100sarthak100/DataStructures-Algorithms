// Input:
// 2
// 5
// 1 2 3 4 5 
// 4
// 5
// 11 22 33 44 55
// 445

// Output:
// 3
// -1

// time complexity - T(n) = T(n/2) + c  -> O(logn) (theta)
// space in iterative method -> O(1)

#include <bits/stdc++.h>
using namespace std;

// iterative method
int binarySearch(int arr[], int l, int r, int x)
{
    while(l <= r)
    {
        int mid = (l + r)/2;
        if(arr[mid] == x)
            return mid;
        else if(arr[mid] < x)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return -1;
}

int main()
{
    int arr[] = { 2, 3, 4, 10, 40 }; 
    int x = 10;
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<binarySearch(arr, 0, n-1, x)<<endl;
}