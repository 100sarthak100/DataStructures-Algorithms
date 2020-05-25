// input - 
// 11       no of nodes (head node == 1)
// 2 3      
// 4 -1
// 5 -1
// 6 -1
// 7 8
// -1 9
// -1 -1
// 10 11
// -1 -1
// -1 -1
// -1 -1
// 2
// 2
// 4
//          1                     1                          1             
//         / \                   / \                        / \            
//        /   \                 /   \                      /   \           
//       2     3    [s]        2     3                    2     3          
//      /      /                \     \                    \     \         
//     /      /                  \     \                    \     \        
//    4      5          ->        4     5          ->        4     5       
//   /      / \                  /     / \                  /     / \      
//  /      /   \                /     /   \                /     /   \     
// 6      7     8   [s]        6     7     8   [s]        6     7     8
//  \          / \            /           / \              \         / \   
//   \        /   \          /           /   \              \       /   \  
//    9      10   11        9           11   10              9     10   11 
// output - 
// 2 9 6 4 1 3 7 5 11 8 10
// 2 6 9 4 1 3 7 5 10 8 11


#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left, *right;
};

Node* newNode(int data)
{
    Node* newnode = new Node;
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}


Node* insert(vector<vector<int>> &indexes)
{
    queue<Node*> q;
    Node* head = newNode(1);
    Node* temp;
    q.push(head);
    int i = 0;
    while(!q.empty())
    {
        temp = q.front();
        q.pop();
        if(i < indexes.size())
        {
            int l = indexes[i][0];
            int r = indexes[i][1];
            if(l == -1)
                temp->left = NULL;
            else
            {
                Node* left = newNode(l);
                temp->left = left;
                q.push(temp->left);
            }
            if(r == -1)
                temp->right = NULL;
            else 
            {
                Node* right = newNode(r);
                temp->right = right;
                q.push(temp->right);
            }
        }
        i++;
    }
    return head;
}

void inOrder(Node* head, vector<int> &vec)
{
    if(head == NULL) return;
    inOrder(head->left, vec);
    cout<<head->data<<" ";
    vec.push_back(head->data);
    inOrder(head->right, vec);
}

vector<vector<int>> swapNodes(vector<vector<int>> indexes, vector<int> queries) {
    Node* head = insert(indexes);
    vector<vector<int>> ret;
    for(int i = 0;i<queries.size();i++)
    {
        int level = 1;
        vector<int> vec;
        int quer = queries[i];
        queue<Node*> q1, q2;
        q1.push(head);
        Node* temp;
        while(!q1.empty())
        {
            temp = q1.front();
            q1.pop();
            //cout<<level<<" "<<quer<<endl;
            if(level % quer == 0)
            {
                Node* swapT = temp->left;
                temp->left = temp->right;
                temp->right = swapT;
            }
            if(temp->left)
            {
                q2.push(temp->left);
            }
            if(temp->right)
            {
                q2.push(temp->right);
            }
            if(q1.empty())
            {
                swap(q1, q2);
                level++;
            }
        }
        inOrder(head, vec);
        cout<<endl;
        ret.push_back(vec);
        vec.clear();
    }
    return ret;
}