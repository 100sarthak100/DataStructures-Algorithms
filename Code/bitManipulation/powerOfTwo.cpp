#include <bits/stdc++.h>
using namespace std;

bool powerTwo(int n)
{
    return n&(n-1);
}

int main()
{
    int n = 8;
    if(powerTwo(n))
        cout<<"Not a power of two";
    else cout<<"power of two"<<endl;
}