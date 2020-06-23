// input -
// 5 5
// 1 5 2 4 3
// q 1 5
// q 1 3
// q 3 5
// u 3 6
// q 1 5

// output -
// 1
// 1
// 2
// 1

// Total number of nodes= n + (n-1) = 2n-1 Now, we know its a full 
// binary tree and thus the height is: ceil(Log2(n)) +1

// update -  O(log(n))
// query -  O(log(n))
// build - O(n)

#include <bits/stdc++.h>
using namespace std;

int tree[1000001], arr[1000001];

void build(int node, int start, int end)
{
	if(start == end)
		tree[node] = arr[start];
	else
	{
		int mid = (start + end)/2;

		build(2*node+1, start, mid);
		build(2*node+2, mid+1, end);

		tree[node] = min(tree[2*node+1] ,tree[2*node+2]);
	}
}

int query(int node, int start, int end, int l, int r)
{
	if(l <= start && end <= r)
	{
		return tree[node];
	}
	if(r < start || end < l)
		return INT_MAX;

	int mid = (start + end)/2;
	int p1 = query(2*node+1, start, mid, l, r);
	int p2 = query(2*node+2, mid+1, end, l, r);
	return min(p1, p2);
}

void update(int node,int start,int end,int idx,int val)
{
    if(start==end)
    {
       arr[idx]=val;
       tree[node]=val;
    }
    else
   	{
      int mid=(start+end)/2;
      if(idx>=start&&idx<=mid)
      {    
         update(2*node+1,start,mid,idx,val);
      }
      else
      {    
       update(2*node+2,mid+1,end,idx,val);
      }
     tree[node]=min(tree[2*node+1],tree[2*node+2]);
   }
}

int main()
{
	int n, q;
	cin>>n>>q;
	for(int i = 0; i<n; i++)
		cin>>arr[i];
	int node = 0, start = 0, end = n-1;
	build(node, start, end);
	int l, r;
	char c;
	for(int i = 0; i<q; i++)
	{
		cin>>c;
		if(c == 'q')
		{
			cin>>l>>r;
			l--,r--;
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
