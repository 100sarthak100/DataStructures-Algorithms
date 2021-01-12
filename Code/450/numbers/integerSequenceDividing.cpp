//codeforces
// Input
// The first line of the input contains one integer n(1≤n≤2⋅109).

// Output
// Print one integer — the minimum possible value of |sum(A)−sum(B)|
// if you divide the initial sequence 1,2,…,n into two sets A and B.

// The first solution: take n modulo 4 and solve the problem manually 
// (then for cases n=0 and n=3 the answer is 0 and for n=1 and n=2 the 
// answer is 1).

// Prove: Let's see what can we make for numbers n, n−1, n−2 and n−3. 
// We can add n and n−3 in A and add n−1 and n−2 in B. Then the difference
//  between sums will be 0. We can consider last four numbers this way 
//  until we have at least four numbers. And then we have a case 
//  n≤3. We can prove the solution for these four cases using bruteforce.

// The second solution: if ∑i=1ni
// is even then the answer is 0 otherwise the answer is 1. 
// The formula above is just n(n+1)2.

// Prove: if we have an integer sequence 1,2,…,n
// then we can obtain every number from 0 to n(n+1)2 as the sum of 
// some elements of this sequence. How? Greedily! You can see how this 
// greedy works (and prove, if you want) yourself. So what's next? 
// If n(n+1)2 is even then we can obtain the sum n(n+1)4 in A and in B. 
// Otherwise we can only obtain ⌊n(n+1)4⌋ in A and ⌈n(n+1)4⌉ in B 
// (or vice versa).

#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n;
    cin>>n;
    long long sum = n*(n+1)/2;
    cout<<(sum & 1)<<endl;

    return 0;
}

//second solution

int main()
{
    long long n;
    cin>>n;
    n = n%4;
    if(n == 1 || n == 3)
        cout<<0<<endl;
    else
        cout<<1<<endl;
}