// Given n balloons, indexed from 0 to n-1. Each balloon is painted 
// with a number on it represented by array nums. You are asked to burst
// all the balloons. If the you burst balloon i you will get 
// nums[left] * nums[i] * nums[right] coins. Here left and right 
// are adjacent indices of i. After the burst, the left and right
// then becomes adjacent.

// Find the maximum coins you can collect by bursting the balloons 
// wisely.

// Input: [3,1,5,8]
// Output: 167 
// Explanation: nums = [3,1,5,8] --> [3,5,8] -->   [3,8]   -->  [8]  --> []
//              coins =  3*1*5      +  3*5*8    +  1*3*8      + 1*8*1   = 167

// dp[left][right] = sum of coins for bursting coins from left to right
// matric chain modification
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int len = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
         
        vector<vector<int>> dp(len+2, vector<int>(len+2,0));
        for (int iv = 0; iv<len;iv++ ) 
        {   
            for (int left = 1; left <=len-iv;left++) 
            {
                int right = left + iv;
                for (int k = left; k<=right; k++) 
                {
                    int burst_nums = nums[left-1]*nums[k]*nums[right+1] ;
                    dp[left][right] = max(dp[left][right], 
                    burst_nums+ dp[left][k-1] +dp[k+1][right]);
                }
            }    
        }
        return dp[1][len];
    }
};