// We have to paint n boards of length {A1, A2…An}. 
// There are k painters available 
// and each takes 1 unit time to 
// paint 1 unit of board. The problem is to find the minimum time to get

// Input : k = 2, A = {10, 10, 10, 10} 
// Output : 20.
// Here we can divide the boards into 2
// equal sized partitions, so each painter 
// gets 20 units of board and the total
// time taken is 20. 

// Input : k = 2, A = {10, 20, 30, 40} 
// Output : 60.
// Here we can divide first 3 boards for
// one painter and the last board for 
// second painter.

// time complexity - O(K*N^2)
// space complexity - O(k*N)

#include <bits/stdc++.h>
using namespace std;

// recursion
int sum(int arr[], int from, int to)
{
    int total = 0;
    for(int i = from; i<=to; i++)
        total += arr[i];
    return total;
}

int partition(int arr[], int n, int k)
{
    if(k == 1)
        return sum(arr, 0, n-1);
    if(n == 1)
        return arr[0];
    int best = INT_MAX;

    for(int i=1; i<=n; i++)
    {
        cout<<partition(arr, i, k-1)<<" "<<sum(arr, i, n-1)<<endl;
        best = min(best, max(partition(arr, i, k-1),
                                sum(arr, i, n-1)));
    }
    return best;
}

// dp
int findMax(int arr[], int n, int k)
{
    int dp[k+1][n+1];
    memset(dp, 0, sizeof(dp));
    // for(int i = 1; i<=n; i++)
    //     dp[1][i] = sum(arr, 0, i-1);

    for(int i = 1; i<=k; i++)
        dp[i][1] = arr[0];

    int sum[n+1] = {0};
    for(int i = 1; i<=n; i++)
        sum[i] = sum[i-1] + arr[i-1];
    
    for(int i = 1; i<=n; i++)
        dp[1][i] = sum[i];

    for(int i = 2; i<=k; i++)
    {
        for(int j = 2; j<=n; j++)
        {
            int best = INT_MAX;

            for(int p = 1; p<=j; p++)
            {
                //cout<<dp[i-1][p]<<" "<<sum(arr, p, j-1)<<endl;
                // best = min(best, max(dp[i-1][p],
                //                         sum(arr, p, j-1)));
                best = min(best, max(dp[i-1][p], sum[j] - sum[p]));
            }
            dp[i][j] = best;
        }
    }
    for(int i = 0;i<=k;i++)
    {
        for(int j = 0;j<+n;j++)
            cout<<dp[i][j]<<" ";
        cout<<endl;
    }
    return dp[k][n];
}


int main()
{
    int arr[] = { 10, 20, 60, 50, 30, 40 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    int k = 3; 
    cout << findMax(arr, n, k) << endl; 
    return 0;
}