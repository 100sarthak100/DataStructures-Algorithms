#include<iostream>
using namespace std;

int setBit(int n, int k)
{
    return (n | (1 << k));
        
    
}

int main()
 {
	int t;cin>>t;
	while(t--)
    {
        int n, k;
        cin>>n>>k;
        cout<<setBit(n, k)<<endl;
    }
	return 0;
}