// Given a string 's'. The task is to find the smallest window 
// length that contains all the characters of the given string at 
// least one time.
// For eg. A = “aabcbcdbca”, then the result would be 4 as of the 
// smallest window will be “dbca”.

// Input:
// 2
// aabcbcdbca
// aaab

// Output:
// 4
// 2

// Explanation:
// Testcase 1: Smallest window size is 4 which is of "dbca" which 
// consists all characters of the string.

// Time Complexity: O(N).
// As the string is traversed using two pointers only once.
// Space Complexity: O(N).
// As a hash_map is used of size N.

#include<bits/stdc++.h>
using namespace std;
const int MAX_CHARS = 256;

int distWind(string s)
{
   int n = s.size();
   bool map[MAX_CHARS] = {false};
   int dist_count = 0;
   for(int i=0; i<n; i++)
   {
       if(map[s[i]] == false)
       {
           map[s[i]] = true;
           dist_count++;
       }
   }
   
   int start = 0, start_index = -1, min_len = INT_MAX;
   int count = 0;
   int curr_count[MAX_CHARS] = {0};
   for(int j=0; j<n; j++)
   {
       curr_count[s[j]]++;
       
       if(curr_count[s[j]] == 1)
            count++;
            
        if(count == dist_count)
        {
            while(curr_count[s[start]] > 1)
            {
                if(curr_count[s[start]] > 1)
                    curr_count[s[start]]--;
                start++;
            }
            
            int len_window = j - start + 1;
            if(min_len > len_window)
            {
                min_len = len_window;
                start_index = start;
            }
        }
   }
   string str = s.substr(start_index, min_len);
   //cout<<str<<endl;
   return min_len;
   
}

int main()
 {
	int t;cin>>t;
	while(t--)
	{
	    string s;
	    cin>>s;
	    cout<<distWind(s)<<endl;
	}
	return 0;
}