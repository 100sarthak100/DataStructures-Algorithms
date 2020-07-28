// input -
// 1
// 6
// 7 10 4 3 20 15
// 3

// output -
// 10

// time - O(n + klogn)

#include <bits/stdc++.h>
using namespace std;

class maxheap
{
    int* harr;
    int capacity;
    int heap_size;

    public:
    maxheap(int a[], int sz);
    void maxheapify(int i);

    int parent(int i)
    {return (i-1)/2 ;}

    int left(int i)
    {return (2*i + 1);}

    int right(int i)
    {return (2*i + 2);}

    int extractMax();
    int getMax()
    {return harr[0];}
};

maxheap::maxheap(int a[], int sz)
{
    heap_size = sz;
    harr = a;
    int i = (heap_size - 1)/2;
    while(i >= 0)
    {
        maxheapify(i);
        i--;
    }
}

int maxheap::extractMax()
{
    if(heap_size <= 0)
        return INT_MIN;
    
    int root = harr[0];
    if(heap_size > 1)
    {
        harr[0] = harr[heap_size - 1];
        maxheapify(0);
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

void maxheap::maxheapify(int i)
{
    int l = left(i);
    int r = right(i);
    int largest = i;

    if(l < heap_size && harr[l] > harr[i])
        largest = i;
    if(r < heap_size && harr[r] > harr[largest])
        largest = r;
    if(largest != i)
    {
        swap(&harr[i], &harr[largest]);
        maxheapify(largest);
    }
}

int kthlargest(int arr[], int n, int k)
{
    maxheap mh(arr, n);

    for(int i=0; i<k-1; i++)
        mh.extractMax();
    
    return mh.getMax();
}

int main()
{
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;
        int arr[n];
        for(int i=0; i<n;i++)
            cin>>arr[i];
        int k;cin>>k;
        cout<<kthlargest(arr, n, k)<<endl;
    }
}