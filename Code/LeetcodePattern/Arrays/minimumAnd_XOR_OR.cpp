// Given an array A of N integers. Find out the minimum value 
// of the following expression for all valid i, j;
// (Ai and Aj) xor (Ai or Aj) where i != j.

// input -
// 2
// 5
// 1 2 3 4 5
// 3
// 2 4 7

// output -
// 1
// 3

// => (X.Y)^(X+Y)
// => (X.Y)(X+Y)’ + (X.Y)'(X+Y)
// => (X.Y)(X’.Y’) + (X’+Y’)(X+Y)
// => X.X’.Y.Y’ + X’.X + X’.Y + Y’.X + Y’.Y
// => 0 + 0 + X’.Y + Y’.X + 0
// => X^Y

// Time - O(NlogN)
// Sorting array - O(NlogN)

#include <bits/stdc++.h>
using namespace std;

int minXOR(int arr[], int n)
{
	sort(arr, arr+n);
	int minVal = INT_MAX;
	for(int i=1; i<n; i++)
		minVal = min(minVal, arr[i]^arr[i-1]);
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
		cout<<minXOR(arr, n)<<endl;
	}
}
