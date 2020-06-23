// For example, if Bob came up with the string a="abac", then all the substrings 
// of length 2 of the string a are: "ab", "ba", "ac". 
// Therefore, the string b="abbaac".

// input -
// 4
// abbaac
// ac
// bccddaaf
// zzzzzzzzzz

// output -
// abac
// ac
// bcdaf
// zzzzzz

#include <bits/stdc++.h>
using namespace std;

string shortSub(string s)
{
    string ret = s.substr(0, 2);
    int n = s.size();
    for(int i = 3; i<n; i += 2)
        ret += s[i];

    return ret;
}

int main()
{
    int t;cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        cout<<shortSub(s)<<endl;
    }
}