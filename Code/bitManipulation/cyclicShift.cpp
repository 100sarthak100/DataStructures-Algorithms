#include <bits/stdc++.h>
using namespace std;
#define INT_BITS 32

int leftRotate(int n, unsigned int d)
{
    // in n<<d, last d bits are 0, to put first 3
    // bits of n at last, do bitwise or of n<<d
    // with n >> (INT_BITS - d)
    return (n<<d)|(n >> (INT_BITS - d));
}

int rightRotate(int n, unsigned int d)
{
    return (n>>d)|(n<<(INT_BITS - d));
}

int main()
{
    int n = 7881;
    int d = 5;
    cout<<"left rotation of "<<n<<" by "<<d<<" is ";
    cout<<leftRotate(n,d);
}