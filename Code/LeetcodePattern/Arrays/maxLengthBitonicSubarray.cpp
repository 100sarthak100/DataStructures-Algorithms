// Given an array A[0 … n-1] containing n positive integers, a 
// subarray A[i … j] is bitonic if there is a k with i < k < j 
// such that A[i] < A[i + 1] ... < A[k] > A[k + 1] > .. 
// A[j – 1] >  A[j]. Write a program that returns the length of the 
// maximum length bitonic subarray.

// For Example: In array {20, 4, 1, 2, 3, 4, 2, 10} the maximum 
// length bitonic subarray is {1, 2, 3, 4, 2} which is of length 5.

// Note: A[k] can be first or last element. Ex:-  10 20 30 , 
// 30 20 10 and 1 2 3 4 3 2 1 these all are bitonic array.

// Example:

// Input:
// 2
// 6
// 12 4 78 90 45 23
// 4
// 10 20 30 40

// Output:
// 5
// 4

// same as -
// - Longest peak
// - max length bitonic subarray
// - longest mountain peak

// time - O(N)
// SPACE - O(N)

#include<bits/stdc++.h>
using namespace std;

int logPeak(int arr[], int n)
{
    int maxPeak = INT_MIN;
    int i = 1;
    while(i < n)
    {
        bool isPeak = (arr[i] > arr[i-1] && arr[i] > arr[i+1]) ? true : false;
        if(!isPeak)
        {
            i++;
            continue;
        }
        
        int leftIdx = i - 2;
        while(arr[leftIdx] < arr[leftIdx+1] && leftIdx >= 0)
            leftIdx--;
        int rightIdx = i + 2;
        while(arr[rightIdx] < arr[rightIdx-1] && rightIdx < n)
            rightIdx++;
        maxPeak = max(maxPeak, rightIdx - leftIdx - 1);
        i = rightIdx;
    }
    //cout<<i<<endl;
    if(maxPeak == INT_MIN && i == n)
        return n;
    return maxPeak;
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
	   cout<<logPeak(arr, n)<<endl;
	}
	return 0;
}