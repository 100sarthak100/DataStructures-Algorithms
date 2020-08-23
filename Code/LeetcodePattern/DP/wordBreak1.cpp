// Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

// Note:

// The same word in the dictionary may be reused multiple 
// times in the segmentation.
// You may assume the dictionary does not contain duplicate 
// words.
// Example 1:

// Input: s = "leetcode", wordDict = ["leet", "code"]
// Output: true
// Explanation: Return true because "leetcode" can be segmented 
// as "leet code".
// Example 2:

// Input: s = "applepenapple", wordDict = ["apple", "pen"]
// Output: true
// Explanation: Return true because "applepenapple" can be 
// segmented as "apple pen apple".
//              Note that you are allowed to reuse a dictionary 
//              word.
// Example 3:

// Input: s = "catsandog", wordDict = ["cats", "dog", "sand", 
// "and", "cat"]
// Output: false

class Solution {
public:
    bool isPresent(string s, vector<string>& wordDict)
    {
        int n = wordDict.size();
        for(int i=0; i<n; i++)
        {
            if(wordDict[i] == s)
                return true;
        }
        return false;
    }
    unordered_set<string> st;
    bool wordBreak(string s, vector<string>& wordDict) {
        
        int n = s.size();
        if(n == 0)
            return true;
        
        if(st.find(s) != st.end())
            return false;
        
        for(int i=1; i<=n; i++)
        {
            if(isPresent(s.substr(0, i), wordDict) && wordBreak(s.substr(i, n-i), wordDict))
                return true;
        }
        
        st.insert(s);
        return false;
    }
};