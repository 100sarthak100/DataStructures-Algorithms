// Sample input 1
// 7 4
// 3 1 2 1 4 0 1
// 3 2 2 2 2 4 1 3 1 4 0

// Sample output 1
// 2 1 3 1 4 0 1

// Sample input 2
// 3 5
// 2 5 2
// 3 2 4 2 2 2 1 4 1 1 1 1 0

// Sample output 2
// 1 5 2 

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll n, h;
    cin>>n>>h;
    ll boxStack[n];
    for(ll i=0; i<n; i++)
        cin>>boxStack[i];
    bool flag = true;
    bool pickUp = false;
    ll a = 0;
    ll i = 0;
    while(flag)
    {
        cin>>a;
        if(a == 0)
            break;
        else if(a == 1 && i > 0)
            i--;
        else if(a == 2 && i < n-1)
            i++;
        else if(a == 3 && pickUp == false)
        {
            if(boxStack[i] > 0)
            {
                boxStack[i]--;
                pickUp = true;
            }
        }
        else if(a == 4 && pickUp == true)
        {
            if(boxStack[i] < h)
            {
                boxStack[i]++;
                pickUp = false;
            }
        }
    }
    for(ll i=0; i<n; i++)
        cout<<boxStack[i]<<" ";
}