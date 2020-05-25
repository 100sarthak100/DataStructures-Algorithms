#include <bits/stdc++.h>
using namespace std;

int floorSqrt(int a)
{
    if (a == 1 || a == 0)
        return a;
    int start = 0, end = a / 2, ans;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (mid * mid == a)
            return mid;
        if (mid * mid < a)
        {
            start = mid + 1;
            ans = mid;
        }
        else
            end = mid - 1;
    }
    return ans;
}

int main()
{
    int a = 11;
    cout << floorSqrt(a) << endl;
}