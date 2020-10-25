// Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times) 
// with the following restrictions:

// You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
// After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)

// Input: [1,2,3,0,2]
// Output: 3 
// Explanation: transactions = [buy, sell, cooldown, buy, sell]

// Time - O(N)
// Space - O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
   int maxProfit(vector<int>& p) {
      int endWithSell = 0;
      int endWithBuy = INT_MIN;
      int prevBuy =0, prevSell = 0;
      for(int i =0;i<p.size();i++){
         prevBuy = endWithBuy;
         endWithBuy = max(endWithBuy,prevSell - p[i]);
         prevSell = endWithSell;
         endWithSell = max(endWithSell, prevBuy + p[i]);
      }
      return endWithSell;
   }
};
main(){
   Solution ob;
   vector<int> v = {1,2,3,0,2};
   cout << (ob.maxProfit(v));
}