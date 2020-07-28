// The task is to count all the possible paths from top left to 
// bottom right of a mXn matrix with the constraints that from each 
// cell you can either 
// move only to right or down.

// Input:
// 1
// 3 3
// Output:
// 6

// Time complexity of the above dynamic programming solution is 
// O(mn).
// The space complexity of the above solution is O(mn).

#include<iostream>
using namespace std;
#define mod 1000000007

long long int grid(int n, int m)
{
    long long int dp[n][m];
    
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(i==0 || j==0)
                dp[i][j] = 1;
            else
                dp[i][j] = (dp[i-1][j]%mod + dp[i][j-1]%mod)%mod;
        }
    }
    return dp[n-1][m-1]%mod;
}

int main()
 {
	int t;cin>>t;
	while(t--)
	{
	    int n,m;
	    cin>>n>>m;
	    cout<<grid(n, m)<<endl;
	}
	return 0;
}

// Another Approach:(Using combinatorics) In this approach We have 
// to calculate m+n-2 C n-1 here 
// which will be (m+n-2)! / (n-1)! (m-1)!

int numberOfPaths(int m, int n) 
{ 
    // We have to calculate m+n-2 C n-1 here 
    // which will be (m+n-2)! / (n-1)! (m-1)! 
    int path = 1; 
    for (int i = n; i < (m + n - 1); i++) { 
        path *= i; 
        path /= (i - n + 1); 
    } 
    return path; 
} 