#include<iostream>
#include <string>
using namespace std;

void swap(char* a, char* b)
{
    char c = *a;
    *a = *b;
    *b = c;
}

string reverseString(string s)
{
    int r = s.size()-1;
    int l = 0;
    while(l < r)
    {
        swap(&s[l], &s[r]);
        l++;
        r--;
    }
    return s;
}

int main()
 {
	int t;
	cin>>t;
	while(t--)
	{
	    string s;
	    cin>>s;
	    cout<<reverseString(s)<<endl;
	}
	return 0;
}