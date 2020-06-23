#include <bits/stdc++.h>
using namespace std;

int maxProfit(int price[], int n, int k)
{
    int profit[k+1][n+1];
    //for day 0 we cant earn money irrespective
    //of how many times we trade
    for(int i = 0;i <= k; i++)
        profit[i][0] = 0;
    //profit is 0 if we dont do any transation
    //i.e, k = 0
    for(int j = 0; j <= n; j++)
        profit[0][j] = 0;
    // bottom up approach
    for(int i = 1; i <= k; i++)
    {
        int prevDiff = INT_MIN;
        for(int j = 1; j <= n; j++)
        {
            prevDiff = max(prevDiff, profit[i-1][j-1] - price[j-1]);
            profit[i][j] = max(profit[i][j-1], price[j] + prevDiff);  
        }
    }
    return profit[k][n-1];
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