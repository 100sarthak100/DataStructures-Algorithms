// Given an array of integers of size N and a number K. Your 
// must modify array K number of times. Here modify array means 
// in each operation you can replace any array element either 
// arr[i] by -arr[i] or -arr[i] by arr[i]. You need to perform this 
// operation in such a way that after K operations, 
// sum of array must be maximum.

// Input:
// 2
// 5 1
// 1 2 -3 4 5
// 10 5
// 5 -2 5 -4 5 -12 5 5 5 20

// Output:
// 15
// 68

// Explanation:
// Testcase 1:  In testcase 1 we have k=1 so we can change -3 to 
// 3 and sum all the elements to produce 15 as output.
// Testcase 2: Here  we have k=5 so we turn -2, -4, -12 to 2, 4, 
// and 12 respectively. Since we have performed 3 operations so k 
// is now 2. To get maximum sum of array we can turn positive 
// turned 2 into negative and then positive again so k is 0. 
// Now sum is 5+5+4+5+12+5+5+5+20+2 = 68

// Time - O(nlogn)
// Space - O(1)

#include<bits/stdc++.h>
using namespace std;

int swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int l, int r)
{
    int pivot = arr[r];
    int j = l - 1;
    for(int i=l; i<=r-1; i++)
    {
        if(arr[i] <= pivot)
        {
            j++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[j+1], &arr[r]);
    return j+1;
}

void sortArr(int arr[], int l, int r)
{
    if(l < r)
    {
        int pi = partition(arr, l, r);
        sortArr(arr, l, pi-1);
        sortArr(arr, pi+1, r);
    }
}

int maxSum(int arr[], int n, int k)
{
    sortArr(arr, 0, n-1);
    int i = 0;
    int flag = 0;
    while(k > 0)
    {
        if(arr[i] < 0)
        {
            arr[i] = -arr[i];
            k--;
            flag = 1;
        }
        else
        {
            if(k%2 == 0)
                k = 0;
            else if(flag)
            {
                if(arr[i-1] < arr[i])
                    arr[i-1] = -arr[i-1];
                else
                    arr[i] = -arr[i];
            }
            else
                arr[i] = -arr[i];
            k = 0;
        }
        i++;
        if(i > n-1)
            i = n-1;
    }
    int sum = 0;
    for(int i=0; i<n; i++)
        sum += arr[i];
    return sum;
}

int main()
 {
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>>n>>k;
	    int arr[n];
	    for(int i=0; i<n; i++)
	        cin>>arr[i];
	    cout<<maxSum(arr, n, k)<<endl;
	}
	return 0;
}