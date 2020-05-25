#include <bits/stdc++.h>
using namespace std;

// max non negative contagious subarray sum
void maxSubArray(int arr[], int n)
{
    int max_soFar = INT_MIN;
    int currMax = 0;
    int start = 0, end = 0, s = 0;
    for (int i = 0; i < n; ++i)
    {
        currMax += arr[i];
        if (max_soFar < currMax)
        {
            max_soFar = currMax;
            start = s;
            end = i;
        }
        if (currMax < 0)
        {
            currMax = 0;
            s = i + 1;
        }
    }
    cout << max_soFar << endl;
    cout << start << " " << end << endl;
    for (int i = start; i <= end; ++i)
        cout << arr[i] << " ";
}

int main()
{
    int arr[] = {1 ,2 ,3 ,-2 ,5};
    // int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(arr) / sizeof(arr[0]);
    maxSubArray(arr, n);
}

// considering negative numbers also
int maxSubarraySum(int arr[], int n){
    
    int cur_sum = 0;
    int max_sum = INT_MIN;
    int start = 0, s = 0, end = 0;
    int flag = 0;
    for(int i = 0;i<n;i++)
    {
        if(arr[i] > 0)
            flag = 1;
    }
    
    if(flag == 0)
    {
        return *max_element(arr, arr+n);
    }
    
    for(int i = 0;i<n;i++)
    {
        cur_sum += arr[i];
        if(cur_sum > max_sum)
        {
            max_sum = cur_sum;
            start = s;
            end = i;
        }
        if(cur_sum < 0)
        {
            cur_sum = 0;
            s = i + 1;
        }
    }
    //cout<<start<<" "<<end<<endl;
    return max_sum;  
}