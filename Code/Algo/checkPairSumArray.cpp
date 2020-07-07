// Input: arr[] = {0, -1, 2, -3, 1}
//         sum = -2
// Output: -3, 1
// If we calculate the sum of the output,
// 1 + (-3) = -2

// Input: arr[] = {1, -2, 1, 0, 5}
//        sum = 0
// Output: -1
// No valid pair exists.

// Complexity Analysis:

// Time Complexity: Depends on what sorting algorithm we use.
// If Merge Sort or Heap Sort is used then (-)(nlogn) in worst case.
// If Quick Sort is used then O(n^2) in worst case.
// Auxiliary Space: This too depends on sorting algorithm. The 
// auxiliary space is O(n) 
// for merge sort and O(1) for Heap Sort.

#include<bits/stdc++.h>
using namespace std;

bool sumA(int arr[], int n, int x)
{
    if(n == 0)
        return false;
    
    int start = 0, end = n-1;
    while(start < end && end>=0)
    {
        if(arr[start] + arr[end] == x)
            return true;
        else if(arr[start] + arr[end] < x)
            start++;
        else
            end--;
    }
    return false;
}

int main()
 {
	int t;cin>>t;
	while(t--)
	{
	    int n, x;
	    cin>>n>>x;
	    int arr[n];
	    for(int i=0; i<n; i++)
	        cin>>arr[i];
	    sort(arr, arr+n);
	    (sumA(arr, n, x) == 1) ? cout<<"Yes"<<endl : cout<<"No"<<endl;
	}
	return 0;
}