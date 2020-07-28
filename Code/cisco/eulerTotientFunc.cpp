// Euler Totient Function (ETF) Φ(n) for an input n is count of 
// numbers in {1, 2, 3, …, n} that are relatively prime to n, i.e.,
//  the numbers 
// whose GCD (Greatest Common Divisor) with n is 1.

// Input:
// 2
// 11
// 16

// Output:
// 10
// 8

#include<iostream>
using namespace std;

int gcd(int a, int b)
{
    if(b == 0)
        return a;
    return gcd(b, a%b);
}

int tot(int n)
{
    int count = 0;
    for(int i=1; i<n; i++)
    {
        int g = gcd(n, i);
        if(g == 1)
            count++;
    }
    return count;
}

int main()
 {
	int t;cin>>t;
	while(t--)
	{
	    int n;cin>>n;
	    cout<<tot(n)<<endl;
	}
	return 0;
}