// Prime numbers are those numbers that are greater than 1 and 
// have only two factors 1 and itself.

// Composite numbers are also numbers that are greater than 1 but 
// they have at least one more divisor other than 1 and itself.

// For example, 5 is a prime number because 5 is divisible only by 
// 1 and 5 only. However, 6 is a composite number as 6 is divisible 
// by 1, 2, 3, and 6.

// To check primarilty in O(N^1/2)
bool isPrime(int n) {
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

// time - O(N^1/2)
void checkPrime(int n)
{
    int count = 0;
    for(int i=1; i*i<=n; i++)
    {
        if(n%i == 0)
        {
            if(i*i == n)
                count++;
            else // i < sqrt(n) and (n/i) > sqrt(n)
                count += 2;
        } 
    }
    if(count == 2)
        cout<<"N is prime"<<endl;
    else
        cout<<"N is not prime"<<endl;
}

// Sieve of Eratosthenes
// time - O(NloglogN)
void sieve(int n)
{
    bool isPrime[n+1];
    for(int i=0; i<=n; i++)
        isPrime[i] = true;
    isPrime[0] = false;
    isPrime[1] = false;
    for(int i=2; i*i<=n; i++)
    {
        if(isPrime[i] == true)
        {
            for(int j=i*i; j<=n; j+=i)
                isPrime[j] = false;
        }
    }
}

// Modification of Sieve of Eratosthenes for fast factorization
// Factorization in O(N^1/2)
vector<int> factorize(int n)
{
    vector<int> res;
    for(int i=2; i*i<=n; i++)
    {
        while(n%i == 0)
        {
            res.push_back(i);
            n /= i;
        }
    }
    if(n != 1)
        res.push_back(n);
    return res;
}











