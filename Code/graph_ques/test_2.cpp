#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> adj[10];
    adj[1].push_back(3);
    adj[1].push_back(4);
    adj[1].push_back(2);
    for (int i = 0; i < 5; i++)
    {
        if (adj[1][i] != NULL)
            cout << "adjacency list: " << 1 << " -> " << adj[1][i] << endl;
    }
}
