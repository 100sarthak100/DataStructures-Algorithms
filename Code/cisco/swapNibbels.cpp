#include<iostream>
using namespace std;
int main()
 {
	int t;cin>>t;
	while(t--)
	{
	    int n;cin>>n;
	    int fh = (n & (15 << 4));
	    int sh = (n & 15);
	    fh = fh >> 4;
	    sh = sh << 4;
	   
	    n = 0 | fh;
	    n = n | sh;
	    cout<<n<<endl;
	}
	return 0;
}

// #include <bits/stdc++.h> 
// using namespace std; 
  
// int swapNibbles(int x) 
// { 
//     return ( (x & 0x0F) << 4 | (x & 0xF0) >> 4 ); 
// } 
  
// // Driver code 
// int main() 
// { 
//     int x = 100; 
//     cout << swapNibbles(x); 
//     return 0; 
// }