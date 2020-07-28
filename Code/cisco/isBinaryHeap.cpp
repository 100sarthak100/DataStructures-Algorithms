// Given an array A of size N, the task is to check if the given 
// array represents a Binary Max Heap.

// Input:
// 2
// 6
// 90 15 10 7 12 2
// 6
// 9 15 10 7 12 11

// Output:
// 1
// 0

// Time complexity of this solution is O(n).

#include<iostream>
using namespace std;

int isHeap(int arr[], int n)
{
    for(int i=0; i<=(n-2)/2; i++)
    {
        if((2*i + 1) < n && arr[2*i + 1] > arr[i])
            return 0;
        if((2*i + 2) < n && arr[2*i + 2] > arr[i])
            return 0;
    }
    return 1;
}

int main()
 {
	int t;cin>>t;
	while(t--)
	{
	    int n;cin>>n;
	    int arr[n];
	    for(int i=0; i<n; i++)
	        cin>>arr[i];
	    cout<<isHeap(arr, n)<<endl;
	}
	return 0;
}