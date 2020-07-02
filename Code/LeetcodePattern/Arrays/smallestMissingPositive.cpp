// Given an unsorted integer array, find the smallest missing 
// positive integer.

// Example 1:

// Input: [1,2,0]
// Output: 3
// Example 2:

// Input: [3,4,-1,1]
// Output: 2
// Example 3:

// Input: [7,8,9,11,12]
// Output: 1

// best soln
// O(n) time and O(1) extra space solution:
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        vector<bool> present(n+1, false);
        
        for(int i=0; i<n; i++)
        {
            if(nums[i] > 0 && nums[i] <= n)
                present[nums[i]] = true;
        }
        
        for(int i=1; i<=n; i++)
        {
            if(!present[i])
                return i;
        }
        
        return n+1;
    }
};