// Given an input stream of n integers, find the kth largest element 
// for each element in the stream.

// Input:
// 2
// 4 6
// 1 2 3 4 5 6
// 1 2
// 3 4

// Output:
// -1 -1 -1 1 2 3
// 3 4 

// Explanation:
// Testcase1:
// k = 4
// For 1, the 4th largest element doesn't exist so we print -1.
// For 2, the 4th largest element doesn't exist so we print -1.
// For 3, the 4th largest element doesn't exist so we print -1.
// For 4, the 4th largest element is 1 {1, 2, 3, 4}
// For 5, the 4th largest element is 2 {2, 3, 4 ,5}
// for 6, the 4th largest element is 3 {3, 4, 5}

#include<bits/stdc++.h>
using namespace std;

class minheap
{
    int* harr;
    int capacity;
    int heap_size;
    
    public:
    minheap(int a[], int sz);
    void buildheap();
    void minheapify(int i);
    
    int parent(int i)
    {return (i-1)/2;}
    
    int left(int i)
    {return (2*i + 1);}
    
    int right(int i)
    {return (2*i + 2);}
    
    int extractMin();
    int getMin()
    {return harr[0];}
    
    void replaceMin(int x)
    {
        harr[0] = x;
        minheapify(0);
    }
};

minheap::minheap(int a[], int sz)
{
    heap_size = sz;
    harr = a;
}

void minheap::buildheap()
{
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

void kthlargest(int arr[], int n, int k)
{
    int count = 0;
    
    int* stream = new int[k];
    minheap mh(stream, k);
    
    for(int i=0; i<n; i++)
    {
        if(count < k-1)
        {
            stream[count] = arr[i];
            count++;
            cout<<-1<<" ";
        }
        else
        {
            if(count == k-1)
            {
                stream[count] = arr[i];
                mh.buildheap();
            }
            else
            {
                if(arr[i] > mh.getMin())
                    mh.replaceMin(arr[i]);
            }
            cout<<mh.getMin()<<" ";
            count++;
        }
    }
    
}

int main()
 {
	int t;cin>>t;
	while(t--)
	{
	    int k,n;
	    cin>>k>>n;
	    int arr[n];
	    for(int i=0; i<n; i++)
	        cin>>arr[i];
	   kthlargest(arr, n, k);
	   cout<<endl;
	}
	return 0;
}