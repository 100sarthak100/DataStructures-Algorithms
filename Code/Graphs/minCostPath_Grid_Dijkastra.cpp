#include <bits/stdc++.h>
using namespace std;

struct cell
{
    int x, y;
    int distance;
    cell(int x, int y, int distance) : x(x), y(y), distance(distance) {}
};

bool operator <(const cell &a, const cell &b)
{
    if (a.distance == b.distance)
    {
        if (a.x != b.x)
            return (a.x < b.x);
        else
            return (a.y < b.y);
    }
    return (a.distance < b.distance);
}

bool isInsideGrid(int row, int col, int ROW, int COL)
{
    return (row >= 0) && (col >= 0) && (row < ROW) && (col < COL);
}

int shortest(int arr[][50], int n, int m)
{
    set<cell> st;

    int dis[n][m];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            dis[i][j] = INT_MAX;

    int dx[] = {-1, 0, 0, 1};
    int dy[] = {0, -1, 1, 0};

    st.insert(cell(0, 0, 0));
    dis[0][0] = arr[0][0];

    while (!st.empty())
    {
        cell k = *st.begin();
        st.erase(st.begin());
        for (int i = 0; i < 4; ++i)
        {
            int x = k.x + dx[i];
            int y = k.y + dy[i];

            if (!isInsideGrid(x, y, n, m))
                continue;

            if (dis[x][y] > dis[k.x][k.y] + arr[x][y])
            {
                if (dis[x][y] != INT_MAX)
                    st.erase(st.find(cell(x, y, dis[x][y])));

                dis[x][y] = dis[k.x][k.y] + arr[x][y];
                st.insert(cell(x, y, dis[x][y]));
            }
        }
    }
    for (int i = 0; i < n; i++, cout << endl)
        for (int j = 0; j < m; j++)
            cout << dis[i][j] << " ";
    return dis[n - 1][m - 1];
}

int main()
{
    int t, n, m;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        int arr[50][50];
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                cin >> arr[i][j];
        cout << shortest(arr, n, m) << endl;
    }
}

// another soln
#include<bits/stdc++.h>
using namespace std;

int grid[101][101];
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

typedef pair<int, pair<int, int>> pll;

bool isValid(int x, int y, int n)
{
    return (x>=0 && y>=0 && x<n && y<n);
}

int minCost(int n)
{
    bool visited[n+1][n+1];
    for(int i=0; i<=n; i++)
        for(int j=0; j<=n; j++)
            visited[i][j] = false;
    
    int dp[n+1][n+1];
    for(int i=0; i<=n; i++)
        for(int j=0; j<=n; j++)
            dp[i][j] = INT_MAX;
    
    pll p = {grid[0][0], {0, 0}};
    priority_queue<pll, vector<pll>, greater<pll>> q;
    q.push(p);
    dp[0][0] = grid[0][0];
    while(!q.empty())
    {
        p = q.top();
        q.pop();
        int x = p.second.first;
        int y = p.second.second;
        if(visited[x][y])
            continue;
        
        visited[x][y] = true;
        
        for(int pp=0; pp<4; pp++)
        {
            int newx = dx[pp] + x;
            int newy = dy[pp] + y;
            if(!isValid(newx, newy, n) || visited[newx][newy])
                continue;
            
            if(dp[newx][newy] > grid[newx][newy] + dp[x][y])
            {
                dp[newx][newy] = grid[newx][newy] + dp[x][y];
                q.push({dp[newx][newy], {newx, newy}});
            }
        }
    }
    return dp[n-1][n-1];
}

int main()
 {
	int t;cin>>t;
	while(t--)
	{
	    int n;cin>>n;
	    for(int i=0; i<n; i++)
	        for(int j=0; j<n; j++)
	            cin>>grid[i][j];
	   
	   cout<<minCost(n)<<endl;
	}
	return 0;
}