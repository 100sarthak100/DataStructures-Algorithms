// Suppose you have N eggs and you want to determine from 
// which floor in a K-floor building you can drop an egg such 
// that it doesn't break. You have to determine the minimum number 
// of attempts you need in order find the critical floor in the worst 
// case while using the best strategy.

// Input:
// 2
// 2 10
// 3 5

// Output:
// 4
// 3

// // recursive solution using mcm
// #include <bits/stdc++.h>
// using namespace std;

// int eggDrop(int e, int f)
// {
//     if(f == 1 || f == 0)
//         return f;
//     if(e == 1)
//         return f;
    
//     int minVal = INT_MAX;
//     for(int k=1; k<=f; k++)
//     {
//         int temp = 1 + max(eggDrop(e-1, k-1), eggDrop(e, f-k));
//         minVal = min(minVal, temp);
//     }
//     return minVal;
// }

// int main()
// {
//     int t;cin>>t;
//     while(t--)
//     {
//         int n, k;
//         cin>>n>>k;
//         cout<<eggDrop(n, k)<<endl;
//     }
// }

// using bottom up dp (memoization)
#include <bits/stdc++.h>
using namespace std;

int dp[11][51];

int eggDrop(int e, int f)
{
    if(f == 1 || f == 0)
        return f;
    if(e == 1)
        return f;
    if(dp[e][f] != -1)
        return dp[e][f];
    
    int minVal = INT_MAX;
    for(int k=1; k<=f; k++)
    {
        int temp = 1 + max(eggDrop(e-1, k-1), eggDrop(e, f-k));
        minVal = min(minVal, temp);
    }
    dp[e][f] = minVal;
    return minVal;
}

int main()
{
    int t;cin>>t;
    while(t--)
    {
        int n, k;
        cin>>n>>k;
        memset(dp, -1, sizeof(dp));
        cout<<eggDrop(n, k)<<endl;
    }
}