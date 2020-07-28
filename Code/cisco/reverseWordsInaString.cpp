// Given a String of length S, reverse the whole string without 
// reversing the individual words in it. 
// Words are separated by dots.

// Input:
// 2
// i.like.this.program.very.much
// pqr.mno

// Output:
// much.very.program.this.like.i
// mno.pqr

#include<iostream>
using namespace std;

void swap(char* a, char* b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

void reverse(string &s)
{
    int sz = s.size();
    int i= 0;
    int j = sz - 1;
    while(i < j)
    {
        swap(&s[i], &s[j]);
        i++;
        j--;
    }
}

int main()
 {
	int t;cin>>t;
	while(t--)
	{
	    string s;cin>>s;
	    reverse(s);
	    string temp = "";
	    string ret = ""; 
	    int sz = s.size();
	    int i;
	    for(i=0; i<sz; i++)
	    {
	       if(s[i] != '.')
	       {
	            temp += s[i];
	       }
	       else
	       {
	           reverse(temp);
	           ret += temp;
	           ret += ".";
	           temp = "";
	       }
	    }
	    if(i == sz)
	    {
	        reverse(temp);
	        ret += temp;
	    }
	    cout<<ret<<endl;
	}
	return 0;
}