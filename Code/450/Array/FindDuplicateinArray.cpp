// Given an array of integers nums containing n + 1 integers where each 
// integer is in the range [1, n] inclusive.

// There is only one duplicate number in nums, return this duplicate
// number.

// Example 1:
// Input: nums = [1,3,4,2,2]
// Output: 2
// Example 2:

// Input: nums = [3,1,3,4,2]
// Output: 3
// Example 3:

// Input: nums = [1,1]
// Output: 1
// Example 4:

// Input: nums = [1,1,2]
// Output: 1

// Time - O(n)
// Space - O(1)

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        for(int i=0; i<n; i++)
        {
            if(nums[abs(nums[i])-1] > 0 )
                nums[abs(nums[i])-1] = -nums[abs(nums[i])-1]; 
            else
                return abs(nums[i]);
        }
        return -1;
    }
};