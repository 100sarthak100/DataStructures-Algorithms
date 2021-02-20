// Given a word pat and a text txt. Return the count of the occurences 
// of anagrams of the word in the text.

// Example 1:

// Input:
// txt = forxxorfxdofr
// pat = for
// Output: 3
// Explanation: for, orf and ofr appears
// in the txt, hence answer is 3.

// Example 2:

// Input:
// txt = aabaabaa
// pat = aaba
// Output: 4
// Explanation: aaba is present 4 times
// in txt.

// Time - O(N)
// Space - O(K)

class Solution{
public:
	int search(string pat, string txt) {
	    unordered_map<char, int> mp;
	    for(int i=0; i<pat.size(); i++)
	        mp[pat[i]]++;
	        
	    int count = mp.size(), ans = 0;
	    int i = 0, j = 0, k = pat.size();
	    while(j < txt.size())
	    {
	        if(mp.find(txt[j]) != mp.end())
	        {
	            mp[txt[j]]--;
	            if(mp[txt[j]] == 0)
	                count--;
	        }
	        
	        if(j - i + 1 < k)
	            j++;
	        else if(j - i + 1 == k)
	        {
	            if(count == 0)
	                ans++;
	            if(mp.find(txt[i]) != mp.end())
	            {
	               mp[txt[i]]++;
	               if(mp[txt[i]] == 1)
	                   count++;
	            }
	            
	            i++;
	            j++;
	        }
	    }
	    return ans;
	}
};