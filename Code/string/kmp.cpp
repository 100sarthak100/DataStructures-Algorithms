### Longest prefix sufix

// Given a string of character, find the length of longest 
// proper prefix which is also a proper suffix.
// Example:
// S = abab
// lps is 2 because, ab.. is prefix and ..ab is also a suffix.

// Example:
// Input:
// 2
// abab
// aaaa

// Output:
// 2
// 3

// time O(size of string)

// #include<bits/stdc++.h>
// using namespace std;

// int longest(string s)
// {
//     int sz = s.size();
//     int pattern[sz];
//     for(int i=0; i<sz; i++)
//         pattern[i] = -1;
    
//     int j = 0;
//     int i = 1;
//     while(i < sz)
//     {
//         if(s[i] == s[j])
//         {
//             pattern[i] = j;
//             i++;
//             j++;
//         }
//         else if(j > 0)
//             j = pattern[j-1] + 1;
//         else
//             i++;
//     }
    
//     return pattern[sz-1]+1;
// }

// int main()
//  {
// 	int t;cin>>t;
// 	while(t--)
// 	{
// 	    string s;
// 	    cin>>s;
// 	    cout<<longest(s)<<endl;
// 	}
// 	return 0;
// }

### KMP (Knuth Morris Pratt) Pattern Searching

space - O(PSZ)
TIME - O(PSZ + TSZ)

Given a text txt[0..n-1] and a pattern pat[0..m-1], 
write a function search(char pat[], char txt[]) that 
prints all occurrences of pat[] in txt[]. You may assume 
that n > m.
Examples:

Input:  txt[] = "THIS IS A TEST TEXT"
        pat[] = "TEST"
Output: Pattern found at index 10

Input:  txt[] =  "AABAACAADAABAABA"
        pat[] =  "AABA"
Output: Pattern found at index 0
        Pattern found at index 9
        Pattern found at index 12


#include <bits/stdc++.h>
using namespace std;

void computePattern(string pat, int* pattern)
{
    int sz = pat.size();
    for(int i=0; i<=sz; i++)
        pattern[i] = -1;
    int j = 0;
    int i = 1;
    while(i < sz)
    {
        if(pat[i] == pat[j])
        {
            pattern[i] = j;
            i++;
            j++;
        }
        else if(j > 0)
            j = pattern[j-1]+1;
        else
            i++;
    }
    return;
}

bool KMPSearch(string pat, string txt)
{
    int psz = pat.size();
    int tsz = txt.size(); 
    int pattern[psz+1];
    computePattern(pat, pattern);

    // for(int i=0; i<=sz; i++)
    //     cout<<pattern[i]<<" ";

    int i = 0;
    int j = 0;
    int flag = 0;
    while(i < tsz)
    {
        if(pat[j] == txt[i])
        {
            if(j == psz - 1)
            {
                cout<<i-j<<endl;
                for(int x=i-j; x<psz+(i-j); x++)
                    cout<<txt[x];
                cout<<endl;
                flag = 1;
            }
            i++;
            j++;
        }
        else if(j > 0)
            j = pattern[j-1] + 1;
        else
            i++;     
    }
    if(flag == 1)
        return true;
    return false;
}

int main()
{
    string txt = "AABAACAADAABAABA"; 
    string pat = "AABA"; 
    if(KMPSearch(pat, txt))
        cout<<"pattter matched"<<endl;
    else
        cout<<"Not matched"<<endl;
    return 0; 
}

















