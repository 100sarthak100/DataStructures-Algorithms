// Given weights and values related to n items and the maximum 
// capacity allowed for these items. What is the maximum value we 
// can achieve if we can pick any weights any number of times 
// for a total allowed weight of W?

// Input:
// 2
// 2 3
// 1 1
// 2 1 
// 4 8
// 1 4 5 7
// 1 3 4 5
// Output:
// 3
// 11

#include<iostream>
using namespace std;

int unboundKnap(int val[], int wt[], int n, int W)
{
    int dp[n+1][W+1];
    
    for(int i=0; i<=n; i++)
    {
        for(int w=0; w<=W; w++)
        {
            if(i==0 || w==0)
                dp[i][w] = 0;
            else if(wt[i-1] <= w)
                dp[i][w] = max(val[i-1] + dp[i][w - wt[i-1]], dp[i-1][w]);
            else
                dp[i][w] = dp[i-1][w];
        }
    }
    return dp[n][W];
}

int main()
 {
	int t;cin>>t;
	while(t--)
	{
	    int n, w;
	    cin>>n>>w;
	    int val[n], wt[n];
	    for(int i=0; i<n; i++)
	        cin>>val[i];
	    for(int i=0; i<n; i++)
	        cin>>wt[i];
	    cout<<unboundKnap(val, wt, n, w)<<endl;
	}
	return 0;
}