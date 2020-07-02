// Given a rod of length n inches and an array of prices that 
// contains prices of all pieces of size smaller than n. Determine 
// the maximum value obtainable by cutting up the rod and 
// selling the pieces

// Maximum Obtainable Value is 22

// length   | 1   2   3   4   5   6   7   8  
// --------------------------------------------
// price    | 1   5   8   9  10  17  17  20

#include <bits/stdc++.h>
using namespace std;

// wt array -> lenght array
// val array -> price array
int cutRod(int val[], int n)
{
    int dp[n+1][n+1];
    int wt[n];
    for(int i=0; i<n; i++)
        wt[i] = i+1;

    for(int i=0; i<=n; i++)
    {
        for(int w=0; w<=n; w++)
        {
            if(i==0 || w==0)
                dp[i][w] = 0;
            else if(wt[i-1] <= w)
                dp[i][w] = max(val[i-1] + dp[i][w - wt[i-1]], dp[i-1][w]);
            else
                dp[i][w] = dp[i-1][w];
        }
    }
    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=n; j++)
            cout<<dp[i][j]<<" ";
        cout<<endl;
    }
    return dp[n][n];
}

int main() 
{ 
    int arr[] = {1, 5, 8, 9, 10, 17, 17, 20}; 
    int size = sizeof(arr)/sizeof(arr[0]); 
    printf("Maximum Obtainable Value is %d", cutRod(arr, size)); 
    getchar(); 
    return 0; 
}