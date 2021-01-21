// There are 2 sorted arrays A and B of size n each. Write an algorithm to find 
// the median of the array obtained after merging the above 2 arrays(i.e. array of 
// length 2n). 
// The complexity should be O(log(n)).
// Median is 16

// Time - O(log(n))
// Space - O(1)

#include <bits/stdc++.h>
using namespace std;

int median(int arr[], int n)
{
    if(n%2 == 0)
        return (arr[n/2] + arr[n/2-1])/2;
    return (arr[n/2]);
}

int getMedian(int ar1[], int ar2[], int n)
{
    if(n <= 0)
        return -1;
    if(n == 1)
        return (ar1[0] + ar2[0])/2;
    if(n == 2)
        return (max(ar1[0], ar2[0]) + min(ar1[1], ar2[1]))/2;
    
    int m1 = median(ar1, n);
    int m2 = median(ar2, n);

    if(m1 == m2)
        return m1;

    if(m1 < m2)
    {
        if(n%2 == 0)
            return getMedian(ar1+n/2-1, ar2, n-n/2+1);
        return  getMedian(ar1+n/2, ar2, n-n/2);
    }
    else // (m1 > m2)
    {
        if(n%2 == 0)
            return getMedian(ar2+n/2-1, ar1, n-n/2+1);
        return getMedian(ar2+n/2, ar1, n-n/2);
    }
}

int main()
{
    int ar1[] = {1, 12, 15, 26, 38};
    int ar2[] = {2, 13, 17, 30, 45};

    int n = sizeof(ar1)/sizeof(ar1[0]);
    cout<<getMedian(ar1, ar2, n)<<endl;
}