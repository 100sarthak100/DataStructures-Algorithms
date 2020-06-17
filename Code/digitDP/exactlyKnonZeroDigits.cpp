#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// ll k_nonzer0_numbers(string s, ll n, ll k)
// {
//     ll dp[n+1][2][k+1];

//     //memset(dp, 0, sizeof(dp));
    
//     for (int i = 0; i <= n; i++) 
//         for (int j = 0; j < 2; j++) 
//             for (int x = 0; x <= k; x++) 
//                 dp[i][j][x] = 0; 
  
//     dp[0][0][0] = 1;

//     for(ll i=0; i<n; i++)
//     {
//         ll sm = 0;
//         while(sm < 2)
//         {
//             for(ll j=0; j<k+1; j++)
//             {
//                 ll x = 0;
//                 while(x <= (sm ? 9 : s[i] - '0'))
//                 {
//                     dp[i+1][sm || x < (s[i] - '0')][j + (x > 0)]
//                         += dp[i][sm][j];
//                     ++x;
//                 }
//             }
//             ++sm;
//         }
//     }
//     return dp[n][0][k] + dp[n][1][k];
// }

#define ll long long int
ll countString(string s, ll n, ll k)
{
    ll dp[n+1][2][k+1];

    memset(dp, 0, sizeof(dp));
    dp[0][0][0] = 1;

    for(ll i=0; i<n; i++)
    {
        ll sm = 0;
        while(sm < 2)
        {
            for(ll j=0; j<k+1; j++)
            {
                ll x = 0;
                while(x <= (sm ? 9 : s[i] - '0'))
                {
                    dp[i+1][sm || x < (s[i] - '0')][j + (x > 0)]
                        += dp[i][sm][j];
                    ++x;
                }
            }
            ++sm;
        }
    }
    return dp[n][0][k] + dp[n][1][k];
}

int getNumberOfIntegers(string L, string R, int K) {
    //ll num1 = stoi(L); 
    //cout<<L<<endl;
    //num1 = num1-1;
    //L = to_string(num1);
    //cout<<L<<endl;
    ll n1 = L.size();
    ll n2 = R.size();
    ll ans1 = countString(L, n1, K);
    ans1 = ans1%(10000000007);
    ll ans2 = countString(R, n2, K);
    ans2 = ans2%(10000000007);
    return (ans2 - ans1)%(10000000007);
}


int main()
{
    string L = "2";
    string R = "15";
    int K = 1;
    cout<<getNumberOfIntegers(L, R, K)<<endl;
    return 0;
}




