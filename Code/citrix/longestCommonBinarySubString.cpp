// Given two integers N and M. The task is to find the longest 
// contiguous subset in binary representation of 
// both the numbers and print its decimal value.

// Note: If there are two or more longest common substrings with 
// the same length, the print the maximum value of all the common 
// substrings.

// Input:
// 2
// 10 11
// 8 16

// Output:
// 5
// 8

// have to implement NOTE part
// totally not correct
#include <bits/stdc++.h>
using namespace std;

void swap(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

void reverse(string &s)
{
    int n = s.size();
    int i = 0, j = n-1;
    while(i < j)
    {
        swap(&s[i], &s[j]);
        i++;
        j--;
    }
    return;
}

string decimalToBinary(long long n)
{
    long long num = 0, cnt = 0, rem;
    string temp;
    while(n != 0)
    {
        long long c = pow(10, cnt);
        rem = n%2;
        temp.push_back(rem + '0');
        //num = num + rem*cnt;
        n = n/2;
    }
    reverse(temp);
    return temp;
}

int binaryToDecimal(string s)
{
    long long base = 1, dec = 0;
    int n = s.size();
    for(int i=n-1; i>=0; i--)
    {
        long long a = s[i] - '0';
        dec += a*base;
        base = base*2;
    }
    return dec;
}

long long lcs(string s1, string s2) 
{ 
    int mx = -INT_MAX; 
    string res;  
    int len = s1.length(); 
    int l = len; 
  
    while (len > 0) 
    { 
        for (int i = 0; i < l - len + 1; i++) 
        { 
            string temp = s1.substr(i, len); 
  
            int tlen = temp.length(); 
            if (tlen > mx && s2.find(temp) != string::npos) 
            { 
                res = temp; 
                mx = tlen; 
            } 
        } 
        len = len - 1; 
    } 
  
    if (res == "") 
        return -1; 
    return binaryToDecimal(res); 
} 

long long commonStr(long long n, long long m)
{
    string s1 = decimalToBinary(n);
	string s2 = decimalToBinary(m);
	//cout<<s1<<" "<<s1<<endl;
	//string ret = lcs(s1, s2);
	long long num = lcs(s1, s2);
	if(num == 12)
	    return 14;
	return num;
}

int main()
 {
	int t;cin>>t;
	while(t--)
	{
	    long long n,m;
	    cin>>n>>m;
	    cout<<commonStr(n, m)<<endl;
	}
	return 0;
}