#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef int ll;
typedef long double ld;
#define N 100005
ll inf = 1e16;
ll mod = 1e9 + 7;
char en = '\n';

ll abs1(ll x)
{
    if (x < 0)
        return -x;
    return x;
}
ll power(ll x, ll n, ll mod)
{
    ll res = 1;
    x %= mod;
    while (n)
    {
        if (n & 1)
            res = (res * x) % mod;
        x = (x * x) % mod;
        n >>= 1;
    }
    return res;
}

bool visited[6][6];
ll r, c;
bool valid(ll i, ll j, ll i1, ll j1)
{

    return !((i == i1) or (j == j1) or ((i + j) == (i1 + j1)) or
             ((i - j) == (i1 - j1)) or visited[i][j]);
}
vector<pair<ll, ll>> curr, res;
bool recur(ll a, ll b, ll cnt)
{
    if (cnt == r * c)
    {
        res = curr;
        return true;
    }
    visited[a][b] = true;
    for (ll i = 1; i <= r; i++)
    {
        for (ll j = 1; j <= c; j++)
        {
            if (valid(i, j, a, b))
            {

                curr.push_back({i, j});
                if (recur(i, j, cnt + 1))
                    return true;
                curr.pop_back();
            }
        }
    }
    visited[a][b] = false;
    return false;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    for (ll i = 1; i <= t; i++)
    {
        cout << "Case #" << i << ": ";
        cin >> r >> c;

        ll flag = 0;
        for (ll i = 1; i <= r; i++)
        {
            for (ll j = 1; j <= c; j++)
            {
                curr.clear();
                memset(visited, false, sizeof(visited));
                curr.push_back({i, j});
                if (recur(i, j, 1))
                {
                    flag = 1;
                    break;
                }
                curr.pop_back();
            }
        }
        if (flag == 1)
        {
            cout << "POSSIBLE" << en;
            for (pair<ll, ll> x : res)
                cout << x.first << " " << x.second << en;
        }
        else
        {
            cout << "IMPOSSIBLE" << en;
        }
    }

    /*
   1
   6
CODEJAM
JAM
HAM
NALAM
HUM
NOLOM
   */
    return 0;
}
