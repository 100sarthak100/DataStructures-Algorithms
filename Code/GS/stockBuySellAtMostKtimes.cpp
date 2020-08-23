// In stock market , a person buys a stock and sells it on some 
// future date. Given the stock prices of N days in an form of an 
// array A[ ] and a positive integer K, find out the maximum profit 
// a person can make in atmost K transactions. A transaction is 
// equivalent to (buying + selling) of a stock and new transaction 
// can start only when the 
// previous transaction has been completed.

// Input:
// 3
// 2
// 6
// 10 22 5 75 65 80
// 3
// 4
// 20 580 420 900
// 1
// 5
// 100 90 80 50 25
// Output:
// 87
// 1040
// 0

// Explanation:
// Output 1: Trader earns 87 as sum of 12 and 75  i.e. Buy at 
// price 10, 
// sell at 22, buy at  5 and sell at 80
// Output 2: Trader earns 1040 as sum of 560 and 480 i.e. Buy 
// at price 20, sell at 580, buy at 420 and sell at 900
// Output 3: Trader cannot make any profit as selling price is 
// decreasing day by day.Hence, it is not possible to earn anything.

// time - O(nk)
// space - O(nk)

#include<bits/stdc++.h>
using namespace std;

int maxTransac(int price[], int k, int d)
{
    int dp[k+1][d+1];
    for(int i=0; i<=k; i++)
        dp[i][0] = 0;
    for(int j=0; j<=d; j++)
        dp[0][j] = 0;
    
    for(int i=1; i<=k; i++)
    {
        int maxVal = INT_MIN;
        for(int j=1; j<=d; j++)
        {
            maxVal = max(maxVal, -price[j-1] + dp[i-1][j-1]);
            dp[i][j] = max(dp[i][j-1], price[j] + maxVal); 
        }
    }
    return dp[k][d-1];
}

int main()
 {
	int t;cin>>t;
	while(t--)
	{
	    int k, n;
	    cin>>k>>n;
	    int arr[n];
	    for(int i=0; i<n; i++)
	        cin>>arr[i];
	   cout<<maxTransac(arr, k, n)<<endl;
	}
	return 0;
}