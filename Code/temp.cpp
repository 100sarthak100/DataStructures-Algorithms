#include <bits/stdc++.h>
using namespace std;

bool isPerfectSquare(int n)
{
    if (n == 0)
        return true;
    for (int i = 1; i * i <= n; i++)
    {

        // If (i * i = n)
        if ((n % i == 0) && (n / i == i))
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int t;
    cin >> t;
    int lt = 0;
    while (t--)
    {
        lt++;
        int n;
        cin >> n;
        int prefixSum[n + 1];
        int count = 0;
        int zeroCount = 0;
        prefixSum[0] = 0;
        int running_total = 0;
        for (int index = 1; index <= n; index++)
        {
            int element;
            cin>>element;
            running_total += element;
            prefixSum[index] = running_total;
        }
        //cout << count << endl;
        for (int prev = 0; prev < n; prev++)
        {
            for (int index = prev + 1; index <= n; index++)
            {
                if (isPerfectSquare(prefixSum[index] - prefixSum[prev]))
                {
                    count++;
                }
            }
        }
        //cout<<zeroCount<<endl;
        if (zeroCount > 1)
            zeroCount--;
        cout << "Case #" << lt << ": " << count << endl;
    }
}