// Given a set of distinct positive integers, find the largest subset such that every pair (Si, Sj) of elements in this subset satisfies:

// Si % Sj = 0 or Sj % Si = 0.

// If there are multiple solutions, return any subset is fine.

// Example 1:

// Input: [1,2,3]
// Output: [1,2] (of course, [1,3] will also be ok)
// Example 2:

// Input: [1,2,4,8]
// Output: [1,2,4,8]

// Time Complexity : O(n2)
// Auxiliary Space : O(n)

// dp solution
class Solution {
public:
    int max(int a, int b)
    {
        return (a > b) ? a : b;
    }
    
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector<int> ret;
        
        if(n == 0) return ret;
        
        sort(nums.begin(), nums.end());
        
        int count[n];
        for(int i = 0; i<n; i++)
            count[i] = 1;
        
        for(int i = 1; i < n; i++)
        {
            for(int j = i - 1; j >= 0; j--)
            {
                if(nums[i] % nums[j] == 0)
                    count[i] = max(count[i], count[j] + 1);
            }
        }
        
        int maxIndex = 0;
        int maxEle = 0;
        for(int i = 0; i<n; i++)
        {
            if(count[i] > maxEle)
            {
                maxEle = count[i];
                maxIndex = i;
            }
        }
        
        int temp = nums[maxIndex];
        for(int i = maxIndex; i>=0; i--)
        {
            if(temp % nums[i] == 0 && maxEle == count[i])
            {
                ret.push_back(nums[i]);
                temp = nums[i];
                maxEle--;
            }
        }
        return ret;
    }
};