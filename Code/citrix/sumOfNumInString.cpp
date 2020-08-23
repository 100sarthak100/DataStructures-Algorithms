// Given a string str containing alphanumeric characters, 
// calculate sum 
// of all numbers present in the string.

// Input:
// 4
// 1abc23
// geeks4geeks
// 1abc2x30yz67
// 123abc

// Output:
// 24
// 4
// 100
// 123

// Explanation:
// Testcase 1: 1 and 23 are numbers in the string which 
// is added to get the sum as 24.
// Testcase 4: 123 is a single number, so sum is 123.

#include<iostream>
using namespace std;

int sumNum(string s)
{
    int n = s.size();
    int num = 0, sum = 0;
    for(int i=0; i<n; i++)
    {
        if(s[i] >= '0' && s[i] <= '9')
        {
            num = num*10 + (s[i] - '0');
        }
        else
        {
            sum += num;
            num = 0;
        }
    }
    sum += num;
    return sum;
}

int main()
 {
	int t;cin>>t;
	while(t--)
	{
	    string s;cin>>s;
	    cout<<sumNum(s)<<endl;
	}
	return 0;
}