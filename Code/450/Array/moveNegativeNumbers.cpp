// Move all negative numbers to beginning and positive to end 
// with constant extra space

// Time - O(n)
// Space - O(1)

#include <bits/stdc++.h>
using namespace std;

void moveNeg(int arr[], int n)
{
    int i = 0, j=n-1;
    while(i < j)
    {
        if(arr[i] < 0)
            i++;
        else
        {
            swap(arr[i], arr[j]);
            j--;
        }
    }
    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    return;
}

int main()
{
    int arr[] = { -1, 2, -3, 4, 5, 6, -7, 8, 9 };
    int n = sizeof(arr) / sizeof(arr[0]);

    moveNeg(arr, n);
    return 0;
}