#include <bits/stdc++.h>
using namespace std;

stack<int> st;

void insert_at_bottom(int x)
{
    if(st.empty())
        st.push(x);
    else
    {
        int a = st.top();
        st.pop();
        insert_at_bottom(x);

        st.push(a);
    }
}

// 1 2 3 4 

void reverseST()
{
    if(st.size() > 0)
    {
        int x = st.top();
        st.pop();
        reverseST();

        insert_at_bottom(x);
    }
}

int main()
{
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    reverseST();
    while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
}