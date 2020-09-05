struct ret
{
    int x;
    int y;
};

bool isValid(int x, int y, int R, int C, vector<vector<int> > &matrix)
{
    return (x >= 0 && y >= 0 && x < R && y < C && matrix[x][y] == 1);
}

bool checkAll(vector<vector<int> > &matrix)
{
    for(int i = 0;i<matrix.size();i++)
        for(int j = 0;j <matrix[0].size();j++)
            if(matrix[i][j] == 1)
                return false;
    return true;
}

bool delim(ret temp)
{
    return (temp.x == -1 && temp.y == -1);
}


int rotOranges(vector<vector<int> > matrix, int R, int C)
{
    queue<ret> q;
    ret temp;
    int ans = 0;
    for(int i = 0;i < R; i++)
    {
        for(int j = 0; j < C ; j++)
        {
            if(matrix[i][j] == 2)
            {
                temp.x = i;
                temp.y = j;
                q.push(temp);
            }
        }
    }
    
    temp.x = -1;
    temp.y = -1;
    q.push(temp);
    
    while(!q.empty())
    {
        bool flag = false;
        
        while(!delim(q.front()))
        {
            temp = q.front();
            
            if(isValid(temp.x +1, temp.y, R, C, matrix))
            {
                matrix[temp.x +1][temp.y] = 2;
                temp.x++;
                q.push(temp);
                temp.x--;
                if(!flag) ans++, flag = true;
            }
            
            if(isValid(temp.x -1, temp.y, R, C, matrix))
            {
                matrix[temp.x -1][temp.y] = 2;
                temp.x--;
                q.push(temp);
                temp.x++;
                if(!flag) ans++, flag = true;
            }
            
            if(isValid(temp.x, temp.y +1, R, C, matrix))
            {
                matrix[temp.x][temp.y +1] = 2;
                temp.y++;
                q.push(temp);
                temp.y--;
                if(!flag) ans++, flag = true;
            }
            
            if(isValid(temp.x, temp.y -1, R, C, matrix))
            {
                matrix[temp.x][temp.y -1] = 2;
                temp.y--;
                q.push(temp);
                temp.y++;
                if(!flag) ans++, flag = true;
            }
        
            q.pop();
        
        }
        q.pop();
        if(!q.empty())
        {
            temp.x =  -1;
            temp.y =  -1;
            q.push(temp);
        }
        
    }
    
    return (checkAll(matrix)) ? ans : -1;
}


// using for loop
// Input:
// 2
// 3 5
// 2 1 0 2 1 1 0 1 2 1 1 0 0 2 1
// 3 5
// 2 1 0 2 1 0 0 1 2 1 1 0 0 2 1

// Output:
// 2
// -1


#include<bits/stdc++.h>
using namespace std;

int arr[101][101];

bool isValid(int x, int y, int r, int c)
{
    return (x>=0 && x<r && y>=0 && y<c);
}

bool delim(pair<int, int> p)
{
    return (p.first == -1 && p.second == -1);
}

bool checkAll(int arr[][101], int r, int c)
{
    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            if(arr[i][j] == 1)
                return false;
        }
    }
    return true;
}

int oranges(int arr[][101], int r, int c)
{
    queue<pair<int, int>> q;
    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            if(arr[i][j] == 2)
                q.push({i, j});
        }
    }
    
    q.push({-1, -1});
    int dx[] = {-1, 0, 0, 1};
    int dy[] = {0, -1, 1, 0};
    int ans = 0;
    while(!q.empty())
    {
        bool flag = false;
        while(!delim(q.front()))
        {
            pair<int, int> p = q.front();
            q.pop();
            for(int pp=0; pp<4; pp++)
            {
                int newx = dx[pp] + p.first;
                int newy = dy[pp] + p.second;
                if(isValid(newx, newy, r, c) && arr[newx][newy] == 1)
                {
                    arr[newx][newy] = 2;
                    q.push({newx, newy});
                    if(!flag)
                    {
                        ans++;
                        flag = true;
                    }
                }
            }
        }
        q.pop();
        if(!q.empty())
            q.push({-1, -1});
    }
    return (checkAll(arr, r, c)) ? ans : -1;
}

int main()
 {
	int t;cin>>t;
	while(t--)
	{
	    int r, c;
	    cin>>r>>c;
	    for(int i=0; i<r; i++)
	        for(int j=0; j<c; j++)
	            cin>>arr[i][j];
	   cout<<oranges(arr, r, c)<<endl;
	    
	}
	return 0;
}