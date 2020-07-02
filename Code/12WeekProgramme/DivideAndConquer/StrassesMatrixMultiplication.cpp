// Given two square matrices A and B of size n x n each, find their 
// multiplication matrix.

// naive method
// output -
// 12 12
// 12 12

// time - O(N^3)

#include <bits/stdc++.h>
using namespace std;
#define n 2
int c[n][n];

void multiply(int a[][n], int b[][n])
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            c[i][j] = 0;
            for(int k=0; k<n; k++)
                c[i][j] += a[i][k]*b[k][j];
        }
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
            cout<<c[i][j]<<" ";
        cout<<endl;
    }
}

int main()
{
    int a[][n] = { {2,2}, {2, 2}};
    int b[][n] = { {3,3}, {3, 3}};
    multiply(a, b);
}

// starssen's emthod
// todo