// Given two integers a and b. Your task is to print the sum of
// all the digits appearing in the integers between a and b.

// The Time Complexity will be O(10*pos*sum*tight)
// a = 123, b = 1024
// digit sum for given range : 12613

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll dp[20][180][2];

void toDigit(ll a, vector<ll> &digit)
{
    while (a)
    {
        digit.push_back(a % 10);
        a = a / 10;
    }
}

ll digitSum(vector<ll> &digit, ll pos, ll tight, ll sum)
{
    if (pos == -1)
        return sum;
    if (dp[pos][sum][tight] != -1 && tight != -1)
        return dp[pos][sum][tight];

    ll ret = 0;

    int k = (tight) ? digit[pos] : 9;

    for (ll i = 0; i <= k; i++)
    {
        int newTight = (digit[pos] == i)? tight : 0;

        ret += digitSum(digit, pos-1, newTight, sum+i);
    }

    if(!tight)
        dp[pos][sum][tight] = ret;
    
    return ret;
}

ll rangeDigitSum(int a, int b)
{
    memset(dp, -1, sizeof(dp));

    vector<ll> digitA;
    toDigit(a-1, digitA);
    ll ans1 = digitSum(digitA, digitA.size() - 1, 1, 0);

    vector<ll> digitB;
    toDigit(b, digitB);
    ll ans2 = digitSum(digitB, digitB.size() - 1, 1, 0);

    for(int i = 0; i<20; i++)
    {
        for(int j = 0; j<180; j++)
        {
            for(int x = 0; x<2; x++)
                cout<<i<<" "<<j<<" "<<x<<" "<<dp[i][j][x]<<" ";
            cout<<endl;
        }
    }

    return (ans2 - ans1);
}

int main()
{
    ll a = 123, b = 1024;
    cout << rangeDigitSum(a, b) << endl;
    return 0;
}

