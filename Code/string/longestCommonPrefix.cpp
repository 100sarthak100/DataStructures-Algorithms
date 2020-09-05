// Write a function to find the longest common prefix string 
// amongst an array of strings.

// If there is no common prefix, return an empty string "".

// Example 1:

// Input: ["flower","flow","flight"]
// Output: "fl"
// Example 2:

// Input: ["dog","racecar","car"]
// Output: ""
// Explanation: There is no common prefix among the input strings.

// Time - O(N M)
// N = Number of strings
// M = Length of the largest common string 
// Space - O(M)

class Solution {
public:
    int min(int a, int b)
    {
        if(a < b)
            return a;
        else
            return b;
    }
    
    int findMinLen(vector<string>& strs)
    {
        int n = strs.size();
        int minLen = INT_MAX;
        for(int i=0; i<n; i++)
            minLen = min(minLen, strs[i].size());
        return minLen;
    }
    
    string longestCommonPrefix(vector<string>& strs) {
        int minLen = findMinLen(strs);
        string ret = "";
        char current;
        int n = strs.size();
        if(n == 0)
            return ret;
        
        for(int i=0; i<minLen; i++)
        {
            current = strs[0][i];
            for(int j=1; j<n; j++)
            {
                if(strs[j][i] != current)
                    return ret;
            }
            ret.push_back(current);
        }
        return ret;
    }
};