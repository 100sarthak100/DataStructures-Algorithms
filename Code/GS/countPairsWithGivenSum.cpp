// Given an array of integers, and an integer  ‘K’ , find the 
// count of pairs of elements 
// in the array whose sum is equal to 'K'.

// Input
// 2
// 4 6
// 1  5  7 1
// 4 2
// 1 1 1 1
// Output
// 2
// 6

#include<bits/stdc++.h>
using namespace std;

int countPair(int arr[], int n, int k)
{
    unordered_map<int, int> mp;
    for(int i=0; i<n; i++)
        mp[arr[i]]++;
    
    int count = 0;
    for(int i=0; i<n; i++)
    {
        count += mp[k - arr[i]];
        if(k - arr[i] == arr[i])
            count--;
    }
    return count/2;
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
	   cout<<countPair(arr, n, k)<<endl;
	}
	return 0;
}