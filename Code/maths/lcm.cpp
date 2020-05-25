#include <bits/stdc++.h>
using namespace std;
#define ll long long

// a x b = LCM(a, b) * GCD (a, b)
// LCM(a, b) = (a x b) / GCD(a, b) 
//  O(Log min(a, b)) to calculate gcd

// int gcd(int a, int b)
// {
//     if(b == 0) return a;
//     return gcd(b, a%b);
// }

// int lcm(int a, int b)
// {
//     return (a * b)/gcd(a, b);
// }

// int main()
// {
//     int a = 15, b = 20;
//     cout<<lcm(a,b)<<endl;
// }

// GCD of two numbers when one of them can be very large
// Given two numbers ‘a’ and ‘b’ such that (0 <= a <= 10^12 and b <= b < 10^250). 
// Find the GCD of two given numbers.
// Input: a = 978 
//        b = 89798763754892653453379597352537489494736
// Output: 6

// Input: a = 1221 
//        b = 1234567891011121314151617181920212223242526272829
// Output: 3

ll gcd(ll a, ll b) 
{ 
    if (!a) 
       return b; 
    return gcd(b%a,a); 
} 

ll reduceB(ll a, char b[]) 
{ 
    // Initialize result 
    ll mod = 0; 
    // calculating mod of b with a to make 
    // b like 0 <= b < a 
    for (int i=0; i<strlen(b); i++) 
    {
        mod = (mod*10 + b[i] - '0')%a; 
        
    }
    cout<<mod;
    return mod; // return modulo 
} 

ll gcdLarge(ll a, char b[]) 
{ 
    // Reduce 'b' (second number) after modulo with a 
    ll num = reduceB(a, b); 
    // gcd of two numbers 
    return gcd(a, num); 
} 

int main() 
{ 
    // first number which is integer 
    ll a = 1221; 
  
    // second number is represented as string because 
    // it can not be handled by integer data type 
    char b[] = "1234567891011121314151617181920212223242526272829"; 
    if (a == 0) 
        cout << b; 
    else
        cout << gcdLarge(a, b); 
  
    return 0; 
} 