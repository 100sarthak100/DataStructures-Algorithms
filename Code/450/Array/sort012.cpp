// Given an array A of size N containing 0s, 1s, and 2s; you need 
// to sort the array in ascending order.

// Input :
// 2
// 5
// 0 2 1 2 0
// 3
// 0 1 0

// Output:
// 0 0 1 2 2
// 0 0 1

// Explanation:
// Testcase 1: After segragating the 0s, 1s and 2s, we have 0 0 1 2 2 
// which shown in the output.

// Time - O(N)
// Space - O(1)

#include<iostream>
using namespace std;

void sort012(int arr[], int n)
{
    int i=-1, j=0, k = n-1;
    while(j <= k)
    {
        if(arr[j] == 2)
        {
            swap(arr[j], arr[k]);
            k--;
        }
        else if(arr[j] == 1)
            j++;
        else
        {
            i++;
            swap(arr[i], arr[j]);
            j++;
        }
    }
    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
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
	    sort012(arr, n);
	}
	return 0;
}