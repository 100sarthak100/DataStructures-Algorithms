// Given a string s, a k duplicate removal consists of 
// choosing k adjacent and equal letters from s and removing them 
// causing the left and the right side of the deleted substring to 
// concatenate together.

// We repeatedly make k duplicate removals on s until we no longer 
// can.

// Return the final string after all such duplicate removals have 
// been made.

// It is guaranteed that the answer is unique.

// Example 1:

// Input: s = "abcd", k = 2
// Output: "abcd"
// Explanation: There's nothing to delete.
// Example 2:

// Input: s = "deeedbbcccbdaa", k = 3
// Output: "aa"
// Explanation: 
// First delete "eee" and "ccc", get "ddbbbdaa"
// Then delete "bbb", get "dddaa"
// Finally delete "ddd", get "aa"
// Example 3:

// Input: s = "pbbcggttciiippooaais", k = 2
// Output: "ps"

// Time Complexity – O(N)

class Solution {
public:
    void swap(char *a, char *b)
    {
        char temp = *a;
        *a = *b;
        *b = temp;
    }
    
    void reverse(string &s)
    {
        int i = 0;
        int j = s.size()-1;
        while(i < j)
        {
            swap(&s[i], &s[j]);
            i++;
            j--;
        }
    }
    
    string removeDuplicates(string s, int k) {
        int n = s.size();
        pair<char, int> p;
        stack<pair<char, int>> st;
        for(int i=0; i<n; i++)
        {
            char x = s[i];
            if(st.size() > 0 && st.top().second == k)
            {
                char curr = st.top().first;
                
                while(st.size() > 0 && st.top().first == curr)
                    st.pop();
            }
            
            if(st.size() > 0 && st.top().first == x)
            {
                p = {x, st.top().second + 1};
                st.push(p);
            }
            else
            {
                p = {x, 1};
                st.push(p);
            }
        }
        
        if(st.size() > 0 && st.top().second == k)
        {
            char curr = st.top().first;
                
            while(st.size() > 0 && st.top().first == curr)
                st.pop();
        }
        
        string temp;
        while(!st.empty())
        {
            temp += st.top().first;
            st.pop();
        }
        reverse(temp);
        return temp;
    }
};