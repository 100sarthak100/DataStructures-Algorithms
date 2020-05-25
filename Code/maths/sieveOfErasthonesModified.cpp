#include <bits/stdc++.h>
using namespace std;
const long long MAX_SIZE = 1000001; 

// isPrime[] is true if number is prime
// prime[] stores all prime number less than N
// SPF[] that stores smallest prime factor of number
vector<long long> isPrime(MAX_SIZE, true);
vector<long long> prime;
vector<long long> SPF(MAX_SIZE);

void manipulated_seive(int N)
{
    isPrime[0] = isPrime[1] = false;

    for(long long int i = 2; i<N; i++)
    {
        if(isPrime[i])
        {
            prime.push_back(i);
            SPF[i] = i;
        }

        for(long long int j = 0;
        j < (int)prime.size() && 
        i*prime[j] < N && prime[j] <= SPF[i];
        j++)
        {
            isPrime[i*prime[j]] = false;
            SPF[i*prime[j]] = prime[j];
        }
        
    }
}

int main()
{
    // prime number till N
    int N = 123 ; // Must be less than MAX_SIZE 
    manipulated_seive(N); 
    // pint all prime number less then N 
    for (int i=0; i<prime.size() && prime[i] <= N ; i++) 
        cout << prime[i] << " "; 
  
    return 0; 
}