// Input:
// 2
// 1
// 1 4 7 5 6 
// 5
// 7 10 4 11 2 5 9 
// Output:
// 5 4 6 7 
// 11 10 2 7 9 4 

// Time Comp = O(N)
// Space Comp=O(N)

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* left, *right;
};

Node* newNode(int key)
{
    Node* temp = new Node;
    temp->data = key;
    temp->left = temp->right = NULL;
    return temp;
}

void inorder(Node* root)
{
    if(root == NULL) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void deletionBT(struct Node* root, int key)
{
    if(root == NULL) return;
    if(!root->left && !root->right)
    {
        if(root->data == key)
        {
            root = NULL;
            return;
        }
        else return;
    }
    
    queue<Node*> q;
    q.push(root);
    Node* temp;
    Node* key_node = NULL;
    Node* lastParent = NULL;
    while(!q.empty())
    {
        temp = q.front();
        q.pop();
        if(temp->data == key)
            key_node = temp;
        
        if(temp->left)
        {
            lastParent = temp;
            q.push(temp->left);
        }
        if(temp->right)
        {
            lastParent = temp;
            q.push(temp->right);
        }
    }
    if(key_node != NULL)
    {
        int x = temp->data;
        key_node->data = x;
        if(lastParent->left == temp)
            lastParent->left = NULL;
        else lastParent->right = NULL;
    }
    return;
}

int main()
{
    Node* root = newNode(10);
    root->left = newNode(11);
    root->left->left = newNode(7);
    root->left->right = newNode(12);
    root->right = newNode(9);
    root->right->left = newNode(15);
    root->right->right = newNode(8);

    inorder(root);

    int key = 11;
    root = deletion(root, key);

    cout<<endl;
    inorder(root);

}