// Given candidate set 10,1,2,7,6,1,5 and target 8,

// A solution set is:

// [1, 7]
// [1, 2, 5]
// [2, 6]
// [1, 1, 6]

// using backtacking and repition is not allowed
#include <bits/stdc++.h>
using namespace std;

void waysSum(vector<int> &A, int n, int index, int sum, vector<vector<int>> &ret, vector<int> &vec)
{
    if (sum == n && find(ret.begin(), ret.end(), vec) == ret.end())
    {
        ret.push_back(vec);
        return;
    }
    for (int i = index; i < A.size(); i++)
    {
        vec.push_back(A[i]);
        sum += A[i];
        waysSum(A, n, i, sum, ret, vec);
        sum -= A[i];
        vec.pop_back();
    }
    return;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int m, n, a;
        cin >> m >> n;
        vector<int> A;
        for (int i = 0; i < m; i++)
        {
            cin >> a;
            A.push_back(a);
        }
        int index = 0;
        vector<vector<int>> ret;
        vector<int> vec;
        int sum = 0;
        sort(A.begin(), A.end());
        waysSum(A, n, index, sum, ret, vec);
        if (!ret.empty())
        {
            for (auto i : ret)
            {
                vector<int> temp = i;
                for (auto x : i)
                    cout << x << " ";
                cout << endl;
            }
        }
    }
}

// Input : arr = {1, 5, 6}, N = 7
// Output : 6

// Explanation:- The different ways are:
// 1+1+1+1+1+1+1
// 1+1+5
// 1+5+1
// 5+1+1
// 1+6
// 6+1

// repition is allowed
int countWays(int arr[], int m, int N)
{
    int count[N+1];
    memset(count, 0, sizeof(count));

    count[0] = 1;

    for(int i = 1; i <= N; i++)
        for(int j = 0; j < m;j++)
            if(i >= arr[j])
                count[i] += count[i - arr[j]];

    for(int i = 0; i <= N; i++)
            cout<<count[i]<<" ";

    return count[N];
}

int main()
{
    int arr[] = {1, 5, 6}; 
    int m = sizeof(arr) / sizeof(arr[0]); 
    int N = 7; 
    cout<<countWays(arr, m, N)<<endl;
}