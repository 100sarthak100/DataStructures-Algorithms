// Input:
// 2
// testsample
// output

// Output:
// e
// t

// Explanation:
// Testcase 1: e is the character which is having highest frequency.
// Testcase 2: t and u are the characters with the same frequency, 
// but t is lexicographically smaller.

#include<bits/stdc++.h>
using namespace std;

void countStr(string s)
{
    int freq[256];
    memset(freq, 0, sizeof(freq));
    
    int n = s.size(), maxVal = 0;
    char maxChar;
    for(int i=0; i<n; i++)
    {
        freq[s[i]]++;
    }
        
    for(int i=0; i<n; i++)
    {
        if(freq[s[i]] > maxVal)
        {
            maxVal = freq[s[i]];
            maxChar = s[i];
        }
        else if(freq[s[i]] == maxVal)
        {
            if(s[i] < maxChar)
                maxChar = s[i];
        }
    }
    cout<<maxChar;
}

int main()
 {
	int t;cin>>t;
	while(t--)
	{
	    string s;
	    cin>>s;
	    countStr(s);
	    cout<<endl;
	}
	return 0;
}