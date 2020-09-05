// Shortest subsequence in S that forms T, order of char matters

// Input: 
// S = "abcdebdde", T = "bde"
// Output: "bcde"

// order matters

// Time - O(ST) (worst case), O(S + T) (best case)
// space - O(1)

#include <bits/stdc++.h>
using namespace std;

string minWindow(string s, string t)
{
    int n = s.size();
    int m = t.size();
    int minVal = INT_MAX;
    string ret;
    int j = 0;
    for(int i=0; i<n; i++)
    {
        if(s[i] == t[j])
        {
            j++;
            if(j == m)
            {
                int end = i + 1;
                j--;
                while(j >= 0)
                {
                    if(s[i] == t[j])
                        j--;
                    i--;
                }
                i++;
                j++;
                if(end - i < minVal)
                {
                    minVal = end - i;
                    ret = s.substr(i, minVal);
                    cout<<ret<<endl;
                }
            }
        }
    }
    return ret;
}

int main()
{
    string S = "abcadebddebde", T = "bde";
    cout<<minWindow(S, T)<<endl;
}