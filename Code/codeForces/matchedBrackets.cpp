#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void checkBrackets(ll arr[], ll n)
{
    vector<ll> ret(n+1, 0);
    ret[0] = arr[0];
    for(ll i=1; i<n; i++)
        ret[i] = ret[i-1] + ((arr[i] == 1) ? 1 : -1); 
    
    for(ll i=0; i<n; i++)
        cout<<ret[i]<<" ";
    cout<<endl;
    
    ll nestingDepth = *max_element(ret.begin(), ret.end());
    ll tempPos = 0;
    ll pos = 0;
    ll maxLen = 0;
    for(ll i=0; i<n; i++)
    {
        if(ret[i] == 0)
        {
            if(maxLen < i - tempPos + 1)
            {
                //cout<<i<<" "<<tempPos<<endl;
                maxLen = i - tempPos + 1;
                pos = tempPos;
            }
            tempPos = i + 1;
        }
        if(maxLen == nestingDepth*2)
            break;
    }
    cout<<nestingDepth<<" "<<(pos+nestingDepth)<<" ";
    maxLen = 0;
    tempPos = 0;
    pos = 0;
    for(ll i=0; i<n; i++)
    {
        if(ret[i] == 0)
        {
            if(maxLen < i - tempPos + 1)
            {
                //cout<<i<<" "<<tempPos<<endl;
                maxLen = i - tempPos + 1;
                pos = tempPos;
            }
            tempPos = i + 1;
        }
    }
    cout<<maxLen<<" "<<pos+1<<endl;
}

int main()
{
    ll n;cin>>n;
    ll arr[n];
    for(ll i=0; i<n; i++)
        cin>>arr[i];
    checkBrackets(arr, n);
}