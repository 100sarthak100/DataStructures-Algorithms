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
#include<math.h>
using namespace std;

void decimalToBin(int n)
{
    int num = 0, rem, cnt = 0;
    while(n > 0)
    {
        rem = n%2;
        int c = pow(10, cnt);
        num = num + rem*c;
        n = n/2;
        cnt++;
        //cout<<num<<" "<<n<<endl;
    }
    cout<<num;
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