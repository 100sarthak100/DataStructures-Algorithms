#include <bits/stdc++.h>
using namespace std;

int knapsack(int val[], int wt[], int W, int n)
{
    int dp[n+1][W+1];

    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=W; j++)
        {
            if(i == 0 || j == 0)
                dp[i][j] = 0;
            else if(wt[i-1] <= j)
                dp[i][j] = max(val[i-1] + dp[i-1][j - wt[i-1]], dp[i-1][j]);
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    for(int i = 0;i<=n;i++)
    {
        for(int j = 0;j<=W;j++)
            cout<<dp[i][j]<<" ";
        cout<<endl;
    }
    return dp[n][W];
}

int main()
{
    int iv[] = {2, 4, 4, 5};
    int pages[] = {2, 2, 3, 4};
    int p = 15;
    int n = 4;
    for(int i=0; i<n; i++)
        pages[i] = pages[i]*2;
    cout<<knapsack(iv, pages, p, n)<<endl;
}

// output - 10