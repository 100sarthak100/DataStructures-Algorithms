// G ONE NUMBERS
#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// numbers between range having digit sum as prime (count of that numbers)
// pos = 10, because constraint is upto 10^8 so it has (99999999) pos upto 8 we are taking 
// mas as 10
// sum = 80, max sum of 9*8 = 72, we are taking 80
// tight = 2, can have 1 or 0 as values

// input
// 3
// 10 19
// 1 9
// 20 29

// output
// 4
// 4
// 5

ll dp[10][80][2];
ll prime[]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109};

bool check(ll sum)
{
    for(auto i : prime)
    {
        if(i == sum)
            return 1;
    }
    return 0;
}

ll g(string str, ll pos=0,ll sum=0, ll tight = 1)
{
    if(pos == str.length())
    {
        if(check(sum))
        {
            cout<<sum<<endl;
            return 1;
        }
        else
            return 0;
    }
    else if(dp[pos][sum][tight] != -1)
        return dp[pos][sum][tight];
    else if(tight == 1)
    {
        ll res = 0;
        // eg 3 2 4 5, pos = 0  str[pos] - '0' gives 3
        for(ll i = 0; i<= str[pos] - '0'; i++)
        {
            if(i == str[pos] - '0')
                res += g(str, pos+1, sum+i, 1);
            else
                res += g(str, pos+1, sum+i, 0);
        }
        dp[pos][sum][tight] = res;
        //cout<<pos<<" "<<sum<<" "<<tight<<" "<<res<<endl;
        return res;
    }
    else
    {
        ll res = 0;
        for(ll i=0; i<=9; i++)
        {
            res += g(str, pos+1, sum+i, 0);
        }
        dp[pos][sum][tight] = res;
        return res;
    }
    
}

int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll l,r;
        cin>>l>>r;
        l = l - 1;
        string a = to_string(l);
        string b = to_string(r);
        memset(dp, -1, sizeof(dp)); 
        ll ans1 = g(b);
        memset(dp, -1, sizeof(dp));
        ll ans2 = g(a);
        cout<<ans1<<" "<<ans2<<endl;

        cout<<ans1-ans2<<endl;
    }
}