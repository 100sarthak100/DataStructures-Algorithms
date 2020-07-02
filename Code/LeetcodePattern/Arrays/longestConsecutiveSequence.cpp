// Given an unsorted array of integers, find the length of the 
// longest consecutive elements sequence.

// Example:

// Input: [100, 4, 200, 1, 3, 2]
// Output: 4
// Explanation: The longest consecutive elements sequence is 
// [1, 2, 3, 4]. 
// Therefore its length is 4.

// time - O(N)
// space - O(N)

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        for(auto i : nums)
            st.insert(i);
        
        int longestStreak = 0;
        
        for(auto num : st)
        {
            if(st.find(num - 1) == st.end())
            {
                int currNum = num;
                int currStreak = 1;
                
                while(st.find(currNum  + 1) != st.end())
                {
                    currNum = currNum + 1;
                    currStreak = currStreak + 1;
                }
                
                longestStreak = max(longestStreak, currStreak);
            }
            
        }
        return longestStreak;
    }
};