// Given an array nums containing n + 1 integers where each 
// integer is between 1 and n (inclusive), prove that at least one 
// duplicate number must exist. Assume that there is only one 
// duplicate number, 
// find the duplicate one.
// There is only one duplicate number in the array, but it could be repeated 
// more than once.

// Example 1:

// Input: [1,3,4,2,2]
// Output: 2
// Example 2:

// Input: [3,1,3,4,2]
// Output: 3

// number from 1 to N, one missing
// no negative numbers (only work for positive)
// same as repeated and missing number question

// time - O(n)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        for(int i=0; i<n; i++)
        {
            if(nums[abs(nums[i]) - 1] > 0)
                nums[abs(nums[i]) - 1] = -nums[abs(nums[i]) - 1];
            else return abs(nums[i]);
        }
        return 0;
    }
};

// Floyd's Tortoise and Hare (Cycle Detection) algo
// time - O(N)
// space - O(1)

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int tortoise = nums[0];
        int hare = nums[0];
        
        do
        {
            tortoise = nums[tortoise];
            hare = nums[nums[hare]];
        }
        while(hare != tortoise);
        
        tortoise = nums[0];
        while(hare != tortoise)
        {
            tortoise = nums[tortoise];
            hare = nums[hare];
        }
        
        return hare;
    }
};