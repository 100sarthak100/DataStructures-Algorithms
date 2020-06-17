// There are 2 sorted arrays A and B of size n each. Write an algorithm to find 
// the median of the array obtained after merging the above 2 arrays(i.e. array of 
// length 2n). 
// The complexity should be O(log(n)).
// Median is 16

// if sizes of both arrays are same
#include <bits/stdc++.h>
using namespace std;

int median(int arr[], int n)
{
    if(n%2 == 0)
        return (arr[n/2] + arr[n/2-1])/2;
    else 
        return arr[n/2];
}

int getMedian(int ar1[], int ar2[], int n)
{
    if(n <= 0)
        return -1;
    if(n == 1)
        return (ar1[0] + ar2[0])/2;
    
    if(n == 2)
        return (max(ar1[0], ar2[0]) +
                min(ar1[1], ar2[1]))/ 2;

    int m1 = median(ar1, n);
    int m2 = median(ar2, n);
    if(m1 == m2)
        return m1;
    if(m1 < m2)
    {
        if(n%2 == 0)
            return getMedian(ar1+n/2 - 1, ar2, n - n/2 + 1);

        return getMedian(ar1+n/2, ar2, n - n/2);
    }

    // if m1 > m2
    if(n%2 == 0)
        return getMedian(ar2+n/2 - 1, ar1, n - n/2 + 1);
    return getMedian(ar2+n/2, ar1, n-n/2);

}

int main()
{
    int ar1[] = {1, 12, 15, 26, 38};
    int ar2[] = {2, 13, 17, 30, 45};

    int n1 = sizeof(ar1) / sizeof(ar1[0]);
    int n2 = sizeof(ar2) / sizeof(ar2[0]);
    if (n1 == n2)
        cout << "Median is "
             << getMedian(ar1, ar2, n1);
    else
        cout << "Doesn't work for arrays"
             << " of unequal size";
    getchar();
    return 0;
}

// sum of middle elements of two sorted arrays

// Input :
// 1
// 5
// 1 2 4 6 10
// 4 5 6 9 12

// Output : 
// 11

// Explanation:
// Testcase 1: After merging two arrays, sum of middle elements is 11 (5 + 6).

#include<iostream>
using namespace std;

int median(int arr[], int n)
{
    if(n%2 == 0)
        return (arr[n/2] + arr[n/2 - 1]);
    return arr[n/2];
}

int getMedian(int arr1[], int arr2[], int n)
{
    if(n <= 0)
        return -1;
    if(n == 1)
        return (arr1[0] + arr2[0])/2;
    if(n == 2)
        return (max(arr1[0], arr2[0]) + min(arr1[1], arr2[1]));
    
    int m1 = median(arr1, n);
    int m2 = median(arr2, n);
    if(m1 == m2)
        return m1;
    
    if(m2 > m1)
    {
        if(n%2 == 0)
            return getMedian(arr1 + n/2 - 1, arr2, n - n/2 + 1);
        return getMedian(arr1 + n/2, arr2, n - n/2);
    }
    
    if(m1 > m2)
    {
        if(n%2 == 0)
            return getMedian(arr2 + n/2 - 1, arr1, n - n/2 + 1);
        return getMedian(arr2 + n/2, arr1, n - n/2);
    }
}

int main()
 {
	int t;cin>>t;
	while(t--)
	{
	    int n;cin>>n;
	    int arr1[n], arr2[n];
	    for(int i = 0; i<n; i++)
	        cin>>arr1[i];
	    for(int j = 0; j<n; j++)
	        cin>>arr2[j];
	   
	    int a = getMedian(arr1, arr2, n);
	    cout<<a<<endl;
	}
	return 0;
}