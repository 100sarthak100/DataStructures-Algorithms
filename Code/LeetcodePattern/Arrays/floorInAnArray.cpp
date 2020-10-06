// Given a sorted array arr[] of size N without duplicates, and 
// given a value x. Find the floor of x in given array. Floor of x 
// is defined as the largest element K in arr[] such that K is 
// smaller than or equal to x.

// Input:
// 3
// 7 0
// 1 2 8 10 11 12 19
// 7 5
// 1 2 8 10 11 12 19
// 7 10
// 1 2 8 10 11 12 19

// Output:
// -1
// 1
// 3

#include<bits/stdc++.h>
using namespace std;

int findFloor(int arr[], int n, int k)
{
    int l = 0;
    int h = n-1;
    int res = -1;
    while(l <= h)
    {
        int mid = l + (h - l)/2;
        if(arr[mid] == k)
            return mid;
        
        if(arr[mid] > k)
            h = mid - 1;
        else
        {
            res = max(res, mid);
            l = mid + 1;
        }
    }
    return res;
}

int main()
 {
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>>n>>k;
	    int arr[n];
	    for(int i=0; i<n; i++)
	        cin>>arr[i];
	    cout<<findFloor(arr, n, k)<<endl;
	}
	return 0;
}

// using linear search
int immediateSmaller(int arr[], int n, int x)
{
    sort(arr, arr+n);
    int prev = -1;
    for(int i=0; i<n; i++)
    {
        if(arr[i] < x)
            prev = arr[i];
        else 
            break;
    }
    return prev;
}