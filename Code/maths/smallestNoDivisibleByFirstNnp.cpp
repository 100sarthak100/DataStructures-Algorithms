#include <bits/stdc++.h>
using namespace std;

long long gcd(int a, int b)
{
    if(b == 0) return a;
    return gcd(b, a%b);
}

long long lcm(long long n)
{
    long long ans = 1;
    for(long long i = 1; i<= n;i++)
        ans = (ans*i)/(gcd(ans, i));
    return ans;
}

int main()
{
    long long n = 20; 
    cout << lcm(n); 
    return 0; 
}