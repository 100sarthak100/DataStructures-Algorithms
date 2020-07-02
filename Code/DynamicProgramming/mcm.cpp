// Given a sequence of matrices, find the most efficient way to 
// multiply these matrices together. The problem is not actually to 
// perform the multiplications, but merely to decide in which order 
// to perform the multiplications.

// Example:
//  if you had four matrices A, B, C, and D, you would have:

//     (ABC)D = (AB)(CD) = A(BCD) = ....

// For example:

// A: 10 × 30 matrix
// B : 30 × 5 matrix
// C : 5 × 60 matrix
// Then,
//      (AB)C = (10×30×5) + (10×5×60) 
//            = 1500 + 3000 
//            = 4500 operations
//      A(BC) = (30×5×60) + (10×30×60) 
//            = 9000 + 18000 
//            = 27000 operations.

// Example:
// Input:
// 2
// 5
// 1 2 3 4 5
// 3
// 3 3 3
// Output:
// 38
// 27

// #include<bits/stdc++.h>
// using namespace std;

// int solve(int arr[], int i, int j)
// {
//     if(i >= j)
//         return 0;
        
//     int minVal = INT_MAX;
//     for(int k=i; k<=j-1; k++)
//     {
//         int tempAns = solve(arr, i, k) + solve(arr, k+1, j)
//                         + (arr[i-1] * arr[k] * arr[j]);
//         minVal = min(minVal, tempAns);
//     }
//     return minVal;
// }

// int main()
//  {
// 	int t;cin>>t;
// 	while(t--)
// 	{
// 	    int n;cin>>n;
// 	    int arr[n];
// 	    for(int i=0; i<n; i++)
// 	        cin>>arr[i];
	   
// 	   cout<<solve(arr, 1, n-1)<<endl;
// 	}
// 	return 0;
// }

// bottom up approach (recursion + memoization = dp)
// best soln
#include<bits/stdc++.h>
using namespace std;

int static dp[101][101];

int solve(int arr[], int i, int j)
{
    if(i >= j)
        return 0;
    
    if(dp[i][j] != -1)
        return dp[i][j];
        
    int minVal = INT_MAX;
    for(int k=i; k<=j-1; k++)
    {
        int tempAns = solve(arr, i, k) + solve(arr, k+1, j)
                        + (arr[i-1] * arr[k] * arr[j]);
        minVal = min(minVal, tempAns);
    }
    dp[i][j] = minVal;
    return minVal;
}

int main()
 {
	int t;cin>>t;
	while(t--)
	{
	    int n;cin>>n;
	    int arr[n];
	    for(int i=0; i<n; i++)
	        cin>>arr[i];
	   
	   memset(dp, -1, sizeof(dp));
	   cout<<solve(arr, 1, n-1)<<endl;
	}
	return 0;
}