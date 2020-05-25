// inputCopy
// 2
// 1 2
// 1
// 1
// outputCopy
// 1 2
// inputCopy
// 2
// 2 1
// 1
// 1
// outputCopy
// 2 1
// inputCopy
// 3
// 3 1 2
// 3
// 1 2 3
// outputCopy
// 6 6

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i,n) for(ll i=0;i<n;++i)

int main()
{
    int n, m, a[100000], b[100000];
 
    cin>>n;
    vector<ll> numb(n);
    forn(i,n)
    {
        cin>>a[i];
        numb[a[i]-1] = i;
        //cout<<a[i] - 1<<" "<<i<<endl;
    }
    cin>>m;
    ll ansA = 0, ansB = 0;
    forn(i,m)
    {
        cin>>b[i];
        ansA+=numb[b[i]-1]+1;
        ansB+=n-numb[b[i]-1];
    }
    cout<<ansA<<' '<<ansB;
    return 0;
}