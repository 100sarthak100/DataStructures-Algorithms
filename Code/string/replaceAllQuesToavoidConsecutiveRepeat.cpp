// Given a string s containing only lower case English letters and 
// the '?' character, convert all the '?' characters into lower case 
// letters such that the final string does not contain any consecutive 
// repeating characters. You cannot modify the non '?' characters.

// It is guaranteed that there are no consecutive repeating characters 
// in the given string except for '?'.

// Return the final string after all the conversions (possibly zero) 
// have been made. If there is more than one solution, return any of 
// them. It can be shown that an answer is always possible with the 
// given constraints.

 

// Example 1:

// Input: s = "?zs"
// Output: "azs"
// Explanation: There are 25 solutions for this problem. From "azs" 
// to "yzs", all are valid. Only "z" is an invalid modification as the 
// string will consist of consecutive repeating characters in "zzs".
// Example 2:

// Input: s = "ubv?w"
// Output: "ubvaw"
// Explanation: There are 24 solutions for this problem. Only "v" and 
// "w" are invalid modifications as the strings will consist of 
// consecutive repeating characters in "ubvvw" and "ubvww".
// Example 3:

// Input: s = "j?qg??b"
// Output: "jaqgacb"
// Example 4:

// Input: s = "??yw?ipkj?"
// Output: "acywaipkja"

class Solution {
public:
    string modifyString(string s) {
        string a = "";
        int n = s.size();
        char prevChar = 'a', afterChar = 'a';
        bool map[256] = {false};
        for(int i=0; i<n; i++)
        {
            if(s[i] == '?')
            {
                if(i > 0)
                {
                    prevChar = s[i-1];
                    if(prevChar == '?')
                        prevChar = a[a.size()-1];
                    map[prevChar] = true;
                }
                
                if(i < n-1)
                {
                    afterChar = s[i+1];
                    map[afterChar] = true;
                }
                
                for(int i=97; i<=122; i++)
                {
                    if(map[i] == false)
                    {
                        a += char(i);
                        map[prevChar] = false;
                        map[afterChar] = false;
                       
                        break;
                    }
                }
            }
            else
                a += s[i];
        }
        return a;
    }
};