#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;

    getline(cin, s);

    string ret = "";
    map<string, int> m;
    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] != ' ')
        {
            ret += s[i];
        }
        if (s[i] == ' ' || s[i] == '\n' || i == s.size() - 1)
        {

            m[ret]++;
            ret.clear();
        }
    }
    int max = INT_MIN;
    string word;
    for (auto x : m)
    {
        cout << x.first << " -> " << x.second << endl;
        if (x.second > max)
        {
            max = x.second;
            word = x.first;
        }
    }
    cout << word << " " << max << endl;
}