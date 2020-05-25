// Given two strings str1 and str2 and below operations that can 
// performed on str1. Find minimum number of edits (operations) 
// required to convert ‘str1′ into ‘str2′.

// Insert
// Remove
// Replace
// All of the above operations are of cost=1.
// Both the strings are of lowercase.

// Input:
// 1
// 4 5
// geek gesek

// Output:
// 1

// time - O(nm)
// space - O(nm)
// explanation in notebook

#include<iostream>
using namespace std;

int minVal(int a, int b, int c)
{
    if(a < b)
    {
        if(a < c)
            return a;
        else
            return c;
    }
    else
    {
        if(b < c)
            return b;
        else
            return c;
    }
}

int editDistance(string s1, string s2)
{
    int n = s1.length();
    int m = s2.length();
    int dp[n+1][m+1];
    for(int i = 0;i<=n;i++)
        dp[i][0] = i;
    for(int i = 0;i<=m;i++)
        dp[0][i] = i;
        
    for(int i = 1; i<=n; i++)
    {
        for(int j = 1; j<=m;j++)
        {
            if(s1[i-1] == s2[j-1])
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = minVal(dp[i-1][j-1], dp[i][j-1], dp[i-1][j]) + 1;
        }
    }
    return dp[n][m];
}

int main()
 {
    int t;cin>>t;
    while(t--)
    {
        int p, q;
        cin>>p>>q;
        string s1, s2;
        cin>>s1>>s2;
        cout<<editDistance(s1, s2)<<endl;
    }
	return 0;
}