// Example:
// Input:
// 2
// 9
// 5 0 1 3 2 4 1 0 5
// 4
// 8
// 3 1 0 2 5 4 1 2
// 4

// Output:
// 8
// 7

#include<bits/stdc++.h>
using namespace std;

int lru(int pages[], int n, int capa)
{
    unordered_set<int> st;
    unordered_map<int, int> mp;
    int page_fault = 0;
    for(int i=0; i<n; i++)
    {
        if(st.size() < capa)
        {
            if(st.find(pages[i]) == st.end())
            {
                st.insert(pages[i]);
                page_fault++;
            }
            mp[pages[i]] = i;
        }
        else
        {
            if(st.find(pages[i]) == st.end())
            {
                int lru = INT_MAX, val;
                for(auto it = st.begin(); it != st.end(); it++)
                {
                    if(mp[*it] < lru)
                    {
                        lru = mp[*it];
                        val = *it;
                    }
                }
                st.erase(val);
                st.insert(pages[i]);
                page_fault++;
            }
            mp[pages[i]] = i;
        }
    }
    return page_fault;
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
	   int capa; cin>>capa;
	    cout<<lru(arr, n, capa)<<endl;
	}
	return 0;
}