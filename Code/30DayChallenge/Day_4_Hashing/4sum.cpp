// Given an array nums of n integers and an integer target, 
// are there elements a, b, c, and d in nums such that 
// a + b + c + d = target? Find all unique quadruplets in the 
// array which gives the sum of target.

// Note:
// The solution set must not contain duplicate quadruplets.

// Example:
// Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.
// A solution set is:
// [
//   [-1,  0, 0, 1],
//   [-2, -1, 1, 2],
//   [-2,  0, 0, 2]
// ]

// Time - Avg O(N^2), Worst O(N^3)
// Space - O(N^2)
// sort - O(n logn) < O(N^2)
// find for vector - O(N)
// find for map - O(logn)
// find for unordered_map - O(1)

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        unordered_map<int, vector<pair<int, int>>> mp;
        vector<vector<int>> ret;
        vector<int> vec;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i=1; i<n-1; i++)
        {
            for(int j = i+1; j<n; j++)
            {
                int sum = nums[i] + nums[j];
                int diff = target - sum;
                if(mp.find(diff) != mp.end())
                {
                    auto it = mp[diff];
                    for(auto pp : it)
                    {
                        vec = {pp.first, pp.second, nums[i], nums[j]};
                        if(find(ret.begin(), ret.end(), vec) == ret.end())
                            ret.push_back(vec);
                        vec.clear();
                    }
                }
            }
            
            for(int k = 0 ; k<i; k++)
            {
                int sum = nums[i] + nums[k];
                if(mp.find(sum) == mp.end())
                    mp[sum] = {{nums[k], nums[i]}};
                else
                    mp[sum].push_back({nums[k], nums[i]});
                
            }
        }      
        return ret;   
    }
        
};