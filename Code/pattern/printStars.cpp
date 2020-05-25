#include <bits/stdc++.h>
using namespace std;

// half pyramid
void halfPyramid(int rows)
{
    for (int i = 1; i <= rows; i++)
    {
        for (int j = 1; j <= i; j++)
            cout << j << " "; // to print numbers
        // cout<<" * "; to print stars
        cout << endl;
    }
    return;
}

// full pyramid
void fullPyramid(int rows)
{
    for (int i = 1, k = 0; i <= rows; ++i, k = 0)
    {
        for (int space = 1; space <= rows - i; ++space)
            cout << "  ";
        while (k != 2 * i - 1)
        {
            cout << "* ";
            ++k;
        }
        cout << endl;
    }
}

int main()
{
    int rows = 5;
    // halfPyramid(rows);
    fullPyramid(rows);
}