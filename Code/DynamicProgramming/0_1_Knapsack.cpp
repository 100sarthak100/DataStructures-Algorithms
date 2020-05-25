// Given weights and values of n items, put these items in a 
// knapsack of 
// capacity W to get the maximum total value in the knapsack.

#include <bits/stdc++.h>
using namespace std;

// using recursion
// int knapSack(int W, int wt[], int val[], int n)
// {
//     if(n == 0 || W == 0)
//         return 0;

//     if(wt[n-1] > W)
//         return knapSack(W, wt, val, n-1);

//     else return max(val[n-1] + knapSack(W - wt[n-1], wt, val, n-1),
//                     knapSack(W, wt, val, n-1));
// }


//using dp
int knapSack(int W, int wt[], int val[], int n)
{
    int i, w;
    int K[n+1][W+1];

    for(i = 0;i<=n;i++)
    {
        for(w = 0;w<=W;w++)
        {
            if(i==0 || w==0)
                K[i][w] = 0;
            else if(wt[i-1] <= w)
                K[i][w] = max(val[i-1] + K[i-1][w - wt[i-1]], 
                            K[i-1][w]);
            else
                K[i][w] = K[i-1][w];
        }
    }
    for(int i = 0;i<=n;i++)
    {
        for(int j = 0;j<=W;j++)
            cout<<K[i][j]<<" ";
        cout<<endl;
    }

    return K[n][W];

}

int main()
{
    int val[] = {1, 2, 3};
    int wt[] = {4, 5, 1};
    int W = 4;
    int n = sizeof(val)/sizeof(val[0]);
    cout<<knapSack(W, wt, val, n);
    return 0;
}
