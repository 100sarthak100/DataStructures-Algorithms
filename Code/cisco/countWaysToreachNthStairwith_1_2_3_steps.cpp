// A child is running up a staircase with n steps and can hop 
// either 1 step, 2 steps, or 3 steps at a time. Implement a method 
// to count how many possible ways the 
// child can run up the stairs.

// Input : 4
// Output : 7
// Explantion:
// Below are the four ways
//  1 step + 1 step + 1 step + 1 step
//  1 step + 2 step + 1 step
//  2 step + 1 step + 1 step 
//  1 step + 1 step + 2 step
//  2 step + 2 step
//  3 step + 1 step
//  1 step + 3 step

// Input : 3
// Output : 4
// Explantion:
// Below are the four ways
//  1 step + 1 step + 1 step
//  1 step + 2 step
//  2 step + 1 step
//  3 step

// Time Complexity: O(n).
// Only one traversal of the array is needed. So Time Complexity 
// is O(n).
// Space Complexity: O(n).
// To store the values in a DP, n extra space is needed.

// order matters
#include <iostream> 
using namespace std; 
  
// A recursive function used by countWays 
int countWays(int n) 
{ 
    int res[n + 1]; 
    res[0] = 1; 
    res[1] = 1; 
    res[2] = 2; 
    for (int i = 3; i <= n; i++) 
        res[i] = res[i - 1] + res[i - 2] 
                + res[i - 3]; 
  
    return res[n]; 
} 
  
// Driver program to test above functions 
int main() 
{ 
    int n = 4; 
    cout << countWays(n); 
    return 0; 
} 

// count ways to reach Nth stair

// There are N stairs, a person standing at the bottom wants to 
// reach the top. The person can climb either 1 stair or 2 stairs 
// at a time. Count the number of ways, 
// the person can reach the top (order does matter).

#include<iostream>
using namespace std;
#define m 1000000007

int main()
 {
	int t;cin>>t;
	
	long long int dp[100001];
	dp[0] = 1;
	dp[1] = 1;
	    
	for(int i=2; i<=100000; i++)
	   dp[i] = (dp[i-1]%m + dp[i-2]%m)%m;
	
	while(t--)
	{
	    int n;cin>>n;
	    cout<<dp[n]%m<<endl;
	}
	return 0;
}