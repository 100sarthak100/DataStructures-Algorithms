// Given an array of integers, 1 ≤ a[i] ≤ n (n = size of array), 
// some elements appear twice and others appear once.

// Find all the elements that appear twice in this array.

// Example:
// Input:
// [4,3,2,7,8,2,3,1]

// Output:
// [2,3]

// time - O(n)

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ret;
        int n = nums.size();
        if(n == 0)
            return ret;
        
        for(int i=0; i<n; i++)
        {
            if(nums[abs(nums[i]) - 1] > 0)
                nums[abs(nums[i]) - 1] = -nums[abs(nums[i]) - 1];
            else ret.push_back(abs(nums[i]));
        }
        return ret;
    }
};