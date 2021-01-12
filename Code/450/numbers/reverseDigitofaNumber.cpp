// Input
// 4
// 12345
// 31203
// 2123
// 2300
// Output
// 54321
// 30213
// 3212
// 32

#include <iostream>
using namespace std;

int main() {
	int t;cin>>t;
	while(t--)
	{
	    long long n;cin>>n;
	    long long val = 0;
	    while(n)
	    {
	        val = val*10 + n%10;
	        n = n/10;
	    }
	    cout<<val<<endl;
	}
	return 0;
}