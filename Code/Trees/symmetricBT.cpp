// Check for Symmetric Binary Tree (Iterative Approach)
// mirror image of itself
// Given a binary tree, check whether it is a mirror of 
// itself without recursion.

// Input :   
    
//      1
//    /   \
//   2     2
//  / \   / \
// 3   4 4   3

// Output : Symmetric

// Input :    
   
//     1
//    / \
//   2   2
//    \   \
//    3    3

// Output : Not Symmetric


// output -
// The given tree is Symmetric
// time - O(N)
// iterative approach

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* makeNode(int data)
{
    Node* newNode = new Node;
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

bool check(Node* root)
{
    if(root == NULL)
        return false;
    
    if(!root->left && !root->right)
        return true;
    
    queue<Node*> q;
    q.push(root);
    q.push(root);

    Node* left, *right;

    while(!q.empty())
    {
        left = q.front();
        q.pop();
        right = q.front();
        q.pop();
        if(left->data != right->data)
            return false;

        if(left->left && right->right)
        {
            q.push(left->left);
            q.push(right->right);
        }
        else if(left->left || right->right)
            return false;

        if(left->right && right->left)
        {
            q.push(left->right);
            q.push(right->left);
        }
        else if(left->right || right->left)
            return false;
    }
    return true;
}

int main()
{
    Node *root = makeNode(1); 
    root->left = makeNode(2); 
    root->right = makeNode(2); 
    root->left->left = makeNode(3); 
    root->left->right = makeNode(4); 
    root->right->left = makeNode(4); 
    root->right->right = makeNode(3);

    if(check(root))
        cout<<"Is symmetric"<<endl;
    else cout<<"Not symmetric"<<endl; 

    return 0;
}