// Given an array arr[] of N non-negative integers representing 
// height of blocks at index i as Ai where the width of each block 
// is 1. Compute how much water can be 
// trapped in between blocks after raining.

// Input:
// 2
// 4
// 7 4 0 9
// 3
// 6 9 9

// Output:
// 10
// 0

// Explanation:
// Testcase 1: Water trapped by block of height 4 is 3 units, 
// block of height 0 is 7 units. 
// So, total unit of water trapped is 10 units.

// Time - O(n)
// Space - O(1)

#include<iostream>
using namespace std;

int rainWater(int arr[], int n)
{
    int left_max = 0, right_max = 0;
    int lo = 0, hi = n-1;
    int results = 0;
    while(lo <= hi)
    {
        if(arr[lo] < arr[hi])
        {
            if(arr[lo] > left_max)
                left_max = arr[lo];
            else
                results += left_max - arr[lo];
            
            lo++;
        }
        else
        {
            if(arr[hi] > right_max)
                right_max = arr[hi];
            else
                results += right_max - arr[hi];
            
            hi--;
        }
    }
    return results;
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
	   cout<<rainWater(arr, n)<<endl;
	}
	return 0;
}

// Alternate solution (using two arrays, MXL & MXR)
int trappingWater(int arr[], int n){
    int mxl[n], mxr[n], water[n];
    
    mxl[0] = arr[0];
    for(int i=1; i<n; i++)
        mxl[i] = max(mxl[i-1], arr[i]);
        
    mxr[n-1] = arr[n-1];
    for(int i=n-2; i>=0; i--)
        mxr[i] = max(mxr[i+1], arr[i]);
        
    int total = 0;
    for(int i=0; i<n; i++)
    {
        water[i] = min(mxl[i], mxr[i]) - arr[i];
        total += water[i];
    }
    
    return total;
}