// Given a string S, find the longest palindromic substring in S. 
// Substring of string S: S[ i . . . . j ] where 0 ≤ i ≤ j < len(S). 
// Palindrome string: A string which reads the same backwards. More 
// formally, S is palindrome if reverse(S) = S. Incase of conflict, 
// return the substring which occurs first ( with the least starting 
// index ).

// NOTE: Required Time Complexity O(n2).

// Input:
// 1
// aaaabbaa

// Output:
// aabbaa

// Explanation:
// Testcase 1: The longest palindrome string present in the 
// given string is "aabbaa". 

// Time - O(N^2)
// Space - O(1)

#include<iostream>
using namespace std;

string palindrome(string s)
{
    string str;
    if(s.size() == 0)
        return "";
    int n = s.size();
    int maxLen = 1, low, high, start = 0;
    for(int i = 1; i<n; i++)
    {
        low = i-1;
        high = i;
        while(low >= 0 && high < n && s[low] == s[high])
        {
            if(maxLen < high-low+1)
            {
                maxLen = high-low+1;
                start = low;
            }
            low--;
            high++;
        }
        
        low = i-1;
        high = i+1;
        while(low >= 0 && high < n && s[low] == s[high])
        {
            if(maxLen < high-low+1)
            {
                maxLen = high-low+1;
                start = low;
            }
            low--;
            high++;
        }
    }
    for(int i=start; i<start+maxLen; i++)
        str.push_back(s[i]);
    
    return str;
}

int main()
 {
	int t;cin>>t;
	while(t--)
	{
	    string s;
	    cin>>s;
	    cout<<palindrome(s)<<endl;
	}
	return 0;
}