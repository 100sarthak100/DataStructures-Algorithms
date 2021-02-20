// Given a string you need to print the size of the longest possible 
// substring that has exactly k unique characters. If there is no possible 
// substring print -1.
// Example
// For the string aabacbebebe and k = 3 the substring will be cbebebe 
// with length 7.

// Input:
// 2
// aabacbebebe
// 3
// aaaa
// 1
// Output:
// 7
// 4

// Time - O(N)
// Space - O(K)

#include<bits/stdc++.h>
using namespace std;

int longestK(string s, int k)
{
    unordered_map<char, int> mp;
    int i = 0, j = 0, maxEle = INT_MIN;
    
    while(j < s.size())
    {
        mp[s[j]]++;
        if(mp.size() < k)
            j++;
        else if(mp.size() == k)
        {
            maxEle = max(maxEle, j - i + 1);
            j++;
        }
        else if(mp.size() > k)
        {
            while(mp.size() > k)
            {
                mp[s[i]]--;
                if(mp[s[i]] == 0)
                    mp.erase(s[i]);
                i++;
            }
            j++;
        }
    }
    if(maxEle == INT_MIN)
        return -1;
    return maxEle;
}


int main()
 {
	int t;cin>>t;
	while(t--)
	{
	    string s;cin>>s;
	    int k;cin>>k;
	    cout<<longestK(s, k)<<endl;
	}
	return 0;
}