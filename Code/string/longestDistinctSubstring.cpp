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