// Given a binary tree, a target node in the binary tree, and an 
// integer value k, print all the nodes that are at distance k from 
// the given target node. 
// No parent pointers are available.

// time complexity is O(n).

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* newnode(int data)
{
    Node* newNode = new Node;
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void inorder(Node* root)
{
    if(root == NULL)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void printkdistanceNodeDown(Node* root, int k)
{
    if(root == NULL || k < 0)
        return;
    if(k == 0)
    {
        cout<<root->data<<" ";
        return;
    }
    printkdistanceNodeDown(root->left, k-1);
    printkdistanceNodeDown(root->right, k-1);
}

int printkdistanceNode(Node* root, Node* target, int k)
{
    if(root == NULL)
        return -1;
    
    if(root == target)
    {
        printkdistanceNodeDown(root, k);
        return 0;
    }

    int dl = printkdistanceNode(root->left, target, k);

    if(dl != -1)
    {
        if(dl + 1 == k)
            cout<<root->data<<endl;
        else
            printkdistanceNodeDown(root->right, k - 2 - dl);

        return dl + 1;
    }

    int dr = printkdistanceNode(root->right, target, k);

    if(dr != -1)
    {
        if(dr + 1 == k)
            cout<<root->data<<endl;
        else
            printkdistanceNodeDown(root->left, k - 2 - dr);
        
        return dr + 1;
    }
    return -1;
}

int main()
{
    Node * root = newnode(20); 
    root->left = newnode(8); 
    root->right = newnode(22); 
    root->left->left = newnode(4); 
    root->left->right = newnode(12); 
    root->left->right->left = newnode(10); 
    root->left->right->right = newnode(14); 
    //inorder(root);

    Node * target = root->left; // 8 
    printkdistanceNode(root, target, 2); 
}