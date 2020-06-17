// 2
// 5
// 1 0 1 1 0
// 10
// 1 0 1 1 1 1 1 0 0 0

// Output:
// 0 0 1 1 1
// 0 0 0 0 1 1 1 1 1 1

// Time Complexity: O(n)

#include<iostream>
using namespace std;

void sort01(int arr[], int n)
{
    int i = 0, j = 0;
    while(j <= n-1)
    {
        if(arr[j] != 0)
            j++;
        else
        {
            swap(arr[i], arr[j]);
            i++;
            j++;
        }
    }
    for(int i = 0; i<n; i++)
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
	    for(int i = 0; i<n; i++)
	        cin>>arr[i];
	    sort01(arr, n);
	}
	return 0;
}