// input -
// 2
// 3
// 1 2 3
// 4 5 6
// 7 8 9
// 2
// 4 3
// 1 4

// output -
// 0
// 2

// Time - O(n^4)
// Brute force method

#include <bits/stdc++.h>
using namespace std;

int arr[21][21];

int inverCount(int arr[][21], int n)
{
	int count = 0;
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			for(int x=i; x<n; x++)
				for(int y=j; y<n; y++)
					if(arr[i][j] > arr[x][y])
						count++;
	return count;
}

int main()
{
	int t;cin>>t;
	while(t--)
	{
		int n;cin>>n;
		for(int i=0; i<n; i++)
			for(int j=0; j<n;j++)
				cin>>arr[i][j];
		cout<<inverCount(arr, n)<<endl;
	}
}
