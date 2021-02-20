// Given a string s, find the length of the longest substring without 
// repeating characters.

// Example 1:

// Input: s = "abcabcbb"
// Output: 3
// Explanation: The answer is "abc", with the length of 3.

// Example 2:

// Input: s = "bbbbb"
// Output: 1
// Explanation: The answer is "b", with the length of 1.

// Example 3:

// Input: s = "pwwkew"
// Output: 3
// Explanation: The answer is "wke", with the length of 3.
// Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.

// Example 4:

// Input: s = ""
// Output: 0

// Time - O(N)
// Space - O(K)

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0)
            return 0;
        int i = 0, j = 0, maxLen = INT_MIN;
        unordered_map<char, int> mp;
        
        while(j < s.size())
        {
            mp[s[j]]++;
            if(mp.size() == j - i + 1)
            {
                maxLen = max(maxLen, j-i+1);
                j++;
            }
            else if(mp.size() < j - i + 1)
            {
                while(mp.size() < j - i + 1)
                {
                    mp[s[i]]--;
                    if(mp[s[i]] == 0)
                        mp.erase(s[i]);
                    i++;
                }
                j++;
            }
        }
        return maxLen;
    }
};