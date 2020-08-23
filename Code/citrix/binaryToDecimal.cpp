// Given a Binary Number B, Print its decimal equivalent.

// Input:
// 2
// 10001000
// 101100
// Output:
// 136
// 44

#include<iostream>
using namespace std;

int binaryToDecimal(long long n)
{
    int base = 1, dec = 0;;
    while(n)
    {
        int lastD = n%10;
        n = n/10;
        dec += lastD*base;
        base = base * 2;
    }
    return dec;
}

int main()
 {
	int t;cin>>t;
	while(t--)
	{
	    long long n; cin>>n;
	    cout<<binaryToDecimal(n)<<endl;
	}
	return 0;
}