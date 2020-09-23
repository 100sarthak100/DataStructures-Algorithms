// You are given a rooted tree with N nodes. Each node contains 
// a lowercase English letter. Node with label 1 is the root.There 
// are Q questions of the form

// X S: Here X is the root of subtree and S is a string.

// For each question, let T be the string built using all the 
// characters in the nodes of subtree with root X (each subtree node 
// character comes exactly once) .
// For each question, print minimum number of characters to be added 
// to T , so that the we can build S using some characters of string 
// T (each character of string T can be used at most once).

// Input -
// 8 3
// o v s l v p d i
// 1 3
// 8 3
// 4 8
// 6 1
// 5 3
// 7 6
// 2 3
// 7 ifwrxl
// 4 eyljywnm
// 3 llvse

// Output -
// 6
// 7
// 2

// Explanation
// Query 1- Character in the subtree with root 7 is d, we need 6 
// characters(i,f,w,r,x,l) 
// to make S=(ifwrxl).

// Query 2- Character in the subtree with root 4 is l, we need 7 
// characters(e,y,j,y,w,n,m) to make S=(eyljywnm).

// Query 3- Characters in the subtree with root 3 are (v,s,i,l), 
// we need 2 characters(l,e) to make S=(llvse).

// Time - dfs - O(V + E)

#include <bits/stdc++.h>
using namespace std;

vector<int> adj[1000000];
vector<bool> visited(1000000);
vector<string> vec(1000000);

void dfs(int x)
{
	visited[x] = true;
	for(auto neighbor : adj[x])
	{
		if(!visited[neighbor])
		{
			dfs(neighbor);
			vec[x] += vec[neighbor];
		}
	}
	cout<<vec[x]<<endl;
}

int solveCount(string a, string b)
{
	vector<int> f1(26, 0);
	vector<int> f2(26, 0);

	for(int i=0; i<a.size(); i++)
		f1[a[i] - 'a']++;
	for(int i=0; i<b.size(); i++)
		f2[b[i] - 'a']++;	
	
	int count = 0;
	for(int i=0; i<26; i++)
		count += min(f1[i], f2[i]);
	
	return count;
}

int main()
{
	int n, q;
	cin>>n>>q;
	char c;
	for(int i=1; i<=n; i++)
	{
		cin>>c;
		vec[i].push_back(c);
	}

	int a, b;
	for(int i=0; i<n-1; i++)
	{
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	for(int i=0; i<1000000; i++)
		visited[i] = false;
	dfs(1);

	int x;string s;
	for(int i=0; i<q; i++)
	{
		cin>>x>>s;
		cout<<s.size() - solveCount(s, vec[x])<<endl;
	}
}