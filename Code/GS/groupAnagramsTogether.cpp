// Given an array of words, print the count of all anagrams together 
// in sorted order (increasing order of counts).
// For example, if the given array is {“cat”, “dog”, “tac”, “god”, 
// “act”}, then grouped anagrams are “(dog, god) 
// (cat, tac, act)”. So the output will be 2 3.

// Input:
// 2
// 5
// act cat tac god dog
// 3
// act cat tac
// Output:
// 2 3
// 3

#include<bits/stdc++.h>
using namespace std;

void countAnagrams(vector<string> vec, int n)
{
    unordered_map<string, vector<string>> mp;
    for(int i=0; i<n; i++)
    {
        string s = vec[i];
        string sortedS = s;
        sort(sortedS.begin(), sortedS.end());
        mp[sortedS].push_back(s);
    }
    for(auto x : mp)
    {
        cout<<x.second.size()<<" ";
    }
    return;
}

int main()
 {
	int t;cin>>t;
	while(t--)
	{
	    int n;cin>>n;
	    vector<string> vec;
	    string s;
	    for(int i=0; i<n; i++)
	    {
	        cin>>s;
	        vec.push_back(s);
	    }
	    countAnagrams(vec, n);
	    cout<<endl;
	}
	return 0;
}