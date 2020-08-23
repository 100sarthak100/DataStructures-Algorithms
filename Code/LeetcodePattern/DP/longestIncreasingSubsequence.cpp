// Given an unsorted array of integers, find the length of longest 
// increasing subsequence.

// Example:

// Input: [10,9,2,5,3,7,101,18]
// Output: 4 
// Explanation: The longest increasing subsequence is [2,3,7,101], 
// therefore the length is 4. 

// time - O(N^2)
// space - O(n)

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)
            return 0;
        int lis[n+1];
        for(int i=0; i<=n; i++)
            lis[i] = 1;
        
        int maxEle = lis[0];
        for(int i=1; i<n; i++)
        {
            for(int j=0; j<i; j++)
            {
                if(nums[i] > nums[j] && lis[i] < lis[j] + 1)
                    lis[i]  = lis[j] + 1;
                maxEle = max(maxEle, lis[i]);
            }
        }
        return maxEle;
    }
};