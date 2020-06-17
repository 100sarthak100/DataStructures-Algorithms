// For example:

// Given [1,3], [2,6], [8,10], [15,18],

// return [1,6], [8,10], [15,18].

// Make sure the returned intervals are sorted.

// Input
// 2
// 4
// 1 3 2 4 6 8 9 10
// 4
// 6 8 1 9 2 4 4 7

// Output
// 1 4 6 8 9 10
// 1 9

// time - O(n Log n) and 
// O(1) Extra Space Solution

#include<bits/stdc++.h>
using namespace std;

struct pairs
{
    int s, e;
};

bool comp(pairs a, pairs b)
{
    return a.s < b.s;
}

void mergePair(pairs arr[], int n)
{
    sort(arr, arr+n, comp);
    
    int index = 0;
    for(int i = 1; i<n; i++)
    {
        if(arr[index].e >= arr[i].s)
        {
            arr[index].e = max(arr[index].e, arr[i].e);
            arr[index].s = min(arr[index].s, arr[i].s);
        }
        else
        {
            index++;
            arr[index] = arr[i];
        }
    }
    
    for(int i=0; i<=index; i++)
        cout<<arr[i].s<<" "<<arr[i].e<<" ";
    cout<<endl;
}

int main()
 {
	int t;cin>>t;
	while(t--)
	{
	    int n, x, y;
	    cin>>n;
	    pairs arr[n];
	    for(int i = 0; i<n; i++)
	    {
	        cin>>x>>y;
	        arr[i] = {x, y};
	    }
	    mergePair(arr, n);
	}
	return 0;
}