#include <bits/stdc++.h>
using namespace std;

bool sortbysec(pair<int,int> &a,pair<int,int> &b)
{
	if(a.second == b.second)
		return a.first > b.first;
	return a.second > b.second;
}

int main()
{
	int n,m,k,x,y;
	cin>>n>>m>>k;
	int a[n];
	for(int i = 0;i<n;i++)
		cin>>a[i];
	vector<int> v[1001];
	for(int i = 0;i<m;i++)
	{
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for(int i = 1;i <= n; i++)
	{
		vector<pair<int, int>> vec;
		for(int j = 0; j < v[i].size(); j++)
		{
			x = v[i][j];
			y = a[x - 1];
            cout<<endl;
            cout<<x<<" "<<y<<endl;
			vec.push_back(make_pair(x,y));
		}
		sort(vec.begin(), vec.end(), sortbysec);
		if(vec.size() >= k)
			cout<<vec[k-1].first<<"\n";
		else
			cout<<"-1\n";
	}
}