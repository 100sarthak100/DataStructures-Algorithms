#include <bits/stdc++.h>
using namespace std;

void subArraySum(int arr[], int n, int sum)
{
    unordered_map<int, int> map;
    int curr_sum = 0;
    for(int i = 0; i < n; i++)
    {
        curr_sum = curr_sum + arr[i];
        if(curr_sum == sum)
        {
            cout<<0<<" "<<i<<endl;
            return;
        }
        if(map.find(curr_sum - sum) != map.end())
        {
            cout<<map[curr_sum - sum] + 1<<" "<<i<<endl;
            return;
        }
        map[curr_sum] = i; 
    }
    cout<<-1<<endl;
    return;
}

int main()
{
    int arr[] = {10, 2, -2, -20, 10}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    int sum = -10; 
    subArraySum(arr, n, sum); 
    return 0; 
}