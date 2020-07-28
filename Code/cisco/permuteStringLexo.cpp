#include<bits/stdc++.h>
using namespace std;

void swap(char* a, char* b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

void reverse(string s, int l, int r)
{
    while(l < r)
    {
        swap(&s[l], &s[r]);
        l++;
        r--;
    }
}

void permut(string s)
{
   int sz = s.size();
   sort(s.begin(), s.end());
   bool isFinished = false;
   
   while(!isFinished)
   {
       cout<<s<<" ";
       
       int i;
       for(i = sz-2; i>=0; i--)
            if(s[i] < s[i+1])
                break;
       
        if(i == -1)
            isFinished = true;
        else
        {
            for(int x = sz-1; x>i; x--)
            {
                if(s[x] > s[i])
                {
                    swap(&s[i], &s[x]);
                    break;
                }
            }
            sort(s.begin()+i+1, s.end());
        }
   }
}

int main()
 {
	int t;cin>>t;
	while(t--)
	{
	    string s;cin>>s;
	    permut(s);
	    cout<<endl;
	}
	return 0;
}