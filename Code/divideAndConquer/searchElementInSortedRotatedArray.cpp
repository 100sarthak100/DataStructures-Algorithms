// Input:
// 3
// 9
// 5 6 7 8 9 10 1 2 3
// 10
// 3
// 3 1 2
// 1
// 4
// 3 5 1 2
// 6

// Output:
// 5
// 1
// -1

// Explanation:
// Testcase 1: 10 is found at index 5.

// time complexity - O(logn)
// uses binary search

#include<iostream>
using namespace std;

int binarySearch(int arr[], int l, int r, int x)
{
    while(l <= r)
    {
        int m = (l + r)/2;
        if(arr[m] == x)
            return m;
        else if(arr[m] < x)
            l = m + 1;
        else
            r = m - 1;
    }
    return -1;
}

int findPivot(int arr[], int low, int high)
{
    if(low > high) return -1;
    if(low == high) return low;
    
    int mid = (low + high)/2;
    
    if(mid < high && arr[mid + 1] < arr[mid])
        return mid;
    if(mid > low && arr[mid] < arr[mid - 1])
        return mid - 1;
        
    if(arr[low] >= arr[mid])
        return findPivot(arr, low, mid-1);
        
    return findPivot(arr, mid+1, high);
}

int piviotedBS(int arr[], int n, int x)
{
    int pivot = findPivot(arr, 0, n-1);
    if(pivot == -1)
	   return binarySearch(arr, 0, n-1, x);
	   
	if(arr[pivot] == x)
	   return pivot;
	   
	if(arr[0] <= x)
	    return binarySearch(arr, 0, pivot-1, x);
	    
	return binarySearch(arr, pivot+1, n-1, x);
}

int main()
 {
	int t;cin>>t;
	while(t--)
	{
	    int n;cin>>n;
	    int arr[n];
	    for(int i = 0; i< n; i++)
	        cin>>arr[i];
	   int x;cin>>x;
	   
	   cout<<piviotedBS(arr, n, x)<<endl;
	}
	return 0;
}