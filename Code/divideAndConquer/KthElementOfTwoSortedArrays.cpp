#include <bits/stdc++.h>
using namespace std;

int kth(int arr1[], int m, int arr2[], int n, int k)
{
    if(k > (m+n) || k < 1) return -1;

    if(m > n)
        return kth(arr2, n, arr1, m, k);
    
    if(m == 0)
        return arr2[k-1];
    
    if(k == 1)
        return min(arr1[0], arr2[0]);

    int i = min(m, k/2), j = min(n, k/2);

    if(arr1[i - 1] > arr2[j - 1])
        return kth(arr1, m, arr2+j, n-j, k-j);
    else
        return kth(arr1+i, m-i, arr2, n, k-i);
}

int main()
{
    int arr1[5] = {2, 3, 6, 7, 9}; 
    int arr2[4] = {1, 4, 8, 10}; 
    int m = sizeof(arr1)/sizeof(arr1[0]); 
    int n = sizeof(arr2)/sizeof(arr2[0]); 
    int k = 5; 
      
    int ans = kth(arr1,m,arr2, n, k); 
      
    if(ans == -1) cout<<"Invalid query"; 
    else cout<<ans; 
      
    return 0;
}