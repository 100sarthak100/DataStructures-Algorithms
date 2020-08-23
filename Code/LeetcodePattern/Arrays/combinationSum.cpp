// Given a set of candidate numbers (candidates) (without duplicates) and 
// a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.

// The same repeated number may be chosen from candidates unlimited 
// number of times.

// Example 1:

// Input: candidates = [2,3,6,7], target = 7,
// A solution set is:
// [
//   [7],
//   [2,2,3]
// ]
// Example 2:

// Input: candidates = [2,3,5], target = 8,
// A solution set is:
// [
//   [2,2,2,2],
//   [2,3,3],
//   [3,5]
// ]

// combination sum 1

class Solution {
public:
    void func(vector<int>& arr, int target, int &sum, int &index, vector<int> &vec, vector<vector<int>> &ret, int n)
    {
        if(sum == target)
        {
            ret.push_back(vec);
            return;
        }
        
        if(sum > target || index >= n)
            return;
        
        for(int i=index; i<n; i++)
        {
            sum += arr[i];
            vec.push_back(arr[i]);
            func(arr, target, sum, i, vec, ret, n);
            sum -= arr[i];
            vec.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        int index = 0;
        vector<int> vec;
        vector<vector<int>> ret;
        int sum = 0;
        int n = candidates.size();
        func(candidates, target, sum, index, vec, ret, n);
        return ret;
    }
};









// Combination sum 2

// Given a collection of candidate numbers (candidates) and a 
// target number (target), find all unique combinations in candidates where the candidate numbers sums to target.

// Each number in candidates may only be used once in the 
// combination.

// Example 1:

// Input: candidates = [10,1,2,7,6,1,5], target = 8,
// A solution set is:
// [
//   [1, 7],
//   [1, 2, 5],
//   [2, 6],
//   [1, 1, 6]
// ]
// Example 2:

// Input: candidates = [2,5,2,1,2], target = 5,
// A solution set is:
// [
//   [1,2,2],
//   [5]
// ]

class Solution {
public:
    void func(vector<int> &arr, int target, int &sum, int index, vector<int> &vec, vector<vector<int>> &ret, int n)
    {
        if(sum == target && find(ret.begin(), ret.end(), vec) == ret.end())
        {
            ret.push_back(vec);
            return;
        }
        
        if(sum > target || index >= n)
            return;
        
        for(int i=index; i<n; i++)
        {
            sum += arr[i];
            vec.push_back(arr[i]);
            func(arr, target, sum, i+1, vec, ret, n);
            sum -= arr[i];
            vec.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> vec;
        vector<vector<int>> ret;
        int sum = 0;
        int index = 0;
        int n = candidates.size();
        sort(candidates.begin(), candidates.end());
        func(candidates, target, sum, index, vec, ret, n);
        return ret;
    }
};