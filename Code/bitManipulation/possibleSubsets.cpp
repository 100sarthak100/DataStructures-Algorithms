#include <bits/stdc++.h>
using namespace std;

void possibleSubsets(char a[], int n)
{
    for (int i = 0; i < (1 << n); i++)
    {
        for (int j = 0; j < n; j++)
            if (i & (1 << j))
                cout << a[j] << " ";
        cout<<endl;
    }
}

int main()
{
    char a[] = {'a', 'b', 'c'};
    int n = 3;
    possibleSubsets(a, n);
}