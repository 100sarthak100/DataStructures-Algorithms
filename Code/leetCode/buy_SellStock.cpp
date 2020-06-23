// Buy on day : 0   Sell on day: 3
// Buy on day : 4   Sell on day: 6
// maxProfit - 865

// time - O(n)
// can buy and sell any number of times

#include <bits/stdc++.h>
using namespace std;

// int stocks(int price[], int n)
// {
//     int maxProfit = 0;
//     int i = 0;
//     if (n == 1)
//         return 0;
//     while (i < n - 1)
//     {
//         while ((i < n - 1) && (price[i + 1] <= price[i]))
//             i++;
//         if (i == n - 1)
//             break;
//         int buy = i;
//         i++;

//         while ((i < n) && (price[i] >= price[i - 1]))
//             i++;
//         int sell = i - 1;
//         cout << buy << " " << sell << endl;
//         maxProfit = maxProfit + (price[sell] - price[buy]);
//     }
//     return maxProfit;  
// }

// int main()
// {
//     int price[] = {100, 180, 260, 310, 40, 535, 695};
//     int n = sizeof(price) / sizeof(price[0]);
//     cout << stocks(price, n);
// }

// buy and sell stock at most k times

// The time complexity of the above solution is O(kn) and 
// space complexity is O(nk).

// Let profit[i][j] represent maximum profit using at most i 
// transactions up to day j (including day i).
// dp[i][j-1] which represents not doing any transaction on 
// the jth day.

int maxProfit(int price[], int n, int k)
{
    int dp[k+1][n+1];
    
    for(int i=0; i<=k; i++)
        dp[i][0] = 0;
    for(int i=0; i<=n; i++)
        dp[0][i] = 0;

    for(int i = 1; i<=k; i++)
    {
        int prevDiff = INT_MIN;
        for(int j=1; j<=n; j++)
        {
            prevDiff = max(prevDiff, dp[i-1][j-1] - price[j-1]);
            dp[i][j] = max(dp[i][j-1], price[j] + prevDiff);
        }
    }
    return dp[k][n-1];
}

int main()
{
    int k = 3; 
    int price[] = { 12, 14, 17, 10, 14, 13, 12, 15 }; 
    int n = sizeof(price) / sizeof(price[0]); 
    cout << "Maximum profit is: "
         << maxProfit(price, n, k); 
    return 0; 
}