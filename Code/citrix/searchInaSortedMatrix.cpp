// Given a matrix mat[] of size n x m, where every 
// row and column is sorted in increasing order, and a number x 
// is given. The task is to find whether element x is present in 
// the matrix or not.

// Expected Time Complexity : O(m + n)
// Example:
// Input:
// 2
// 3 3
// 3 30 38 44 52 54 57 60 69
// 62
// 1 6
// 18 21 27 38 55 67
// 55

// Output:
// 0
// 1

// Explanation:
// Testcase 1: 62 is not present in the matrix, so output is 0.
// Testcase 2: 55 is present in the matrix at 5th cell.

#include<iostream>
using namespace std;

int arr[31][31];

int search(int arr[][31], int n, int m, int x)
{
    if(n == 0)
        return 0;
    int smallest = arr[0][0], largest = arr[n-1][m-1];
    if(x < smallest || x > largest)
        return 0;
    int i = 0, j = m-1;
    while(i < n && j >= 0)
    {
        if(arr[i][j] == x)
            return 1;
        else if(arr[i][j] > x)
            j--;
        else
            i++;
    }
    return 0;
}

int main()
 {
	int t;cin>>t;
	while(t--)
	{
	    int n, m;
	    cin>>n>>m;
	    for(int i=0; i<n; i++)
	        for(int j=0; j<m; j++)
	            cin>>arr[i][j];
	   int x;cin>>x;
	   cout<<search(arr, n, m, x)<<endl;
	}
	return 0;
}