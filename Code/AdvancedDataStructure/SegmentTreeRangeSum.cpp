// Segment Tree is a basically a binary tree used for storing the 
// intervals or segments. Each node in the Segment Tree represents 
// an interval.
// Since a Segment Tree is a binary tree, a simple linear array can be used to represent the Segment Tree.

// complexity of build is O(n);
// complexity of update is O(logn);
// complexity of query is O(logn);

// question is  - given an array , given a query l and r , find the sum
// between th el and r in given array
// and also update value

#include <bits/stdc++.h>
using namespace std;

int tree[100005];

void build(int node, int start, int end, int arr[])
{
    if(start == end)
        tree[node] = arr[start];
    else
    {
        int mid = (start + end)/2;

        build(2*node+1, start, mid, arr);
        build(2*node+2, mid+1, end, arr);

        tree[node] = tree[2*node+1] + tree[2*node+2];
    }
}

int query(int node, int start, int end, int l, int r)
{
    // if l and r are completely outside start and end
    if(r < start || end < l)
        return 0;

    if(l <= start && end <= r)
        return tree[node];

    // partially inside
    int mid = (start + end)/2;
    int p1 = query(2*node+1, start, mid , l, r);
    int p2 = query(2*node+2, mid+1, end, l, r);
    return (p1 + p2);
}

// update a[idx] = a[idx] + val
void update(int node, int start, int end, int idx, int val, int arr[])
{
    if(start == end)
    {
        arr[idx] += val;
        tree[node] += val;
        return;
    }
    else
    {
        int mid = (start + end)/2;
        if(start <= idx && idx <= mid)
            update(2*node+1, start, mid, idx, val, arr);
        else
            update(2*node+2, mid+1, end, idx, val, arr);
    }
    tree[node] = tree[2*node+1] + tree[2*node+2];
}

int main()
{
    int arr[] = {1, 3, 5, 7, 9, 11};  
    int n = sizeof(arr)/sizeof(arr[0]); 
    int node = 0;
    int start = 0;
    int end = n-1;
    build(node, start, end, arr);

    int l = 2, r = 5;

    cout<<"Sum of values in given range = "
    <<query(node, start, end, l, r)<<endl; 

    int idx = 2, val = 6;
    arr[idx] = val;
    update(node, start, end, idx, val, arr);

    cout<<"Sum of updated values in given range = "
    <<query(node, start, end, l, r)<<endl; 
}