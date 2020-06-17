// Input: prices = [8,4,6,2,3]
// Output: [4,2,4,2,3]
// Explanation: 
// For item 0 with price[0]=8 you will receive a discount equivalent to prices[1]=4, therefore, the final price you will pay is 8 - 4 = 4. 
// For item 1 with price[1]=4 you will receive a discount equivalent to prices[3]=2, therefore, the final price you will pay is 4 - 2 = 2. 
// For item 2 with price[2]=6 you will receive a discount equivalent to prices[3]=2, therefore, the final price you will pay is 6 - 2 = 4. 
// For items 3 and 4 you will not receive any discount at all.

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int> ret;
        if(n == 0) return ret;
        bool flag = false;
        for(int i = 0; i<n; i++)
        {
            flag = false;
            for(int j = i+1; j<n; j++)
            {
                if(prices[j] <= prices[i])
                {
                    ret.push_back(prices[i] - prices[j]);
                    flag = true;
                    break;
                }
            }
            if(flag == false)
                ret.push_back(prices[i]);
        }
        return ret;
    }
};