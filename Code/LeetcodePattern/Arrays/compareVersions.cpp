//  version number is a string that is used to identify unique 
//  states of a software product. A version number looks like a.b.c.d 
//  where a, b, etc are number, so the version number is a string in 
//  which numbers are separated by dots. These numbers generally 
//  represent hierarchy 
//  from major to minor (a is major and d is minor).

// Input: 
// V1 = “1.0.31”
// V2 = “1.0.27”
// Output:  v2 is latest
// Because V2 < V1

// Input: 
// V1 = “1.0.10”
// V2 = “1.0.27”
// Output:  v1 is latest
// Because V1 < V2

#include <bits/stdc++.h>
using namespace std;

int compareVer(string s1, string s2)
{
    int num1 = 0, num2 = 0;
    int i=0, j = 0;
    while(i<s1.size() || j<s2.size())
    {
        while(i<s1.size() && s1[i] != '.')
        {
            num1 = 10*num1 + (s1[i] - '0');
            i++;
        }

        while(j<s2.size() && s2[j] != '.')
        {
            num2 = 10*num2 + (s2[j] - '0');
            j++;
        }

        if(num1 > num2)
            return 1;
        if(num2 > num1)
            return -1;
        
        num1 = 0;
        num2 = 0;
        i++;j++;
    }
    return 0;
}

int main()
{
    int t;cin>>t;
    while(t--)
    {
        string s1,s2;
        cin>>s1>>s2;
        int x = compareVer(s1, s2);
        if(x == 1)
            cout<<"s1 > s2"<<endl;
        else if(x == -1)
            cout<<"s2 > s1"<<endl;
        else
            cout<<"s1 == s2"<<endl;
    }
}