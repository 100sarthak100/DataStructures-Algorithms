// Given two strings ‘str1’ and ‘str2’ of size m and n respectively. 
// The task is to remove/delete and insert minimum number of 
// characters from/in str1 so as to transform it into str2. It 
// could be possible that the same character needs to be 
// removed/deleted from one point of str1 and 
// inserted to some another point.

// Input:
// 1
// 4 3
// heap pea 

// Output:
// 3

// Time Complexity: O(m * n)

#include<iostream>
#include <string>
using namespace std;

int lcs(string a, string b)
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
    return dp[n][m];
}

int minNumber(string s1, string s2)
{
    int n = s1.size();
    int m = s2.size();
    int l = lcs(s1, s2);
    return (n - l + m - l);
}

int main()
 {
	int t;cin>>t;
	while(t--)
	{
	    int n, m;
	    cin>>n>>m;
	    string s1, s2;
	    cin>>s1>>s2;
	    cout<<minNumber(s1, s2)<<endl;
	}
	return 0;
}