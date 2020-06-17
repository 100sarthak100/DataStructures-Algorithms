#include <bits/stdc++.h>
using namespace std;
#define No_OF_CHARS 256

int longestUniqueSubsttr(string str)
{
    int n = str.size();
    int cur_len = 1;
    int max_len = 1;
    int prev_index;
    int visited[No_OF_CHARS];
    memset(visited, -1, sizeof(visited));
    visited[str[0]] = 0;
    for(int i = 1;i<n;i++)
    {
        prev_index = visited[str[i]];
        // cout<<str[i]<<" "<<visited[str[i]]<<" "<<i-cur_len<<" "<<prev_index<<endl;
        if(prev_index == -1 || i - cur_len > prev_index)
        {
             cur_len++;
             //cout<<cur_len<<endl;
        }
        else
        {
            if(cur_len > max_len)
                max_len = cur_len;
            cur_len = i - prev_index;
        }
        visited[str[i]] = i;
    }
    
    if(cur_len > max_len)
        max_len = cur_len;
    return max_len;
}

int main()
{
    string str = "geeksforgeeks"; 
    cout << "The input string is " << str << endl; 
    int len = longestUniqueSubsttr(str); 
    cout << "The length of the longest non-repeating "
            "character substring is "
        << len; 
    return 0; 
}

// Input: "pwwkew"
// Output: 3
// Explanation: The answer is "wke", with the length of 3. 
//              Note that the answer must be a substring, "pwke" 
//              is a subsequence and not a substring.

// best solution
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    if(s.size() < 2) return s.size();
    bool MAP[256] = {false};
    int start = 0, end = 0, longest = 0;
    while(end < s.size())
    {
        if(MAP[s[end]])
        {
            MAP[s[start]] = false;
            start++;
        }
        else
        {
            MAP[s[end]] = true;
            end++;
            longest = max(longest,end - start);
        }
    }
    return longest;
    }
};