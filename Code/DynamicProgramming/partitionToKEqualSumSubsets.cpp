// Input : arr = [2, 1, 4, 5, 6], K = 3
// Output : Yes
// we can divide above array into 3 parts with equal
// sum as [[2, 4], [1, 5], [6]]

// Input  : arr = [2, 1, 5, 5, 6], K = 3
// Output : No
// It is not possible to divide above array into 3
// parts with equal sum


#include <bits/stdc++.h>
using namespace std;

// backtracking (printing all k sets)
bool sumPartition(int arr[], int n, int sum, int sumTemp, int k, int index, bool visited[], vector<vector<int>> &ret, vector<int> &vec)
{
    if(k == 1)
    {
        vec.clear();
        for(int i=0;i <n;i++)
        {
            if(visited[i] == false)
            {
                vec.push_back(arr[i]);
            }
        }
        ret.push_back(vec);
        return true;
    }
    
    if(sumTemp == sum)
    {
        ret.push_back(vec);
        vec.clear();
        return sumPartition(arr, n, sum, 0, k-1 , 0, visited, ret, vec);
    }

    for(int i = index; i<n;i++)
    {
        if(!visited[i])
        {
            visited[i] = true;
            vec.push_back(arr[i]);
            if(sumPartition(arr, n, sum, sumTemp + arr[i], k, i+1, visited, ret, vec))
                return true;
            visited[i] = false;
            vec.pop_back();
        }
    }
    return false;
}

void isPossible(int arr[], int n, int k)
{
    int sum = 0;
    for(int i = 0;i<n;i++)
        sum += arr[i];
    if(k == 0 || sum%k != 0)
    {
        cout<<"Partition not possible "<<endl;
        return;
    }

    bool visited[n+1];
    for(int i = 0; i<= n;i++)
        visited[i] = false;
    
    int sumTemp = 0, index = 0;
    vector<vector<int>> ret;
    vector<int> vec;

    if(sumPartition(arr, n, sum/k, sumTemp, k, index, visited, ret, vec))
    {
        cout<<"Partition is possible "<<endl;
        for(auto i : ret)
        {
            vector<int> temp = i;
            for(auto x : i)
                cout<<x<<" ";
            cout<<endl;
        }
    }
    else 
        cout<<"Partition not possible "<<endl;  
    return;
}

int main()
{
    //int arr[] = {1, 5, 11, 5};
    //int arr[] = {1, 3, 5};
    int arr[] = {2, 1, 4, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    //int k = 2;
    int k = 3;
    
    isPossible(arr, n, k);
}


