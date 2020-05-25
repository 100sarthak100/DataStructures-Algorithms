#include <bits/stdc++.h>
using namespace std;

// factors or divisors in increasing order of a number A
vector<int> allFactors(int A)
{
    vector<int> ret, ret2;
    for (int i = 1; i <= sqrt(A); ++i)
    {
        if (A % i == 0)
        {
            if (A / i == i)
                ret.push_back(i);
            else
            {
                ret.push_back(i);
                ret2.push_back(A / i);
            }
        }
    }
    for (int i = ret2.size() - 1; i >= 0; --i)
        ret.push_back(ret2[i]);
    return ret;
}

int main()
{
    int a = 50;
    vector<int> ret = allFactors(a);
    for(auto x : ret)
        cout<<x<<" ";
}