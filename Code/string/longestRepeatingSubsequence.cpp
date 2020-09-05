// Given a string str, find length of the longest repeating 
// subseequence such that the two subsequence don’t have same string 
// character at same position, i.e., any i’th character in the two 
// subsequences shouldn’t have the 
// same index in the original string.

// Input:
// 2
// 3
// abc
// 5
// axxxy

// Output:
// 0
// 2

#include<iostream>
#include <string>
using namespace std;

int lrs(string a, string b)
{
    int n = a.size();
    int dp[n+1][n+1];
    
    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=n; j++)
        {
            if(i == 0 || j == 0)
                dp[i][j] = 0;
            else if(a[i-1] == b[j-1] && i != j)
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[n][n];
}

int main()
 {
	int t;cin>>t;
	while(t--)
	{
	    int n;cin>>n;
	    string s;
	    cin>>s;
	    cout<<lrs(s, s)<<endl;
	}
	return 0;
}