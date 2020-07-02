// output -
// 1 1 2 5 14 42 132 429 1430 4862 16796

// C0 = 1, C(n+1) = SUM(i=0 to n) {C(i) * C(n-i)} for n>=0 
// Time Complexity: Time complexity of above implementation is O(n2)

// dp
// #include <bits/stdc++.h>
// using namespace std;

// unsigned long int catalan(unsigned int n)
// {
//     unsigned long int dp[n+1];
//     dp[0] = dp[1] = 1;

//     for(int i=2; i<=n; i++)
//     {
//         dp[i] = 0;
//         for(int j=0; j<i; j++)
//             dp[i] += dp[j] * dp[i - j - 1];
//     }
//     return dp[n];
// }

// int main()
// {
//     for(int i=0; i<=10; i++)
//     {
//         cout<<catalan(i)<<" ";
//     }
// }

// using binomial coefficient;
// C(n) = (1 / (n + 1)) * 2n C n 

// Time Complexity: Time complexity of above implementation 
// is O(n).

// best soln
#include <bits/stdc++.h>
using namespace std;

unsigned long int binomialCoeff(unsigned int n, unsigned int k)
{
    if(k > n - k)
        k = n - k;

    unsigned long int res = 1;
    for(int i=0; i<k; i++)
    {
        res *= (n - i);
        res /= (i + 1);
    }

    return res;
}

unsigned long int catalan(unsigned int n)
{
    unsigned long int c = binomialCoeff(2*n, n);
    return c/(n+1);
}

int main()
{
    for(int i = 0; i<10; i++)
        cout<<catalan(i)<<" ";
}