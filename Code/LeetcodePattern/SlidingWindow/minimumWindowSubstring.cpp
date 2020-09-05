// Given a string S and a string T, find the minimum window in 
// S which will contain 
// all the characters in T in complexity O(n).

// Order of chars doesn't matters

// Example:

// Input: S = "ADOBECODEBANC", T = "ABC"
// Output: "BANC"
// Note:

// If there is no such window in S that covers all characters in T, 
// return the empty string "".
// If there is such window, you are guaranteed that there will always 
// be only one unique minimum window in S.

// B - len of bigger string
// S - len of smaller string
// time - O(B + S)
// space - O(B + S)

class Solution {
public:
    bool isValid(unordered_map<char, int> &temp, unordered_map<char, int> &mp)
    {
        for(auto i : mp)
        {
            if(temp[i.first] < i.second)
                return false;
        }
        return true;
    }
    
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        
        unordered_map<char, int> mp;
        for(auto i : t)
            mp[i]++;
        
        unordered_map<char, int> temp;
        
        int start = 0;
        int minVal = INT_MAX;
        string vec;
        string ret;
        
        while(start < n)
        {
            vec += s[start];
            temp[s[start]]++;
            while(vec.size() >= m && isValid(temp, mp))
            {
                if(vec.size() < minVal)
                {
                    minVal = vec.size();
                    ret = vec;
                }
                char c = vec[0];
                vec.erase(vec.begin());
                temp[c]--;
            }
            start++;
        }
        return ret;
    }
};