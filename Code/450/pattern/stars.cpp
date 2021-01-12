// Input :

// First Line contains T i.e. number of test case.
// Each of the next T lines contain an integer N.

// Output:

// For each test case print the pattern of N lines then after a blank line.
// SAMPLE INPUT

// 3
// 9
// 2
// 5

// SAMPLE OUTPUT

// *################*
// **##############**
// ***############***
// ****##########****
// *****########*****
// ******######******
// *******####*******
// ********##********
// ******************

// *##*
// ****

// *########*
// **######**
// ***####***
// ****##****
// **********

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;cin>>t;
	while(t--)
	{
		int n;cin>>n;
		int g = n;
		for(int i=1; i<=n; i++)
		{
			for(int j=1; j<=i; j++)
				cout<<"*";
			for(int j=1; j<=((g*2)-2); j++)
			{
				cout<<"#";
			}
			g--;
			for(int j=1; j<=i; j++)
				cout<<"*";
			cout<<endl;
		}
	}
	return 0;
}