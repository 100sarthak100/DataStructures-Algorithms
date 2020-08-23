// Given an array of integers where each element represents 
// the max number of steps that can be made forward from that element. 
// The task is to find the minimum number of jumps to reach the end 
// of the array (starting from the first element). If an element is 
// 0, then cannot move through that element.

// Input:
// 2
// 11
// 1 3 5 8 9 2 6 7 6 8 9
// 6
// 1 4 3 2 6 7
// Output:
// 3
// 2

// Explanation:
// Testcase 1: First jump from 1st element, and we jump to 2nd 
// element with value 3. Now, from here we jump to 5h element with 
// value 9. 
// and from here we will jump to last.
#include<bits/stdc++.h>
using namespace std;

// if reachable print minimum no of steps
int minJump(int arr[], int n)
{
    long long int dp[n+1];
    long long int actJump[n+1];
    for(int i=0; i<=n; i++)
        dp[i] = INT_MAX;
    
    dp[0] = 0;
    actJump[0] = 0;
    
    for(int i=1; i<=n; i++)
    {
        for(int j=0; j<i; j++)
        {
            if(j + arr[j] >= i)
            {
                if(dp[i] > 1 + dp[j])
                {
                    dp[i] = 1 + dp[j];
                    actJump[i] = j;
                }
                
            }
        }
    }
    if(dp[n-1] == INT_MAX)
        return -1;
    return dp[n-1];
}

int main()
 {
	int t;cin>>t;
	while(t--)
	{
	    int n;cin>>n;
	    int arr[n];
	    for(int i = 0;i <n;i++)
	        cin>>arr[i];
	    cout<<minJump(arr, n)<<endl;
	}
	return 0;
}

// bool if reachable or not
bool isReachable(int arr[], int n)
{
    int reachable = 0;
    for(int i=0; i<n; i++)
    {
        if(reachable < i)
            return false;
        reachable = max(reachable, i + arr[i]);
    }
    return false;
}