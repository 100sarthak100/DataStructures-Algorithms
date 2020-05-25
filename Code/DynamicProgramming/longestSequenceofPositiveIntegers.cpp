#include <bits/stdc++.h>
using namespace std;

void getLongestSeq(int a[], int n)
{
    int maxIdx = 0, maxLen = 0, currLen = 0, currIdx = 0;

    for (int k = 0; k < n; k++)
    {
        if (a[k] > 0)
        {
            currLen++;

            if (currLen == 1)
                currIdx = k;
        }

        else
        {
            if (currLen > maxLen)
            {
                maxLen = currLen;
                maxIdx = currIdx;
            }
            currLen = 0;
        }
    }
    if(maxLen > 0)
        cout<<"length "<<maxLen<<" , starting index"<<maxIdx<<endl;

    return;
}
int main()
{
    int arr[] = {1, 2, -3, 2, 3, 4, -6,
                 1, 2, 3, 4, 5, -8, 5, 6};
    int n = sizeof(arr) / sizeof(int);
    getLongestSeq(arr, n);
    return 0;
}