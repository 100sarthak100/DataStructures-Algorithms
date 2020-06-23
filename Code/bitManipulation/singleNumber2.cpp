// Given a non-empty array of integers, every element appears 
// three times except for one, which appears exactly once. Find 
// that single one.

// Note:

// Your algorithm should have a linear runtime complexity. Could 
// you implement it without using extra memory?

// Example 1:

// Input: [2,2,3,2]
// Output: 3
// Example 2:

// Input: [0,1,0,1,0,1,99]
// Output: 99

// Time Complexity : O(n)
// Auxiliary Space : O(1)

class Solution {
public:
    #define INT_SIZE 32
    int singleNumber(vector<int>& nums) {
        int sum , result = 0;
        int x;
        
        for(int i = 0; i < INT_SIZE; i++)
        {
            x = (1 << i);
            sum = 0;
            for(int j=0; j<nums.size(); j++)
            {
                if(nums[j] & x)
                    sum++;
            }
            
            if(sum % 3)
                result = result | x;
        }
        return result;
    }
};