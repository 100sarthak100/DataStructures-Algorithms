// #include <bits/stdc++.h>
// using namespace std;

// int setCount(int n)
// {
// 	int count = 0;
// 	while(n)
// 	{
// 		n = n&(n-1);
// 		count++;
// 	}
// 	return count;
// }

// int main()
// {
// 	int t;cin>>t;
// 	while(t--)
// 	{
// 		int n;cin>>n;
// 		cout<<setCount(n)<<endl;
// 	}
// }

// // alternate
// // You are given a number N. Find the total count of set bits for all numbers 
// // from 1 to N(both inclusive).
// int countSetBits(int n){
    
//     int sum = 0;
//     for(int i = 1;i<=n;i++)
//     {
//         int count = 0;
//         int x = i;
//         while(x)
//         {
//             x = x&(x-1);
//             count++;
//         }
//         sum += count;
//     }
//     return sum;
    
// }

// time - log(n) time , cause dividing everytime by 2
#include <bits/stdc++.h>
using namespace std;

int countSetBits(int n)
{
    int count = 0;
    while(n > 0)
    {
        if(n&1)
            count++;
        n = n >> 1;
    }
    return count;
}

int main()
{
    int n = 4;
    cout<<countSetBits(n)<<endl;
}