// Given an array nums of n integers where n > 1,  return an 
// array output such that output[i] is equal to the 
// product of all the elements of nums except nums[i].

// Example:

// Input:  [1,2,3,4]
// Output: [24,12,8,6]

// Note: Please solve it without division and in O(n).

// time - O(N)

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ret(n, 1);
        if(n == 0)
            return ret;
        
        int temp = 1;
        for(int i=0; i<n; i++)
        {
            ret[i] = temp;
            temp = temp * nums[i];
        }
        
        temp = 1;
        for(int i=n-1; i>=0; i--)
        {
            ret[i] = ret[i] * temp;
            temp = temp * nums[i];
        }
        
        return ret;
    }
};