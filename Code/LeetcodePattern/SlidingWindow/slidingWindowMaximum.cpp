// Given an array nums, there is a sliding window of size k which 
// is moving from the very left of the array to the very right. 
// You can only see the k numbers in the window. Each time the 
// sliding window moves right by one 
// position. Return the max sliding window.

// Example:

// Input: nums = [1,3,-1,-3,5,3,6,7], and k = 3
// Output: [3,3,5,5,6,7] 
// Explanation: 

// Window position                Max
// ---------------               -----
// [1  3  -1] -3  5  3  6  7       3
//  1 [3  -1  -3] 5  3  6  7       3
//  1  3 [-1  -3  5] 3  6  7       5
//  1  3  -1 [-3  5  3] 6  7       5
//  1  3  -1  -3 [5  3  6] 7       6
//  1  3  -1  -3  5 [3  6  7]      7

//  time - O(n)
// sliding window using deque
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        int n = nums.size();
        vector<int> ans;
        if(n < k)
            return ans;
        
        for(int i=0; i<k; i++)
        {
            while(dq.size() && nums[dq.back()] <= nums[i])
                dq.pop_back();
            dq.push_back(i);
        }
        
        ans.push_back(nums[dq.front()]);
        
        for(int i=k; i<n; i++)
        {
            while(dq.size() && dq.front() <= (i - k))
                dq.pop_front();
            while(dq.size() && nums[dq.back()] <= nums[i])
                dq.pop_back();
            dq.push_back(i);
            ans.push_back(nums[dq.front()]);
        }
        
        return ans;
    }
};