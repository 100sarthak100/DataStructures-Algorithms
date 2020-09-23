// Given an unsorted array A of size N. Find the subarray A[s..e] 
// such that sorting this subarray makes the whole array 
// sorted.

// Input:
// 2
// 11
// 10 12 20 30 25 40 32 31 35 50 60
// 9
// 0 1 15 25 6 7 30 40 50

// Output:
// 3 8
// 2 5

// Explanation:
// Testcase 1: Subarray starting from index 3 and ending at index 8 is 
// required subarray.
// Initial array: 10 12 20 30 25 40 32 31 35 50 60
// Final array:  10 12 20 25 30 31 32 35 40 50 60  (After sorting the 
// bold part)

#include<iostream>
using namespace std;

void sortArray(int arr[], int n)
{
    int s = 0, e = n-1, i;
    for(i=0; i<n-1; i++)
    {
        if(arr[i] > arr[i+1])
            break;
    }
    s = i;
    if(s == n-1)
    {
        cout<<0<<" "<<0<<endl;
        return;
    }
    
    for(i=n-1; i>0; i--)
    {
        if(arr[i] < arr[i-1])
            break;
    }
    e = i;
    
    int maxEle = 0, minEle = 100000000;
    for(i=s; i<=e; i++)
    {
        if(arr[i] > maxEle)
            maxEle = arr[i];
        if(arr[i] < minEle)
            minEle = arr[i];
    }
    
    for(i=0; i<s; i++)
    {
        if(arr[i] > minEle)
        {
            s = i;
            break;
        }
    }
    
    for(i=n-1; i>=e-1; i--)
    {
        if(arr[i] < maxEle)
        {
            e = i;
            break;
        }
    }
    
    cout<<s<<" "<<e<<endl;
    return;
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
	    sortArray(arr, n);
	}
	return 0;
}