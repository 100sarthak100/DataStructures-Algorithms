// Given an array arr[] and a number K where K is smaller than 
// size of array, the task is to find the Kth smallest element in 
// the given array. 
// It is given that all array elements are distinct.

// Input:
// 2
// 6
// 7 10 4 3 20 15
// 3
// 5
// 7 10 4 20 15
// 4
// Output:
// 7
// 15

// Time complexity of this solution is O(n + kLogn).

#include <bits/stdc++.h>
using namespace std;

class minheap
{
    int *harr;
    int capacity;
    int heap_size;
    
 public:
    minheap(int a[], int sz);
    void minheapify(int i);
    
    int parent(int i)
    {return (i-1)/2; }
    
    int left(int i)
    {return (2*i + 1);}
    
    int right(int i)
    {return (2*i + 2);}
    
    
    int extractMin();
    int getMin() 
    {return harr[0];}
};

minheap::minheap(int a[], int sz)
{
    heap_size = sz;
    harr = a;
    int i = (heap_size - 1)/2;
    while(i >= 0)
    {
        minheapify(i);
        i--;
    }
}

int minheap::extractMin()
{
    if(heap_size == 0)
        return INT_MAX;
    
    int root = harr[0];
    
    if(heap_size > 1)
    {
        harr[0] = harr[heap_size - 1];
        minheapify(0);
    }
    heap_size--;
    return root;
}

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void minheap::minheapify(int i)
{
    int l = left(i);
    int r = right(i);
    int smallest = i;
    
    if(l < heap_size && harr[l] < harr[i])
        smallest = l;
    if(r < heap_size && harr[r] < harr[smallest])
        smallest = r;
    if(smallest != i)
    {
        swap(&harr[i], &harr[smallest]);
        minheapify(smallest);
    }
}

int Kthsmallest(int arr[], int n, int k)
{
    minheap mh(arr, n);
    
    for(int i=0; i<k-1; i++)
        mh.extractMin();
    
    return mh.getMin();
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
        int k;cin>>k;
        cout<<Kthsmallest(arr, n, k)<<endl;
    }
}

// using priority_queue stl (min heap)
// same time complexity
int main()
{
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i=0; i<n; i++)
        {
            int a;cin>>a;
            pq.push(a);
        }
        int k;cin>>k;
        
        for(int i=0; i<k-1; i++)
            pq.pop();
        
        cout<<pq.top()<<endl;
    }
}