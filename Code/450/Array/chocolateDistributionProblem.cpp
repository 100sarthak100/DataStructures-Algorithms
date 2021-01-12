// Given an array A of positive integers of size N, where each value 
// represents number of chocolates in a packet. Each packet can have 
// variable number of chocolates. 
// There are M students, the task is to distribute chocolate packets 
// such that :
// 1. Each student gets one packet.
// 2. The difference between the number of chocolates given to the 
// students having packet with maximum chocolates and student having 
// packet with minimum chocolates is minimum.

// Time - O(nlogn) // cause using sort function
// Space - O(1);

#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int t;cin>>t;
	while(t--)
	{
	    int n;cin>>n;
	    int arr[n];
	    
	    for(int i=0; i<n; i++)
	        cin>>arr[i];
	    sort(arr, arr+n);
	    int s; cin>>s;
	    int l = 0, h = s-1;
	    int minDiff = INT_MAX;
	    while(h < n)
	    {
	        minDiff = min(minDiff, arr[h] - arr[l]);
	        l++;
	        h++;
	    }
	    
	    cout<<minDiff<<endl;
	}
	return 0;
}