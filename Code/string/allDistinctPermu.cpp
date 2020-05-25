#include <bits/stdc++.h>
using namespace std;

void swap(char *a, char *b)
{
    char t = *a;
    *b = *b;
    *b = t;
}

// prints duplicates (not distinct permutation)
void permut(string s, int l, int r)
{
    if (l == r)
        cout << s << endl;
    else
    {
        for (int i = l; i <= r; ++i)
        {
            swap(s[l], s[i]);
            permut(s, l + 1, r);
            swap(s[l], s[i]);
        }
    }
}

// Print all distinct permutation of a string having duplicates.
// Input:  str[] = "ABCA"
// Output: AABC AACB ABAC ABCA ACBA ACAB BAAC BACA
//         BCAA CABA CAAB CBAA

bool shouldSwap(string s, int start, int curr)
{
    for (int i = start; i < curr; i++)
        if (s[i] == s[curr])
            return 0;
    return 1;
}

void findPermuAlt(string s, int index, int n)
{
    if (index >= n)
    {
        cout << s << endl;
        return;
    }
    for (int i = index; i <= n; i++)
    {
        bool check = shouldSwap(s, index, i);
        if (check)
        {
            swap(s[index], s[i]);
            findPermuAlt(s, index + 1, n);
            swap(s[index], s[i]);
        }
    }
}

// Permutation in lexicographic order
int findCeil(string s, char first, int l, int h)
{
    int ceilIndex = 1;
    for (int i = l + 1; i <= h; i++)
        if (s[i] > first && s[i] < s[ceilIndex])
}

void sortedPermutation(string s)
{
    int size = s.size();
    sort(s.begin(), s.end());
    bool isFinished = false;
    while (!isFinished)
    {
        cout << s << " ";
        for (int i = size - 2; i >= 0; --i)
            if (s[i] < s[i + 1])
                break;

        if (i == -1)
            isFinished = true;
        else
        {
            int ceilIndex = findCeil(s, s[i], i + 1, size - 1);
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int n = s.size();
        permut(s, 0, n - 1);
        cout << endl;
        findPermuAlt(s, 0, n - 1);
    }
}