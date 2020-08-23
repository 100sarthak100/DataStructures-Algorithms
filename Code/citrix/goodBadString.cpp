// In this problem, a String S is composed of lowercase alphabets and wildcard characters i.e. '?'. Here, '?' can be replaced by any of the lowercase alphabets. Now you have to classify the given String on the basis of following rules:

// If there are more than 3 consonants together or more than 5 vowels together, the String is considered to be "BAD". A String is considered "GOOD" only if it is not “BAD”.

// NOTE: String is considered as "BAD" if the above condition is satisfied even once. Else it is "GOOD" and the task is to make the string "BAD".

// Example:
// Input:
// 2
// aeioup??
// bcdaeiou??
// Output:
// 1
// 0

#include<iostream>
using namespace std;

int gb(string s)
{
    int n = s.size();
    int vcount = 0;
    int ccount = 0;
    for(int i=0; i<n; i++)
    {
        if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
        {
            vcount++;
            ccount = 0;
        }
        else if(s[i] == '?')
        {
            vcount++;
            ccount++;
        }
        else
        {
            ccount++;
            vcount = 0;
        }
        
        if(vcount > 5 || ccount > 3)
            return 0;
    }
    return 1;
}

int main()
 {
	int t;cin>>t;
	while(t--)
	{
	    string s;
	    cin>>s;
	    cout<<gb(s)<<endl;
	}
	return 0;
}