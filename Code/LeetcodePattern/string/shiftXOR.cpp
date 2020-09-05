#include <bits/stdc++.h>
using namespace std;

string shiftByOne(string s)
{
    int n = s.size();
    int temp = s[n-1];
    for(int i=n-1; i>0; i--)
        s[i-1] = s[i];
    s[0] = temp;
    return s;
}

string shiftXOR(string s, int k)
{
    string ret;
    for(int i=0; i<k; i++)
    {
        string temp = shiftByOne(s);
        cout<<temp<<endl;
    }
    return ret;
}

int main()
{
    string s = "10101";
    int k = 3;
    cout<<shiftXOR(s, k)<<endl;
}