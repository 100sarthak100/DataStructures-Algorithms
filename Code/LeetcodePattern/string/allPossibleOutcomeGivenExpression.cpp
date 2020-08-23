#include <bits/stdc++.h>
using namespace std;

int eval(int a, char c, int b)
{
    if(c == '+')
        return a+b;
    if(c == '*')
        return a*b;
    if(c == '-')
        return a-b;
    return 0;
}

vector<int> evaluateAll(string expr, int l, int h)
{
    vector<int> res;
    if(l == h)
    {
        res.push_back({expr[l] - '0'});
        return res;
    }
    if(l == h - 2)
    {
        int num = eval(expr[l] - '0', expr[l+1], expr[l+2] - '0');
        res.push_back(num);
        return res;
    }
    
    for(int i=l+1; i<=h; i+=2)
    {
        vector<int> ll = evaluateAll(expr, l, i-1);
        vector<int> r = evaluateAll(expr, i+1, h);
        // for(auto x : ll)
        //     cout<<x<<" ";
        // cout<<endl;
        // for(auto x : r)
        //     cout<<x<<" ";
        // cout<<endl<<endl;
        for(int s1=0; s1<ll.size(); s1++)
        {
            for(int s2=0; s2<r.size(); s2++)
            {
                int val = eval(ll[s1], expr[i], r[s2]);
                res.push_back(val);
            }
        }
    }
    return res;
}

int main()
{
    string expr = "1*2+3*4"; 
    int len = expr.length(); 
    vector<int> ans = evaluateAll(expr, 0, len-1); 
  
    for (int i=0; i< ans.size(); i++) 
        cout << ans[i] << endl; 
  
    return 0;
}