// input -
// 1
// agbcba

// output -
// 5

#include<bits/stdc++.h>
using namespace std;

int lps(string a, string b)
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
    //cout<<dp[n][m]<<endl;
    return dp[n][m];
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
        //cout<<a<<" "<<b<<endl;
	    cout<<lps(a, b)<<endl;
	}
	return 0;
}