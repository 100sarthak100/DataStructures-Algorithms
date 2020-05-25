#include <bits/stdc++.h>
using namespace std;

void nutsBolts(char nuts[], char bolts[], int n)
{
    unordered_map<char, int> m;

    for (int i = 0; i < n; ++i)
        m[nuts[i]] = i;

    for (int i = 0; i < n; ++i)
    {
        if (m.find(bolts[i]) != m.end())
            nuts[i] = bolts[i];
    }
    for (int i = 0; i < n; ++i)
        cout << nuts[i] << " ";
    cout << endl;
    for (int i = 0; i < n; ++i)
        cout << bolts[i] << " ";
}

int main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        char nuts[n], bolts[n];
        for (int i = 0; i < n; ++i)
            cin >> nuts[i];
        for (int i = 0; i < n; ++i)
            cin >> bolts[i];
        sort(bolts, bolts + n);
        nutsBolts(nuts, bolts, n);
    }
}