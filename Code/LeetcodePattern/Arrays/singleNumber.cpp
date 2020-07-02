// Given a non-empty array of integers, every element appears twice 
// except for one. 
// Find that single one.

// Example 1:

// Input: [2,2,1]
// Output: 1
// Example 2:

// Input: [4,1,2,1,2]
// Output: 4

// time - O(n)

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        int a = nums[0];
        for(int i=1; i<n; i++)
        {
            a = a ^ nums[i];
        }
        return a;
    }
};