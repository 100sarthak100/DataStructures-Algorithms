// Given an array arr of N integers. Find the contiguous sub-array with 
// maximum sum.

// Input
// 2
// 5
// 1 2 3 -2 5
// 4
// -1 -2 -3 -4
// Output
// 9
// -1

// Explanation:
// Testcase 1: Max subarray sum is 9 of elements (1, 2, 3, -2, 5) 
// which is a contiguous subarray.

// Time - O(n)
// Space - O(1)

#include<iostream>
using namespace std;

int kaden(int arr[], int n)
{
    int maxSum = -10000000, currSum = 0;
    int i = 0, start = 0, endF = 0, startF = 0;
    
    while(i < n)
    {
        currSum += arr[i];
        if(maxSum < currSum)
        {
            maxSum = currSum ;
            startF = start;
            endF = i;
        }
        
        if(currSum < 0)
        {
            currSum = 0;
            start = i+1;
        }
        
        i++;
    }
    int sumVal = 0;
    for(i=startF; i<=endF; i++)
        sumVal += arr[i];
    return sumVal;
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
	    cout<<kaden(arr, n)<<endl;
	}
	return 0;
}