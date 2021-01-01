// Maximum and minimum of an array using minimum number of 
// comparisons

// Compare in Pairs Method

// Time Complexity: O(n)

// Minimum element is 1
// Maximum element is 3000

// Total number of comparisons: Different for even and odd n, see 
// below: 
// If n is odd:    3*(n-1)/2  
// If n is even:   1 Initial comparison for initializing min and max, 
// and 3(n-2)/2 comparisons for rest of the elements  
//                 =  1 + 3*(n-2)/2 = 3n/2 -2

#include <bits/stdc++.h>
using namespace std;

struct pairs
{
    int minv;
    int maxv;
};

pairs getPairs(int arr[], int n)
{
    pairs p;
    int i = 0;

    if(n%2 == 0)
    {
        if(arr[0] > arr[1])
        {
            p.minv = arr[1];
            p.maxv = arr[0];
        }
        else
        {
            p.minv = arr[0];
            p.maxv = arr[1];
        }
        i = 2;
    }
    else
    {
        p.minv = arr[0];
        p.maxv = arr[0];
        i = 1;
    }

    while(i < n-1)
    {
        if(arr[i+1] < arr[i])
        {
            if(arr[i] > p.maxv)
                p.maxv = arr[i];
            if(arr[i+1] < p.minv)
                p.minv = arr[i+1];
        }
        else
        {
            if(arr[i+1] > p.maxv)
                p.maxv = arr[i+1];
            if(arr[i] < p.minv)
                p.minv = arr[i];
        }
        i += 2;
    }
    
    return p;
}

int main()
{
    int arr[] = {1000, 11, 445, 1, 330, 3000};
    int n = sizeof(arr)/sizeof(arr[0]);

    pairs p = getPairs(arr, n);
    cout<<p.minv<<" "<<p.maxv<<endl;
}