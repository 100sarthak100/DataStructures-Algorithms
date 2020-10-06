// Given two sorted arrays arr1[] and arr2[] in non-decreasing order 
// with size n and m. The task is to merge the two sorted arrays in 
// place, i. e., we need to consider all n + m elements in sorted 
// order, then we need to put first n elements of these sorted in 
// first array and remaining m elements in second array.

// Example 1:

// Input: 
// N = 4, arr1[] = [1 3 5 7] 
// m = 5, arr2[] = [0 2 6 8 9]
// Output: 
// arr1[] = [0 1 2 3]
// arr2[] = [5 6 7 8 9]
// Explanation: After merging the two non-decreasing 
// arrays, we have, 0 1 2 3 5 6 7 8 9.
// Example 2:

// Input: 
// N = 2, arr1[] = [10, 12] 
// M = 3, arr2[] = [5 18 20]
// Output: 
// arr1[] = [5 10]
// arr2[] = [12 18 20]
// Explanation: After merging two sorted arrays 
// we have 5 10 12 18 20.

// Your Task:
// This is a function problem. You only need to complete the function 
// merge() that takes n and m as parameters.

// Time Complexity: The worst case time complexity of code/algorithm 
// is O(m*n). The worst case occurs when all elements of ar1[] are 
// greater than all elements of ar2[].

// This gives TLE , Time - O(n*m)
void merge(int arr1[], int arr2[], int n, int m) 
{ 
    int last = 0;
    for(int i=m-1; i>=0; i--)
    {
        int j;
        int last = arr1[n-1];
        for(j=n-2; j>=0 && arr1[j] > arr2[i]; j--)
                arr1[j+1] = arr1[j];
        
        if(j != n-2 || last > arr2[i])
        {
            arr1[j+1] = arr2[i];
            arr2[i] = last;
        }
    }
    return;
} 

// best solution, using gap algo (shel sort)
// Time -  O((n+m)*log(n+m)) 
// Space - O(1)

int nextGap(int gap)
{
    if(gap <= 1)
        return 0;
    return (gap/2) + (gap%2);
}

void merge(int arr1[], int arr2[], int n, int m) 
{ 
    int i, j, gap = n+m;
    for(gap = nextGap(gap); gap>0; gap = nextGap(gap))
    {
        for(i=0; i+gap<n; i++)
            if(arr1[i] > arr1[i+gap])
                swap(arr1[i], arr1[i+gap]);
        
        j = (gap > n) ? gap-n : 0;
        for(j; i<n && j<m; i++, j++)
            if(arr1[i] > arr2[j])
                swap(arr1[i], arr2[j]);
                
        if(j < m)
        {
            for(j=0; j+gap<m; j++)
                if(arr2[j] > arr2[j+gap])
                    swap(arr2[j], arr2[j+gap]);
        }
    }
    return;
} 