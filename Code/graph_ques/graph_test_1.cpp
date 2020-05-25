#include <iostream>
#include <vector>
using namespace std;

vector<int> adj[1000];

int main()
{
    int x, y, nodes, edges, q, node1, node2;
    cin >> nodes >> edges;

    for (int i = 0; i < edges; ++i)
    {
        cin >> x >> y;
        adj[x].push_back(y);
    }
    cin >> q;
    for (int i = 0; i < q; ++i)
    {
        cin >> node1 >> node2;
        bool flag = false;
        for (int j = 0; j < adj[node1].size(); ++j)
        {
            if (adj[node1][j] == node2)
            {
                cout << "YES" << endl;
                flag = true;
                break;
            }
        }
        if (flag == false)
            cout << "NO" << endl;
    }
}