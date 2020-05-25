// Input arr[] = {1, 11, 2, 10, 4, 5, 2, 1};
// Output: 6 (A Longest Bitonic Subsequence of length 6 is 1, 2, 10, 4, 2, 1)

#include <bits/stdc++.h>
using namespace std;

int lbs(int arr[], int n)
{
    int lis[n]; // longest increasing subsequence
    int lds[n]; // longest decreasing subsequence
    // initialize lis[i] and lds[i] to 1 cause atleast an
    // array is increasing and decreasing by 1
    for (int i = 0; i < n; ++i)
    {
        lis[i] = 1;
        lds[i] = 1;
    }

    // for lis
    // int arr[] = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5,
    //              13, 3, 11, 7, 15};
    for (int i = 1; i < n; ++i)
    {
        for (int j = 0; j < i; j++)
        {
            //cout<<arr[i]<<" "<<arr[j]<<endl;
            if (arr[i] > arr[j] && lis[i] < lis[j] + 1)
            {
                lis[i] = lis[j] + 1;
                //cout<<lis[i]<<endl;
            }
        }
    }
    for (int i = 0; i < n; ++i)
        cout << lis[i] << " ";
    cout << endl;
    cout << *max_element(lis, lis + n) << endl;

    // for lds
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = n - 1; j > i; j--)
        {
            if (arr[i] > arr[j] && lds[i] < lds[j] + 1)
                lds[i] = lds[j] + 1;
        }
    }
    
    for (int i = 0; i < n; ++i)
        cout << lds[i] << " ";
    cout<<endl;
    cout << *max_element(lds, lds + n) << endl;

    int max = lis[0] + lds[0] - 1;
    for (int i = 0; i < n; ++i)
    {
        if (lis[i] + lds[i] - 1 > max)
            max = lis[i] + lds[i] - 1;
    }
    return max;
}

int main()
{
    int arr[] = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5,
                 13, 3, 11, 7, 15};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Length of LBS is %d\n", lbs(arr, n));
    return 0;
}