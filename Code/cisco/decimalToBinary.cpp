// Given a decimal number. Write a program to convert 
// it into equivalent binary number.

// Input:
// 3
// 7
// 10
// 33
// Output:
// 111
// 1010
// 100001

#include<iostream>
using namespace std;

void decimalToBin(int n)
{
    bool flag = false;
    for(int i=31; i>=0; i--)
    {
        int k = n >> i;
        if(k & 1)
        {
            cout<<1;
            flag = true;
        }
        else if(flag == true)
        {
            cout<<0;
        }
    }
}

int main()
 {
	int t;cin>>t;
	while(t--)
	{
	    int n;cin>>n;
	    decimalToBin(n);
	    cout<<endl;
	}
	return 0;
}