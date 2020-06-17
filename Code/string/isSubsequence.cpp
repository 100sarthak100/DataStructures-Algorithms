// Input: s = "abc", t = "ahbgdc"
// Output: true

// Input: s = "axc", t = "ahbgdc"
// Output: false

// Given a string s and a string t, check if s is subsequence of t.

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = s.size();
        int m = t.size();
        if(n > m)
            return false;
        
        int j = 0;
        for(int i = 0; i < m ; i++)
        {
            if(s[j] == t[i])
                j++;
        }
        if(j == n)
            return true;
        else return false;
    }
};