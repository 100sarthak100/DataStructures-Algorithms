// Find total number of Squares in a N*N cheesboard.

// Input:
// 2
// 1
// 2

// Output:
// 1
// 5

// total number of squares in n*n chessboard
#include<iostream>
using namespace std;

int totalWays(int n)
{
    if(n == 0)
        return 0;
    int dp[n+1];
    dp[0] = 0;
    dp[1] = 1;
    for(int i=2; i<=n; i++)
    {
        dp[i] = i*i + dp[i-1];
    }
    return dp[n];
}

int main()
 {
	int t;cin>>t;
	while(t--)
	{
	    int n;cin>>n;
	    cout<<totalWays(n)<<endl;
	}
	return 0;
}

// total no of rectangels in n*n chessboard
#include<bits/stdc++.h>
using namespace std;

long long int noOfRect(int n)
{
    if(n == 0 || n == 1)
        return 0;
    long long int square = 0;
    for(int i=1; i<=n; i++)
    {
        square += i*i;
    }
    long long int rectPlusSquare = pow((n*(n+1)/2), 2);
    return rectPlusSquare - square;
}

int main()
 {
	int t;cin>>t;
	while(t--)
	{
	    int n;cin>>n;
	    cout<<noOfRect(n)<<endl;
	}
	return 0;
}