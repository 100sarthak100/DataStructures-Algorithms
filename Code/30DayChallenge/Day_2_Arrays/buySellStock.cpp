#include <bits/stdc++.h>
using namespace std;

int stocks(int price[], int n)
{
    int i = 0;
    int maxProfit = 0;
    if(n == 1)
        return 0;
    while(i < n-1)
    {
        while(i < n-1 && price[i+1] <= price[i])
            i++;
        if(i == n-1)
            break;
        int buy = i;
        i++;

        while(i<n && price[i] >= price[i-1])
            i++;
        int sell = i-1;

        maxProfit += (price[sell] - price[buy]);
    }
    return maxProfit;
}

int main()
{
    int price[] = {100, 180, 260, 310, 40, 535, 695};
    int n = sizeof(price) / sizeof(price[0]);
    cout << stocks(price, n);
}