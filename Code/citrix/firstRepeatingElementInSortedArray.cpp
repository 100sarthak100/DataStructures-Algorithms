// Given an integer array. The task is to find the first 
// repeating element in the array i.e., an element that 
// occurs more 
// than once and 
// whose index of first occurrence is smallest.

// Input:
// 3
// 7
// 1 5 3 4 3 5 6
// 4
// 1 2 3 4
// 5
// 1 2 2 1 3
// Output:
// 2
// -1
// 1

// Explanation: 
// Testcase 1: 5 is appearing twice and its first appearence 
// is at index 2 which is less than 
// 3 whose first occuring index is 3.
// Testcase 2: None of the elements are occuring twice . So, 
// the answer is -1.
// Testcase 3: 1 is appearing twice and its first appearence 
// is at index 1 which is less than 2 whose first occuring is 
// at index 2.

// Time - O(n)
// space - O(m) -> m is distinct elemnt

#include<bits/stdc++.h>
using namespace std;

int firstRepeat(int arr[], int n)
{
    int min = -1;
    set<int> st;
    
    for(int i = n-1; i>=0; i--)
    {
        if(st.find(arr[i]) != st.end())
            min = i;
        else
            st.insert(arr[i]);
    }
    if(min == -1)
        return -1;
    return min+1;
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
	    cout<<firstRepeat(arr, n)<<endl;
	}
	return 0;
}