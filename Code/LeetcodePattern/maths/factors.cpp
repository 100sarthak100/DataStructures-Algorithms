// Time Complexity : O(sqrt(n))
// Auxiliary Space : O(1)

#include <bits/stdc++.h>
using namespace std;

void factors(int n)
{
    vector<int> ret;
    for(int i=1; i*i<=n; i++)
    {
        if(n%i == 0)
        {
            if(n/i == i)
                ret.push_back(i);
            else
            {
                ret.push_back(n/i);
                ret.push_back(i);
            }
        }
    }
    for(auto i : ret)
        cout<<i<<" ";
}

int main()
{
    int n = 100;
    factors(n);
}