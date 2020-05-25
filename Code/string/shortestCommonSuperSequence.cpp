// Given two strings str1 and str2, find the length of the 
// smallest string which has both, str1 and str2 as its sub-sequences.

// Input:
// 2
// abcd xycd
// efgh jghi
// Output:
// 6
// 6

#include<iostream>
using namespace std;

int lcs(string s1, string s2)
{
    int n = s1.length();
    int m = s2.length();
    
    int dp[n+1][m+1];
    for(int i = 0;i<=n;i++)
        for(int j = 0;j<=m;j++)
            dp[i][j] = 0;
            
    for(int i = 1; i<=n;i++)
    {
        for(int j = 1; j<=m;j++)
        {
            if(s1[i-1] == s2[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[n][m];
}

int main()
 {
	int t;cin>>t;
	while(t--)
	{
	    string s1, s2;
	    cin>>s1>>s2;
	    int a = lcs(s1, s2);
	    cout<<s1.length() + s2.length() - a<<endl;
	}
	return 0;
}