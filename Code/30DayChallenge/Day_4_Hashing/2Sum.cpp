// Given an array of integers, return indices of the two numbers such that they add up to a 
// specific target.

// You may assume that each input would have exactly one solution, 
// and you may not use the same element twice.

// Given nums = [2, 7, 11, 15], target = 9,

// Because nums[0] + nums[1] = 2 + 7 = 9,
// return [0, 1].

// Time complexity : O(n)
// space - O(N)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       unordered_map<int, int> mt;
       
        for(int i=0; i<nums.size(); i++)
        {
            if(mt.find(target - nums[i]) != mt.end())
            {
                return {mt[target - nums[i]], i};
            }
            else
                mt.insert(make_pair(nums[i], i));
        }
        return {};
    }
};