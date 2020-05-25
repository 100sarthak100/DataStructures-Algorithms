// 3 0 0 0
// 0 3 3 0
// 0 1 0 3
// 0 2 3 3

// o/p = 1

#include <bits/stdc++.h>
using namespace std;

bool isValid(int x, int y, int arr[][20], int n, bool**visited)
{
    return (x >= 0 && y >= 0 && x < n && y < n && !visited[x][y] && arr[x][y] != 0);
}


bool dfs(int i, int j, int arr[][20], int n, bool** visited)
{
    visited[i][j] = true;
    if(arr[i][j] == 2)
        return true;
    
    static int dx[] = {-1, 0, 0, 1};
    static int dy[] = {0, -1, 1, 0};
    
    for(int p = 0;p<4;p++)
    {
        if(isValid(i + dx[p], j + dy[p], arr, n, visited))
        {
            
            bool b = dfs(i + dx[p], j + dy[p], arr, n, visited);
	            if(b)
	                return true;
        }
    }
    return false;
}


int main() {
	
	int t;cin>>t;
	while(t--)
	{
	    int n;cin>>n;
	    int arr[20][20];
	    for(int i = 0;i<n;i++)
	        for(int j = 0;j<n;j++)
	            cin>>arr[i][j];
	            
	   bool ** visited = new bool*[n+1];
	   for(int i = 0;i<=n;i++)
	        visited[i] = new bool[n+1];
	   for(int i = 0;i<=n;i++)
	   {
	    for(int j = 0;j<=n;j++)
	    {
	        if(arr[i][j] == 0)
	            visited[i][j] = true;
	       else visited[i][j] = false;
	    }
	   }
	   int flag = 0;
	   
	   for(int i = 0;i<n;i++)
	   {
	       for(int j = 0;j<n;j++)
	       {
	           if(arr[i][j] == 1)
	           {
	           //cout<<i<<" "<<j<<endl;
	            bool b = dfs(i, j, arr, n, visited);
	            if(b)
	            {
	                cout<<1<<endl;
	                flag = 1;
	                break;
	            }
	           }
	       }
	       if(flag == 1) break;
	   }
	   if(flag != 1)
	    cout<<0<<endl;
	}
	return 0;
}