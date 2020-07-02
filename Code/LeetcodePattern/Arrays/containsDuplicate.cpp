// Example 1:

// Input: [1,2,3,1]
// Output: true
// Example 2:

// Input: [1,2,3,4]
// Output: false
// Example 3:

// Input: [1,1,1,3,3,4,3,2,4,2]
// Output: true

// time  O(N)

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if(nums.size() == 0)
            return false;
        sort(nums.begin(), nums.end());
        for(int i = 0; i<nums.size() - 1; i++)
        {
            if(nums[i] == nums[i+1])
                return true;
        }
        return false;
    }
};