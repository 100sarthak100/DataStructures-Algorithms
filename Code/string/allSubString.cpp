#include <bits/stdc++.h>
using namespace std;

void substrPrint(string s)
{
    int n = s.size();
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= n - i; j++)
        {
            cout << s.substr(i, j) << endl;
            count++;
        }
    }
    cout << count << endl;
}

int main()
{
    string s = "abcd";
    substrPrint(s);
}