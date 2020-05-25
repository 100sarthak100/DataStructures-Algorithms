// count number of subsequences of the form a^i b^j c^k
// Input  : abbc
// Output : 3
// Subsequences are abc, abc and abbc

#include <iostream>
#include <map>
using namespace std;

int subSequence(string s)
{
    int aCount = 0;
    int bCount = 0;
    int cCount = 0;

    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] == 'a')
            aCount = 1 + 2 * aCount;
        else if (s[i] == 'b')
            bCount = aCount + 2 * bCount;
        else if (s[i] == 'c')
            cCount = bCount + 2 * cCount;
    }
    return cCount;
}

int main()
{
    int t;
    cin >> t;
    map<char, int> m;
    while (t--)
    {
        string s;
        cin >> s;
        cout << subSequence(s) << endl;
        ;
    }
}