#include <bits/stdc++.h>
using namespace std;

void printArray(int num)
{
    int i = 0, j = num;
    int l = 1, t = 0, p;
    while (i < j)
    {
        while (t < 4)
        {
            cout << l << " ";
            t++;
            l++;
        }
        cout << endl;
        i++;
        t = 0;
        p = 2 * j + 1;
        while (t < 4)
        {
            cout << p << " ";
            p++;
            t++;
        }
        cout << endl;
        t = 0;
        l = p;
        j = num / 2;
    }
}

int main()
{
    int num = 4;
    printArray(num);
}