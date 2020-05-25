#include <bits/stdc++.h>
using namespace std;

string toBinary(int n)
{
    string ret;
    int r, q;
    q = n / 2;
    r = n % 2;
    ret.push_back(r);
    while (q > 0)
    {
        r = q % 2;
        ret.push_back(r);
        q = q / 2;
    }
    /*    6 / 2 R0 Q3 3 / 2 R1 Q1 1 / 2 R1 Q0*/
    return ret;
}

int main()
{
    int n = 6;
    cout << toBinary(n) << endl;
}