// Given n pairs of parentheses, write a function to generate 
// all combinations of well-formed parentheses.

// For example, given n = 3, a solution set is:

// [
//   "((()))",
//   "(()())",
//   "(())()",
//   "()(())",
//   "()()()"
// ]

// Time Complexity: O(2^n).
// For every index there can be two options ‘{‘ or ‘}’. So it 
// can be said that the upperbound of time 
// complexity is O(2^n) or it has exponential time complexity.
// Space Complexity: O(n).
// The space complexity can be reduced to O(n) if global 
// variable or static variable is used to store the output string.

class Solution {
public:
    void para(int n, int open, int close, vector<string> &ret, string &vec)
    {
        if(close == n)
        {
            ret.push_back(vec);
            return;
        }
        else
        {
            if(open > close)
            {
                vec += ')';
                para(n, open, close+1, ret, vec);
                vec.pop_back();
            }
            
            if(open < n)
            {
                vec += '(';
                para(n, open+1, close, ret, vec);
                vec.pop_back();
            }
        }
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        string vec;
        para(n, 0, 0, ret, vec);
        return ret;
    }
};