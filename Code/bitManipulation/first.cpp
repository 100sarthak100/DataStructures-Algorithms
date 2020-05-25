
/*
1) return log2(n & -n)+1 - > returns the position of the rightmost set bit....
2)log2(n)+1 -> returns the number of digits in the binary representation of the given number
3)log10(n)+1 -> returns the number of digits in the number decimal number O(1) time
4)x=x&(x-1) -> turn off the rightmost set bit
5)1<<n --=""> 1*(2^n) and all the term will be zero except the one

2 = 0000 0010
~2 = 1111 1101 (~ negates the flip)(it does 1's comp)
1's complement + 1 = 2's compliment
1111 1101 + 1 = 1111 1110
~2 is -3 */
#include <bits/stdc++.h>
using namespace std;

int getFirstSetBit(int n)
{
    if (n == 0)
        return 0;
    return log2(n & -n) + 1;
}

int main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
    }
    cout << getFirstSetBit(n) << endl;
}
