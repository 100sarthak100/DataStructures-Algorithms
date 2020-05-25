// Input:
// 1
// 4
// GEEKS FOR QUIZ GO
// 3 3
// G I Z U E K Q S E

// Output:
// GEEKS QUIZ

// we can move to any of 8 adjacent characters, 
// but a word should not have multiple instances of same cell.

#include<bits/stdc++.h>
using namespace std;
#define MAX 7
set<string> st;
char boggle[MAX][MAX];
bool visited[MAX][MAX];

int dx[] = {-1,1,0,1,-1,0,1,-1};
int dy[] = {1,-1,1,0,0,-1,1,-1};

bool isSafe(int x, int y, int n, int m)
{
    return (x>=0 && y>=0 && x<n && y<m && !visited[x][y]);
}

bool find(string s, int i, int j, int n, int m, int k)
{
    visited[i][j] = true;
    k++;
    if(k == s.length())
        return true;
        
    for(int p = 0;p<8;p++)
    {
        int newX = i + dx[p];
        int newY = j + dy[p];
        if(isSafe(newX, newY, n, m) && boggle[newX][newY] == s[k])
            return find(s, newX, newY, n, m, k);
    }
    
}


int main()
 {
	int t;cin>>t;
	while(t--)
	{
	    int dicSize;cin>>dicSize;
	    vector<string> dict;
	    for(int i = 0;i<dicSize;i++)
	    {
	        string s;
	        cin>>s;
	        dict.push_back(s);
	    }
	   
	   int n, m;cin>>n>>m;
	   for(int i = 0;i<n;i++)
	        for(int j = 0;j<m;j++)
	            cin>>boggle[i][j];
	   
	   st.clear();
	   for(int x = 0;x<dicSize;x++)
	   {
	       memset(visited, false, sizeof(visited));
	       string s = dict[x];
	       for(int i = 0;i<n;i++)
	       {
	           for(int j = 0; j<m;j++)
	           {
	               if(boggle[i][j] == s[0])
	               {
	                   if(find(s, i, j, n, m, 0))
	                   {
	                       st.insert(s);
	                       break;
	                   }
	               }
	           }
	       }
	   }
	   if(!st.empty())
	   {
	       for(auto i : st)
	            cout<<i<<" ";
	       cout<<endl;
	   }
	   else cout<<-1<<endl;
	   
	   
	}
	return 0;
}

