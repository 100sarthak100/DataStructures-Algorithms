// Given an array of integers nums sorted in ascending order, 
// find the starting and ending position of a given target value.

// Your algorithm's runtime complexity must be in the order of 
// O(log n).

// If the target is not found in the array, return [-1, -1].
// Example 1:

// Input: nums = [5,7,7,8,8,10], target = 8
// Output: [3,4]
// Example 2:

// Input: nums = [5,7,7,8,8,10], target = 6
// Output: [-1,-1]

// In O(log n), using binary search

class Solution {
public:
    int binarySF(vector<int> &nums, int target)
    {
        int l = 0;
        int h = nums.size()  - 1;
        int res = -1;
        while(l <= h)
        {
            int mid = l + (h - l)/2;
            if(nums[mid] == target)
            {
                res = mid;
                h = mid - 1;
            }
            else if(target < nums[mid])
                h = mid - 1;
            else
                l = mid + 1;
        }
        return res;
    }
    
    int binarySL(vector<int> &nums, int target)
    {
        int l = 0;
        int h = nums.size()  - 1;
        int res = -1;
        while(l <= h)
        {
            int mid = l + (h - l)/2;
            if(nums[mid] == target)
            {
                res = mid;
                l = mid + 1;
            }
            else if(target < nums[mid])
                h = mid - 1;
            else
                l = mid + 1;
        }
        return res;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        int firstOccur = binarySF(nums, target);
        int lastOccur = binarySL(nums, target);
        return {firstOccur, lastOccur};
    }
};