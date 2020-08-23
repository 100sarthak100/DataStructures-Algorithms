// Given an integer array nums, find the contiguous 
// subarray within an array (containing at least one number) 
// which has the largest product.

// Example 1:

// Input: [2,3,-2,4]
// Output: 6
// Explanation: [2,3] has the largest product 6.
// Example 2:

// Input: [-2,0,-1]
// Output: 0
// Explanation: The result cannot be 2, because [-2,-1] is 
// not a subarray.

// time - O(N)
// space - O(1)

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int currMax = nums[0];
        int currMin = nums[0];
        int prevMax = nums[0];
        int prevMin = nums[0];
        int ans = nums[0];
        for(int i=1; i<n; i++)
        {
            currMax = max(nums[i], max(nums[i]*prevMax, nums[i]*prevMin));
            currMin = min(nums[i], min(nums[i]*prevMax, nums[i]*prevMin));
            ans = max(ans, currMax);
            prevMax = currMax;
            prevMin = currMin;
        }
        return ans;
    }
};