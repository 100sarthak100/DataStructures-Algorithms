// Given a sorted and rotated array A of N distinct elements 
// which is rotated at some point, and given an element K. The 
// task is to find the index of 
// the given element K in the array A.

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

#include<iostream>
using namespace std;

int rotatedSearch(int arr[], int n, int k)
{
    int low = 0;
    int high = n-1;
    while(low <= high)
    {
        int mid = low + (high - low)/2;
        if(arr[mid] == k)
            return mid;
        if(arr[mid] <= arr[high])
        {
            if(k >= arr[mid] && k <= arr[high])
                low = mid + 1;
            else
                high = mid - 1;
        }
        else
        {
            if(k >= arr[low] && k <= arr[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
    }
    return -1;
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
	   int k;cin>>k;
	   cout<<rotatedSearch(arr, n, k)<<endl;
	}
	return 0;
}
