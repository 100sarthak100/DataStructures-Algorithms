// Given a string s1 and a string s2, write a snippet to 
// say whether s2 is a rotation of s1?
// (eg given s1 = ABCD and s2 = CDAB, return true, given 
// s1 = ABCD, and s2 = ACBD , return false)

#include <bits/stdc++.h>
using namespace std;

bool isRotate(string s1, string s2)
{
    if(s1.size() != s2.size())
        return false;
    int n = s1.size();
    string temp = s1 + s1;
    return (temp.find(s2) != string::npos);
}

int main()
{
    string str1 = "AACD", str2 = "ACDA";
    if(isRotate(str1, str2))
        cout<<"is rotation"<<endl;
    else
        cout<<"not rotation"<<endl;
}