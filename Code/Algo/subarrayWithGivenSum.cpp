// Find subarray with given sum | (Nonnegative Numbers)
// Input: arr[] = {1, 4, 20, 3, 10, 5}, sum = 33
// Ouptut: Sum found between indexes 2 and 4
// Explanation: Sum of elements between indices
// 2 and 4 is 20 + 3 + 10 = 33

// Input: arr[] = {1, 4, 0, 0, 3, 10, 5}, sum = 7
// Ouptut: Sum found between indexes 1 and 4
// Explanation: Sum of elements between indices
// 1 and 4 is 4 + 0 + 0 + 3 = 7

// Input: arr[] = {1, 4}, sum = 0
// Output: No subarray found
// Explanation: There is no subarray with 0 sum

//other method is good

#include <bits/stdc++.h>
using namespace std;

int subArraySum(int arr[], int n, int sum)
{
    int curr_sum = arr[0], start = 0, i;
    for(i = 1; i <= n; i++)
    {
        while(curr_sum > sum && start < i - 1)
        {
            curr_sum = curr_sum - arr[start];
            start++;
        }
        if(curr_sum == sum)
        {
            cout<<start+1<<" "<<i<<endl;
            return 1;
        }
        if(i < n)
            curr_sum = curr_sum + arr[i];
    }
    return 0;
}

int main()
{
    int arr[] = {1 ,2 ,3 ,5 ,6 ,7 ,8 ,9 ,10}; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    int sum = 15; 
    subArraySum(arr, n, sum); 
    return 0; 
}