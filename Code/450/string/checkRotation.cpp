// Given a string s1 and a string s2, write a snippet to say whether s2 
// is a rotation of s1?(eg given s1 = ABCD and s2 = CDAB, return true, 
// given s1 = ABCD, and s2 = ACBD , return false)

// Example:                 
//                      str1 = "ABACD"
//                      str2 = "CDABA"

//      temp = str1.str1 = "ABACDABACD"
//      Since str2 is a substring of temp, str1 and str2 are 
//      rotations of each other.

// Time - O(N)
// Space - O(1)

#include <bits/stdc++.h>
using namespace std;

bool checkRotation(string s1, string s2)
{
    if(s1.length() != s2.length())
        return false;
    
    string temp = s1 + s1;
    if(temp.find(s2) != string::npos)
        return true;
    return false;
}

int main()
{
    string str1 = "AACD", str2 = "AEDA";
    cout<<checkRotation(str1, str2)<<endl;
    return 0;
}