
// calulate (A^B/C)*M
// - (A^B%M) * (C^-1%M)

#include <bits/stdc++.h>
using namespace std;

// Time complexity: O(log N)
// Memory complexity: O(1)
long long expo(long long a, long long b, long long m)
{
	if(b == 0)
		return 1;
	else if(b%2 == 0)
		return expo((a*a)%m, b/2, m);
	else
		return (a*expo((a*a)%m, (b-1)/2, m))%m;
}

// time - O(log max(A, B))
long long d, x, y;
void extendedEuclid(long long A, long long B) {
    if(B == 0) {
        d = A;
        x = 1;
        y = 0;
    }
    else {
        extendedEuclid(B, A%B);
        long long temp = x;
        x = y;
        y = temp - (A/B)*y;
    }
}

long long modularInverse(long long c, long long m)
{
	extendedEuclid(c, m);
	return (x%m+m)%m;
}

int main()
{
	long long a, b, c, m;
	cin>>a>>b>>c>>m;
	long long expoVal = expo(a, b, m);
	long long deno = modularInverse(c, m);
	//cout<<expoVal<<" "<<deno<<endl;
	cout<<(expoVal*deno)%m<<endl;
}