// #include <bits/stdc++.h>
// using namespace std;

// bool cmp(pair<string, int>& a, 
//          pair<string, int>& b) 
// { 
//     return a.second >= b.second; 
// } 
  
// void sort(map<string, int>& M) 
// { 
//     vector<pair<string, int> > A;  
//     for (auto& it : M) { 
//         A.push_back(it); 
//     } 
  
//     sort(A.begin(), A.end(), cmp); 
// } 

// map<string, vector<string>> func(int n, 
// map<string, vector<string>> userBook, 
// int numG, map<string, vector<string>> bookG)
// {
//     map<string, vector<string>> ret;
//     for(auto user : userBook)
//     {
//         map<string, int> mp;
//         for(auto book : user.second)
//         {
//             bool flag = false;
//             for(auto genre : bookG)
//             {
//                 auto vec = genre.second;
//                 if(find(vec.begin(), vec.end(), book) != vec.end())
//                 {
//                     mp[genre.first]++;
//                     flag = true;
//                 }
//                 if(flag)
//                     break;
//             }
//         }
//         sort(mp);
//         auto itr = mp.begin();
//         ret[user.first].push_back(itr->first);
//         int maxVal = itr->second;
//         itr++;

//         for(auto itr : mp)
//         {
//             if(itr.second == maxVal)
//                 ret[user.first].push_back(itr.first);
//         }
//     }
//     return ret;
// }

// class Solution {
// public:
    
//     void dfs(int node, int parent, vector<vector<int>> &adj,
//     vector<bool> &visited,
//     vector<int> &low,
//     vector<int> &order,
//     int &count,
//     vector<pair<int, int>>& bridges)
//     {
//         visited[node] = true;
//         low[node] = order[node] = count;
//         count++;
        
//         for(int neighbor : adj[node])
//         {
//             if(!visited[neighbor])
//             {
//                 dfs(neighbor, node);
                
//                 low[node] = min(low[node], low[neighbor]);
                
//                 if(order[node] < low[neighbor])
//                     bridges.push_back({node, neighbor});
//             }
//             else if(neighbor != parent)
//                 low[node] = min(low[node], order[neighbor]);
//         }
//     }
    
//     vector<pair<int, int>> criticalConnections(int n, int m, vector<pair<int, int>> connections)    {
//     vector<vector<int>> adj;
//     vector<bool> visited;
//     vector<int> low;
//     vector<int> order;
//     int count = 0;
//     vector<pair<int, int>> bridges;
//         adj.resize(n);
//         visited.resize(n, false);
//         low.resize(n, 0);
//         order.resize(n, 0);
        
//         for(auto edges : connections)
//         {
//             adj[edges.first].push_back(edges.second);
//             adj[edges.second].push_back(edges.first);
//         }
        
//         for(int i=0; i<n; i++)
//         {
//             if(!visited[i])
//                 dfs(i, -1, adj, visited, low, order, count, bridges);
//         }
//         return bridges;
//     }
// };

// #include <bits/stdc++.h>
// using namespace std;

// void swap(char *a, char *b)
// {
//     char temp = *a;
//     *a = *b;
//     *b = temp;
// }

// int strToInt(string s)
// {
//     int n = s.size();
//     int ret = 0;
//     int i = 0;
//     while(i < n)
//     {
//         int temp = s[i] - '0';
//         ret = ret*10 + temp;
//         i++;
//     }
//     return ret;
// }

// int func(int n)
// {
//     int arr[] = {9, 8, 7, 6, 5, 4, 3, 2 ,1, 0};
//     string ret;
//     while(n > 0)
//     {
//         int temp = n%10;
//         ret += (arr[temp] + '0');
//         n = n/10;
//     }
//     int i = 0, j = ret.size()-1;
//     while(i < j)
//     {
//         swap(&ret[i], &ret[j]);
//         i++;
//         j--;
//     }
//     int myint = strToInt(ret);
//     return myint;
// }

// int main()
// {
//     int n = 80;
//     cout<<func(n)<<endl;
// }


// #include <stdio.h>

// int main()
// {
    // int a;
    // char *x;
    // x = (char*) &a;
    // a = 512;
    // x[0] = 1;
    // x[1] = 2;
    // printf("%d\n", a);
    // return 0;

    // char a[] = {'A', 'B', 'C', 'D'};
    // char* ppp = &a[0];
    // *ppp++;
    // printf("%c %c\n", *++ppp, --*ppp);

    // int *ptr1, *ptr2;
    // ptr1 = malloc(4);
    // *ptr1 = 10;
    // *ptr2 = free(ptr1);
    // printf("%d\n", *ptr2);
    // return 0;

// }

#include <stdio.h>
void main()
{
    int s[][2] = {{2,6}, (4,8)};
    printf("%d", s);
}