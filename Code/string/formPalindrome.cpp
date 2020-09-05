// Given a string, find the minimum number of characters to be 
// inserted to convert it to palindrome.
// For Example:
// ab: Number of insertions required is 1. bab or aba
// aa: Number of insertions required is 0. aa
// abcd: Number of insertions required is 3. dcbabcd

// Input:
// 3
// abcd
// aba
// geeks

// Output:
// 3
// 0
// 3

#include<bits/stdc++.h>
using namespace std;

int checkPalindrome(string a, string b)
{
    int n = a.size();
    int m = b.size();
    int dp[n+1][m+1];
    
    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=m; j++)
        {
            if(i == 0 || j == 0)
                dp[i][j] = 0;
            else if(a[i-1] == b[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    //cout<<dp[n][m];
    return n - dp[n][m];
}

int main()
 {
	int t;cin>>t;
	while(t--)
	{
	    string a;
	    cin>>a;
	    string b = a;
	    reverse(a.begin(), a.end());
	    cout<<checkPalindrome(a, b)<<endl;
	}
	return 0;
}

