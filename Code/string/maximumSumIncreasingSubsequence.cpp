// Input:
// 2
// 7
// 1 101 2 3 100 4 5
// 4
// 10 5 4 3

// Output:
// 106
// 10

// Explanation:
// Testcase 1: All the increasing subsequences are : 
//(1,101); (1,2,3,100); (1,2,3,4,5). Out of these (1, 2, 3, 100)
//  has maximum sum,i.e., 106.
// time O(n^2)


#include<bits/stdc++.h>
using namespace std;

int maxlcsSum(int arr[], int n)
{
    int lis[n];
    for(int i = 0;i<n;i++)
        lis[i] = arr[i];
    
    for(int i = 1; i<n;i++)
    {
        for(int j = 0;j<i;j++)
        {
            if(arr[i] > arr[j] && lis[i] < lis[j] + arr[i])
            {
                lis[i] = lis[j] + arr[i];
            }
        }
    }
    return *max_element(lis, lis+n);
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
	    cout<<maxlcsSum(arr, n)<<endl;
	}
	return 0;
}