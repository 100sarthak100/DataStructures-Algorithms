// Prime Factorization using Sieve O(log n) for multiple queries
#include <bits/stdc++.h>
using namespace std;

#define MAXN 100001
int spf[MAXN];

void sieve()
{
    spf[1] = 1;
    // marking smallest prime factor for every 
    // number to be itself.
    for(int i = 2; i<MAXN; i++)
        spf[i] = i;

    // separately marking spf for every even 
    // number as 2 
    for(int i = 4; i<MAXN; i+=2)
        spf[i] = 2;

    for(int i = 3; i*i <MAXN; i++)
    {
        if(spf[i] == i)
        {
            for(int j=i*i; j<MAXN; j+=i)
                if(spf[j] == j)
                    spf[j] = i;
        }
    }
}

vector<int> getFactorization(int x)
{
    vector<int> ret;
    while(x != 1)
    {
        ret.push_back(spf[x]);
        x = x / spf[x];
    }
    return ret;
}

int main()
{
    sieve();
    int x = 12246;
    cout<<"prime factorization for "<<x<<" : ";
    vector<int> p = getFactorization(x);

    for(int i = 0;i<p.size(); i++)
        cout<<p[i]<<" ";
    cout<<endl;
    
}