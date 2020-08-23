#include <bits/stdc++.h>
using namespace std;

int tree[1000001], arr[1000001];

void buildTree(int node, int start, int end)
{
    if(start == end)
        tree[node] = arr[start];
    else
    {
        int mid = (start + end)/2;
        buildTree(2*node+1, start, mid);
        buildTree(2*node+2, mid+1, end);

        tree[node] = min(tree[2*node+1], tree[2*node+2]);
    }
}

int query(int node, int start, int end, int l, int r)
{
    if(l<=start && end<= r)
        return tree[node];
    
    if(r<start || l>end)
        return INT_MAX;
    
    int mid = (start + end)/2;
    int p1 = query(2*node+1, start, mid, l, r);
    int p2 = query(2*node+2, mid+1, end, l, r);
    return min(p1, p2);
}

void update(int node, int start, int end, int idx, int ele)
{
    if(start == end)
    {
        arr[idx] = ele;
        tree[node] = ele;
    }
    else
    {
        int mid = (start + end)/2;
        if(idx>=start && idx<=mid)
            update(2*node+1, start, mid, idx, ele);
        else
            update(2*node+2, mid+1, end, idx, ele);
        
        tree[node] = min(tree[2*node+1], tree[2*node+2]);
    }
}

int main()
{
    int n, q;
    cin>>n>>q;
    for(int i=0; i<n; i++)
        cin>>arr[i];
    int node = 0, start = 0, end = n-1;
    buildTree(node, start, end);
    
    int l, r;
    char c;
    for(int i=0; i<q; i++)
    {
        cin>>c;
        if(c == 'q')
        {
            cin>>l>>r;
            l--, r--;
            cout<<query(node, start, end, l, r)<<endl;
        }
        else if(c == 'u')
        {
            cin>>l>>r;
            l--;
            arr[l] = r;
            update(node, start, end, l, r);
        }
    }
}