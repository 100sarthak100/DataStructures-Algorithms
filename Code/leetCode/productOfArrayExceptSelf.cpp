#include <bits/stdc++.h>
using namespace std;
#define EPS 1e-9

// didn't work for {0,0}
void productPuzzle(int a[], int n)
{
    long double sum = 0;
    for (int i = 0; i < n; i++)
        sum += (long double)log10(a[i]);
    cout << sum << endl;

    for (int i = 0; i < n; i++)
        cout << (int)(EPS + pow((long double)10.00,
                                sum - log10(a[i])))
             << " ";
}

void productArray(int arr[], int n)
{
    if (n == 1)
    {
        cout << 0;
        return;
    }
    int i, temp = 1;
    vector<int> prod(n, 1);
    for (i = 0; i < n; i++)
    {
        prod[i] = temp;
        temp *= arr[i];
    }
    for (int i = 0; i < n; i++)
        cout << prod[i] << " ";
    cout << endl;
    temp = 1;
    for (i = n - 1; i >= 0; i--)
    {
        prod[i] *= temp;
        temp *= arr[i];
    }
    for (int i = 0; i < n; i++)
        cout << prod[i] << " ";
    return;
}

int main()
{
    int a[] = {10, 3, 5, 6, 2};
    int n = sizeof(a) / sizeof(a[0]);
    cout << "The product array is: \n";
    productArray(a, n);
    return 0;
}