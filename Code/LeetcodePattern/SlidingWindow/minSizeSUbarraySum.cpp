// Given an array of n positive integers and a positive integer s, 
// find the minimal length of a contiguous subarray of which the 
// sum ≥ s. If there isn't one, return 0 instead.

// Input: s = 7, nums = [2,3,1,2,4,3]
// Output: 2
// Explanation: the subarray [4,3] has the minimal length under the problem 
// constraint.

//O(n) approach using two pointers
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int minLength = INT_MAX;
        int n = nums.size();
        int i = 0;
        int sum = 0;
        for(int j=0; j<n; j++)
        {
            sum += nums[j];
            while(i < nums.size() && sum >= s)
            {
                minLength = min(minLength, j - i + 1);
                sum -= nums[i];
                i++;
            }
        }
        return (minLength == INT_MAX)? 0 : minLength;
    }
};

//O(nlogn) approach