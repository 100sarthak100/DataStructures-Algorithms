#include <bits/stdc++.h>
using namespace std;

bool isPrime(int a)
{
    for(int i=2; i*i<=a; i++)
    {
        if(a%i == 0)
            return false;
    }
    return true;
}

void printPrime(int n)
{
    int count = n;
    int i = 2;
    int x = 0;
    int arr[n+1];
    while(count)
    {
        if(isPrime(i))
        {
            arr[x] = i;
            x++;
            count--;
        }
        i++;
    }
    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";
    return;
}

int main()
{
    int n = 20;
    printPrime(n);
}