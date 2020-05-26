// Given an integer N denoting the Length of a line segment. you need to cut the 
// line segment in such a way that the cut length of a line segment each time is 
// integer either x , y or z. and after performing 
// all cutting operation the total number of cutted segments must be maximum. 

// Input

// 2
// 4
// 2 1 1
// 5
// 5 3 2


// Output
// 4
// 2

// In first test case, total length is 4, and cut lengths are 2, 1 and 1. 
//  We can make maximum 4 segments each of length 1. 
// In secon test case, we can make two segments of lengths 3 and 2

// Time Complexity: O(N).
// Use of a single for loop till length ‘N’.
// Auxiliary Space: O(N).
// Use of an array ‘DP’ to keep track of segments

#include <bits/stdc++.h>
using namespace std;

int findMaximum(int l, int p, int q, int r)
{
    int dp[l+1];
    memset(dp, -1, sizeof(dp));

    dp[0] = 0;
    for(int i = 0; i <=l; i++)
    {
        if(dp[i] == -1)
            continue;
        
        if(i + p <= l)
        {
            //cout<<i<<" "<<p<<" "<<i+p<<" "<<dp[i+p]<<" "<<dp[i]<<endl;
            dp[i+p] = max(dp[i+p], dp[i] + 1);
        }

        if(i + q <= l)
            dp[i+q] = max(dp[i+q], dp[i] + 1);

        if(i + r <= l)
            dp[i+r] = max(dp[i+r], dp[i] + 1);

        for(int i = 0;i<=l;i++)
            cout<<dp[i]<<" ";
        cout<<endl;
    }
    for(int i = 0;i<=l;i++)
        cout<<dp[i]<<" ";
    return dp[l];
}

int main()
{
    int l = 11, p = 2, q = 3, r = 5;

    // Calling Function
    int ans = findMaximum(l, p, q, r);
    cout << ans;

    return 0;
}