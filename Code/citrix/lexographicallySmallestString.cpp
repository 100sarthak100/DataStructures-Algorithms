// Lexicographically smallest string of length N and sum K

// Given two integers N and K. The task is to print the 
// lexicographically smallest string of length N consisting 
// of lower-case English alphabates such that the sum of the 
// characters of the string equals to K where ‘a’ = 1, ‘b’ = 2, 
// ‘c’ = 3, ….. and ‘z’ = 26.

// Examples:

// Input: N = 5, K = 42
// Output: aaamz
// “aaany”, “babmx”, “aablz” etc. are also valid strings
// but “aaamz” is the lexicographically smallest.

// Input: N = 3, K = 25
// Output: aaw

#include <bits/stdc++.h>
using namespace std;

string lexo_small(int n, int k)
{
    string arr = "";
    for(int i=0; i<n; i++)
        arr += 'a';
    
    for(int i = n-1; i>=0; i--)
    {
        k -= i;

        if(k >= 0)
        {
            if(k >= 26)
            {
                arr[i] = 'z';
                k -= 26;
            }
            else
            {
                char c = (char)(k + 97 - 1);
                arr[i] = c;
                k -= arr[i] - 'a' + 1;
            }
        }
        else
            break;
        
        k += i;
    }
    return arr;
}

int main()
{
    int n = 5, k = 42; 
    string arr = lexo_small(n, k); 
    cout << arr; 
}