// Given a string of S as input. Your task is to write a program 
// to remove or delete minimum number of characters from the string 
// so that the resultant string is palindrome.

// Note: The order of characters in the string should be maintained.

// Input:
// 2
// aebcbda
// geeksforgeeks
// Output:
// 2
// 8

// Time - O(N*N)

// It is same as min Insertion to make string Palindrome

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

void swap(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

string reverse(string a)
{
    int i = 0;
    int j = a.size() - 1;
    
    while(i < j)
    {
        swap(&a[i], &a[j]);
        i++;
        j--;
    }
    return a;
}

int minDel(string a)
{
    int n = a.size();
    string b = reverse(a);
    int l = lcs(a, b);
    return (n - l);
}

int main()
 {
	int t;cin>>t;
	while(t--)
	{
	    string s;
	    cin>>s;
	    cout<<minDel(s)<<endl;
	}
	return 0;
}