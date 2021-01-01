#include <bits/stdc++.h>
using namespace std;

vector<int> minChairs(vector<string> simulation)
{
    int free, total;
    vector<int> ret;
    for(auto s : simulation)
    {
        total = 0, free = 0;
        for(auto c : s)
        {
            if(c == 'C')
            {
                if(free > 0)
                    free--;
                else
                    total++; 
            }
            else if(c == 'R')
                free++;
            else if(c == 'U')
            {
                if(free > 0)
                    free--;
                else
                    total++;
            }
            else
                free++;
        }
        ret.push_back(total);
    }
    return ret;
}

int main()
{
    vector<string> ret;
    ret.push_back("CCRUCL");
    ret.push_back("CRUC");
    ret.push_back("CCCC");
    vector<int> num = minChairs(ret);
    for(auto i : num)
        cout<<i<<" ";
}