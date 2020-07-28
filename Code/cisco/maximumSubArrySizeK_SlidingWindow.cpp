// Given an array A and an integer K. Find the maximum for each and 
// every contiguous subarray of size K.

// Input:
// 2
// 9 3
// 1 2 3 1 4 5 2 3 6
// 10 4
// 8 5 10 7 9 4 15 12 90 13

// Output:
// 3 3 4 5 5 5 6
// 10 10 10 15 15 90 90

// Time Complexity: O(n).
// space: O(K)

#include<bits/stdc++.h>
using namespace std;

void maxSizeK(int arr[], int n, int k)
{
    deque<int> q(k);
    int i;
    for(int i=0; i<k; i++)
    {
        while(!q.empty() && arr[i] >= arr[q.back()])
            q.pop_back();
        q.push_back(i);
    }
    for(; i<n; i++)
    {
        cout<<arr[q.front()]<<" ";
        while(!q.empty() && q.front() <= i - k)
            q.pop_front();
        while(!q.empty() && arr[i] >= arr[q.back()])
            q.pop_back();
        q.push_back(i);
    }
    cout<<arr[q.front()];
}

int main()
 {
	int t;cin>>t;
	while(t--)
	{
	    int n,k;
	    cin>>n>>k;
	    int arr[n];
	    for(int i=0; i<n; i++)
	        cin>>arr[i];
	    maxSizeK(arr, n, k);
	    cout<<endl;
	}
	return 0;
}