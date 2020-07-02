// Write a function that takes two parameters n and k and returns the value of 
// Binomial Coefficient C(n, k).

// Input: n = 4 and k = 2
// Output: 6
// Explanation: 4 C 2 is 4!/(2!*2!) = 6

// Input: n = 5 and k = 2
// Output: 10
// Explanation: 5 C 2 is 5!/(3!*2!) = 20

//  O(k) time and O(1) extra space.

// C(n, k) = n! / (n-k)! * k!
// Also, C(n, k) = C(n, n-k)  
// r can be changed to n-r if r > n-r

//Value of C(8, 2) is 28

#include <bits/stdc++.h>
using namespace std;

int binomialCoeff(int n, int k)
{
    if(k > n-k)
        k = n - k;

    int res = 1;
    for(int i=0; i<k; i++)
    {
        res *= (n - i);
        res /= (i + 1);
    }

    return res;
}

int main() 
{ 
    int n = 8, k = 2; 
    cout << "Value of C(" << n << ", "
         << k << ") is " << binomialCoeff(n, k); 
    return 0; 
} 