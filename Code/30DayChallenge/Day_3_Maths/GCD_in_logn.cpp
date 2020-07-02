// GCD(10, 15) = 5
// GCD(35, 10) = 5
// GCD(31, 2) = 1

// Euclidean algorithm basic
#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    if(b == 0)
        return a;
    return gcd(b, a%b);
}

int main()
{
    int a = 36;
    int b = 60;
    cout<<gcd(a, b)<<endl;
}