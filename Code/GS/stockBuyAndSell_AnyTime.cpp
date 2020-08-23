// The cost of stock on each day is given in an array A[] of size N.
// Find all the days on which you buy and sell the stock so that 
// in between those days your profit is maximum.

// Input:
// 3
// 7
// 100 180 260 310 40 535 695
// 4
// 100 50 30 20
// 10
// 23 13 25 29 33 19 34 45 65 67

// Output:
// (0 3) (4 6)
// No Profit
// (1 4) (5 9)

// Explanation:
// Testcase 1: We can buy stock on day 0, and sell it on 3rd day, 
// which will give us maximum profit.

// Note: Output format is as follows - (buy_day sell_day) (buy_day 
// sell_day)
// For each input, output should be in a single line.

#include<iostream>
using namespace std;

int maxProfit(int price[], int n)
{
    if(n == 0)
        return 0;
    int maxProfit = 0;
    int i = 0;
    while(i < n)
    {
        while(i < n-1 && price[i+1] <= price[i])
            i++;
        if(i == n-1)
            break;
        int buy = i;
        i++;
        
        while(i < n && price[i] >= price[i-1])
            i++;
        int sell = i-1;
        
        maxProfit += price[sell] - price[buy];
        cout<<"("<<buy<<" "<<sell<<")"<<" ";
    }
    if(maxProfit <= 0)
        cout<<"No Profit";
    return maxProfit;
}

int main()
 {
	int t;cin>>t;
	while(t--)
	{
	    int n;cin>>n;
	    int arr[n];
	    for(int i=0; i<n; i++)
	        cin>>arr[i];
	   maxProfit(arr, n);
	   cout<<endl;
	}
	return 0;
}

// stock buy sell 1 time only

// Say you have an array for which the ith element is the 
// price of a given stock on day i.

// If you were only permitted to complete at most one transaction 
// (i.e., buy one and sell one share of the stock), design an 
// algorithm to find the maximum profit.

// Note that you cannot sell a stock before you buy one.

// Example 1:

// Input: [7,1,5,3,6,4]
// Output: 5
// Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
//              Not 7-1 = 6, as selling price needs to be larger 
//              than buying price.
// Example 2:

// Input: [7,6,4,3,1]
// Output: 0
// Explanation: In this case, no transaction is done, i.e. 
// max profit = 0.

// time - O(n)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n == 0 || n == 1)
            return 0;
        int minValue = prices[0];
        int maxProfit = 0;
        
        for(int i=1; i<n; i++)
        {
            if(prices[i] < minValue)
                minValue = prices[i];
            else if(prices[i] - minValue > maxProfit)
                maxProfit = prices[i] - minValue;
        }
        return maxProfit;
    }
};