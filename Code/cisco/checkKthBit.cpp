#include<iostream>
using namespace std;

bool checkBits(int n, int k)
{
    return (n & (1 << k));
}

int main()
 {
	int t;cin>>t;
	while(t--)
	{
	    int n,k;
	    cin>>n>>k;
	    (checkBits(n, k)) ? cout<<"Yes"<<endl : cout<<"No"<<endl;
	}
	return 0;
}