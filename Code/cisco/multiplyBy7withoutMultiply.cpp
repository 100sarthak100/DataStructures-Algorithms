#include <bits/stdc++.h>
using namespace std;

int multiply(int n)
{
    return ((n<<3) - n);
}

// for multiplying by 8 just do (n<<3)
// 2^3 = 8, so

// for multiply by 7 do ((n<<3) - n)
// for multiply by 6 do ((n<<3) - n - n)

// for multiply by 14 do ((n<<4) - n - n)
// for multiply by 15 do ((n<<4) - n)
int main()
{
    int n = 4;
    cout<<multiply(n)<<endl;
}

