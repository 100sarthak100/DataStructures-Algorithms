// Given a binary matrix, find out the maximum size 
// square sub-matrix with all 1s.

// Input:
// 3
// 5 6
// 0 1 0 1 0 1 1 0 1 0 1 0 0 1 1 1 1 0 0 0 1 1 1 0 1 1 1 1 1 1
// 2 2
// 1 1 1 1
// 2 2
// 0 0 0 0

// Output:
// 3
// 2
// 0

// Time Complexity: O(m*n) where m is number of rows and n 
// is number of columns in the given matrix.
// Auxiliary Space: O(m*n) where m is number of rows and n 
// is number of columns in the given matrix

#include<bits/stdc++.h>
using namespace std;

int arr[51][51];

int largestSqr(int arr[][51], int n, int m)
{
    int dp[n+1][m+1];
    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=m; j++)
            dp[i][j] = 0;
    }
    int maxVal = 0;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(arr[i-1][j-1] == 1)
                dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
            maxVal = max(maxVal, dp[i][j]);
        }
    }
    return maxVal;
}

int main()
 {
	int t;cin>>t;
	while(t--)
	{
	    int n, m;
	    cin>>n>>m;
	    for(int i=0; i<n; i++)
	        for(int j=0; j<m; j++)
	           cin>>arr[i][j];
	   int a = largestSqr(arr, n, m);
	   cout<<a<<endl;
	}
	return 0;
}