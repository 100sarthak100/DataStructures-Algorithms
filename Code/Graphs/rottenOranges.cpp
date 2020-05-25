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