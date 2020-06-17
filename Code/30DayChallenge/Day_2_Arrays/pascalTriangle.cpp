// Given a positive integer K, return the Kth row of pascal triangle.

// Example :
// 1
// 1 1
// 1 2 1
// 1 3 3 1
// For K = 3, return 3rd row i.e 1 2 1

// Input:
// 1
// 4
// Output:
// 1 3 3 1

// ( O(n^2) time and O(1) extra space )

#include<iostream>
using namespace std;

void triangle(int k)
{
    for(int line=1; line<=k; line++)
    {
        int c = 1;
        for(int i = 1; i<=line; i++)
        {
            if(line == k)
                cout<<c<<" ";
            c = c*(line - i)/i;
        }
    }
    cout<<endl;
}

// triangle with space
void triangleSpace(int k)
{
    for(int line=1; line<=k; line++)
    {
        int c = 1;
        for(int space = line; space <=k; space++)
            cout<<" ";
        for(int i = 1; i<=line; i++)
        {
            cout<<c<<" ";
            c = c*(line - i)/i;
        }
        cout<<endl;
    }
    cout<<endl;
}

int main()
 {
	int t;cin>>t;
	while(t--)
	{
	    int n; cin>>n;
	    //triangle(n);
        triangleSpace(n);
	}
	return 0;
}