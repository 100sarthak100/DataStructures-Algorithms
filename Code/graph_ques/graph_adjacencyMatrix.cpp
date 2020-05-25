#include <iostream>
using namespace std;

bool A[10][10];

void initialize()
{
    for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j < 10; ++j)
            A[i][j] = false;
    }
}

int main()
{
    int x, y, nodes, edges;
    initialize();
    cin >> nodes; // no of nodes
    cin >> edges; // no of edges
    for (int i = 0; i < edges; ++i)
    {
        cin >> x >> y;
        A[x][y] = true;
    }
    for (int i = 0; i <= nodes; ++i)
    {
        for (int j = 0; j <= nodes; ++j)
            cout << A[i][j] << " ";
        cout << endl;
    }
}