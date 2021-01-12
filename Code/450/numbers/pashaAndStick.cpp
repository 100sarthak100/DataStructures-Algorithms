// Input

// The first line of the input contains a positive integer n 
// (1 ≤ n ≤ 2·109) — the length of Pasha's stick.
// Output

// The output should contain a single integer — the number of ways to 
// split Pasha's stick into four parts of positive integer length so 
// that it's possible to make a rectangle by connecting the ends of 
// these parts, 
// but is impossible to form a square. 

// If the given n is odd the answer is 0, because the perimeter of any 
// rectangle is always even number.

// If n is even the number of rectangles which can be construct equals 
// to n / 4. If n is divisible by 4 we will count the square, which are 
// deprecated, 
// because we need to subtract 1 from the answer.

// Time - O(1)
// Space - O(1)

#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n;cin>>n;
    if(n%2 != 0)
        cout<<0<<endl;
    else
    {
        if(n%4 == 0)
            cout<<(n/4)-1<<endl;
        else
            cout<<(n/4)<<endl;
    }
    return 0;
}