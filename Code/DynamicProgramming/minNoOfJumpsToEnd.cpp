#include <bits/stdc++.h>
using namespace std;

// Returns minimum number of jumps to reach arr[n-1] from arr[0]
// int minJumps(int arr[], int n)
// {
//     if (n <= 1)
//         return 0;
//     if (arr[0] == 0)
//         return -1;
//     int maxReach = arr[0];
//     int step = arr[0];
//     int jump = 1;

//     int i = 1;
//     for (i = 1; i < n; i++)
//     {
//         if (i == n - 1)
//             return jump;
//         maxReach = max(maxReach, i + arr[i]);
//         step--;
//         if (step == 0)
//         {
//             jump++;
//             if (i >= maxReach)
//                 return -1;
//             step = maxReach - i;
//         }
//     }
//     return -1;
// }

// int dpSoln(int arr[], int n)
// {
//     int jump[n];
//     int i, j;
//     if (n == 0 || arr[0] == 0)
//         return INT_MAX;
//     jump[0] = 0;

//     for (i = 1; i < n; i++)
//     {
//         jump[i] = INT_MAX;
//         for (int j = 0; j < i; j++)
//         {
//             if (i <= j + arr[j] && jump[j] != INT_MAX)
//             {
//                 jump[i] = max(jump[i], jump[i] + 1);
//                 break;
//             }
//         }
//     }
//     return jump[n - 1];
// }

// another solution dp
int minJumps(int arr[], int n)
{
    if(n == 0 || arr[0] == 0)
        cout<<"no sol"<<endl;
    int dp[n];
    int jumpFrom[n];
    for(int i = 0;i<n;i++)
        dp[i] = INT_MAX;
    dp[0] = 0;
    jumpFrom[0] = 0;

    for(int i = 1; i<n;i++)
    {
        for(int j = 0;j<i;j++)
        {
            if(arr[j] + j >= i)
            {
                //dp[i] = min(dp[i], 1 + dp[j]);
                if(dp[i] > 1 + dp[j])
                {
                    dp[i] = 1 + dp[j];
                    jumpFrom[i] = j;
                }
            }
        }
    }
    for(int i = 0;i<n;i++)
        cout<<dp[i]<<" ";
    cout<<endl;
    int a = n-1;
    stack<int> st;
    while(a != 0)
    {
        st.push(jumpFrom[a]);
        a = jumpFrom[a];
    }
    while(!st.empty())
    {
        cout<<st.top()<<" -> ";
        st.pop();
    }
    cout<<n-1;
    cout<<endl;
    if(dp[n-1] < 0 || dp[n-1] == INT_MAX)
        return -1;
    return dp[n-1];
}

int main()
{
    int arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
    //int arr[] = {2,3,1,1,4};
    int size = sizeof(arr) / sizeof(int);

    // Calling the minJumps function
    cout << ("Minimum number of jumps to reach end is %d ", minJumps(arr, size));
    return 0;
}