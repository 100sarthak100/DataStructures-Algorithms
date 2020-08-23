// Given a number, you need to check whether any permutation of 
// the number is 
// divisible by 8 or not. Print Yes or No.

// Input:
// 2
// 46
// 345
// Output:
// Yes
// No

#include<bits/stdc++.h>
using namespace std;

void swap(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

void reverse(string &temp)
{
    int n = temp.size();
    int i = 0, j = n-1;
    while(i < j)
    {
        swap(&temp[i], &temp[j]);
        i++;
        j--;
    }
    return;
}

string intToStr(int n)
{
    string temp;
    while(n != 0)
    {
        int num = n%10;
        temp.push_back(num + '0');
        n = n/10;
    }
    reverse(temp);
    return temp;
}

int strToint(string s)
{
    int n = s.size();
    int dec = 0;
    for(int i=n-1; i>=0; i--)
    {
        dec = dec*10 + (s[i] - '0');
    }
    return dec;
}

int main()
 {
	int t;cin>>t;
	while(t--)
	{
	    int n;cin>>n;
	    
	    string s = intToStr(n);
	    sort(s.begin(), s.end());
	    int sz = s.size();
	    bool isFinished = false;
	    int flag = 0;
	    while(!isFinished)
	    {
	        int num = strToint(s);
	        if(num%8 == 0)
	        {
	            cout<<"Yes"<<endl;
	            flag = 1;
	            break;
	        }
	        
	        int i;
	        for(i = sz-2; i>=0; i--)
	        {
	            if(s[i] < s[i+1])
	                break;
	        }
	        if(i == -1)
	            isFinished = true;
	        else
	        {
	            for(int x = sz-1; x>i; x--)
	            {
	                if(s[x] > s[i])
	                {
	                    swap(&s[x], &s[i]);
	                    break;
	                }
	            }
	            sort(s.begin()+i+1, s.end());
	        }
	    }
	    if(flag == 0)
	        cout<<"No"<<endl;
	}
	return 0;
}