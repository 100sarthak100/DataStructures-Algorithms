// 2
// 4
// 1 6 5 11
// 4
// 36 7 46 40

// Output : 
// 1
// 23

// Explaination :
// Testcase 1:
// Subset1 = {1, 5, 6} ; sum of Subset1 = 12
// Subset2 = {11} ;       sum of Subset2 = 11

// Testcase 2:
// Subset1 = {7, 46} ;   sum = 53
// Subset2 = {36, 40} ; sum = 76

// Time Complexity = O(n*sum) where n is number of elements and 
// sum is sum of all elements.

// #include <bits/stdc++.h>
// using namespace std;

// vector<int> subsetSum(int arr[], int n, int sum)
// {
//     bool dp[n+1][sum+1];
//     for(int i = 0;i<=n;i++)
//         dp[i][0] = true;

//     for(int j = 1; j<=sum; j++)
//         dp[0][j] = false;

//     for(int i = 1;i <=n; i++)
//     {
//         for(int j = 1; j<=sum;j++)
//         {
//             if(j >= arr[i-1])
//                 dp[i][j] = dp[i-1][j - arr[i-1]] || dp[i-1][j];
//             else dp[i][j] = dp[i-1][j];
//         }
//     }
//     vector<int> ret;
//     for(int i=0; i<=sum/2; i++)
//     {
//         if(dp[n][i] == true)
//             ret.push_back(i);
//     }
//     return ret;
// }

// int findMin(int arr[], int n)
// {
//     int sum = 0;
//     for(int i = 0;i<n;i++)
//         sum += arr[i];
    
//     vector<int> ret = subsetSum(arr, n, sum);
//     for(auto i : ret)
//         cout<<i<<" ";
//     cout<<endl;
//     //return 0;
//     int minEle = INT_MAX, s1 = -1, s2 = -1;
//     for(auto i : ret)
//     {
//         if(sum - 2*i < minEle)
//         {
//             minEle = sum - 2*i;
//             s1 = i;
//             s2 = sum - i;
//         }
//         //minEle = min(minEle, sum - 2*i);
//     }
//     cout<<s1<<" "<<s2<<endl;
//     return minEle;
// }

// int main()
// {
//     //int arr[] = {3, 1, 4, 2, 2, 1}; 
//     // 7
//     // 24 13 21 47 32 6 26
//     int arr[] = {24,13,21,47,32,6,26};
//     int n = sizeof(arr)/sizeof(arr[0]); 
//     cout << "The minimum difference between two sets is "
//          << findMin(arr, n); 
//     return 0;
// }

// method 2

#include<bits/stdc++.h>
using namespace std;

int min(int a, int b)
{
    return (a < b)? a : b;
}

int findMin(int arr[], int n)
{
    int sum = 0;
    for(int i = 0;i<n; i++)
        sum += arr[i];
    bool dp[n+1][sum+1];
    for(int i = 0;i<=n;i++)
        dp[i][0] = true;
    for(int j = 1; j<=sum;j++)
        dp[0][j] = false;
    for(int i = 1; i<=n;i++)
    {
        for(int j = 1; j<=sum; j++)
        {
            if(j >= arr[i-1])
                dp[i][j] = dp[i-1][j - arr[i-1]] || dp[i-1][j];
            else dp[i][j] = dp[i-1][j];
        }
    }
    // for(int i=0; i<n+1; i++)
    // {
    //     for(int j=0; j<sum+1; j++)
    //         cout<<dp[i][j]<<" ";
    //     cout<<endl;
    // }
    int minEle = INT_MAX;
    for(int i = sum/2; i>=0; i--)
    {
        
        if(dp[n][i] == true)
        {
            cout<<i<<" ";
            minEle = sum - 2*i;
            break;
        }    
    }
    return minEle;
}

int main()
 {
	int t;cin>>t;
	while(t--)
	{
	    int n;cin>>n;
	    int arr[n];
	    for(int i = 0;i<n;i++)
	        cin>>arr[i];
	    cout<<findMin(arr, n)<<endl;
	}
	return 0;
}