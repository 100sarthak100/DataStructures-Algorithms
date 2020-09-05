// Input:

// 5
// 140 82
// 89 134
// 90 110
// 112 106
// 88 90
// Output:

// 1 58

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    int n;cin>>n;
    ll p1=0, p2=0;
    ll leadScore = 0;
    ll player = 1;
    ll a=0 , b=0;
    for(int i=0; i<n; i++)
    {
        cin>>a>>b;
        p1 += a;
        p2 += b;

        if(p1 > p2)
        {
            if(leadScore < p1-p2)
            {
                leadScore = p1-p2;
                player = 1;
            }
        }
        else
        {
            if(leadScore < p2-p1)
            {
                leadScore = p2-p1;
                player = 2;
            }
        } 
    }
    cout<<player<<" "<<leadScore<<endl;
}