// Given two strings in lowercase, your task is to 
// find minimum number of manipulations required to make two strings 
// anagram without deleting any character. If two strings contains 
// same data set in any order then strings are called Anagrams.

// Input : 
//        s1 = "aba"
//        s2 = "baa"
// Output : 0
// Explanation: Both String contains identical characters

// Input :
//        s1 = "ddcf"
//        s2 = "cedk"
// Output : 2
// Explanation : Here, we need to change two characters
// in either of the strings to make them identical. We 
// can change 'd' and 'f' in s1 or 'e' and 'k' in s2.

// Time Complexity : O(n), where n is the length of the string.

// deletion of char is not allowed
#include<bits/stdc++.h>
using namespace std;

int oper(string a, string b)
{
    char arr[27];
    for(int i=0; i<27; i++)
        arr[i] = 0;
    
    int n = a.size();
    for(int i = 0; i<n; i++)
        arr[a[i] - 'a']++;
    
    int count = 0;
    for(int i=0; i<n; i++)
    {
        arr[b[i] - 'a']--;
        if(arr[b[i] - 'a'] < 0)
            count++;
    }
    return count;
}

int main()
 {
	int t;cin>>t;
	while(t--)
	{
	    int n;cin>>n;
	    string a, b;
	    cin>>a>>b;
	    cout<<oper(a, b)<<endl;
	}
	return 0;
}