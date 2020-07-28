#include <bits/stdc++.h>
using namespace std;

unsigned int getAbs(int n)
{
    int const mask = n >> (sizeof(int) * 8 - 1);
    return ((n + mask) ^ mask);
}

int main()
{
    int n = -6;
    //cout<<sizeof(int);
    cout<<getAbs(n)<<endl;
}