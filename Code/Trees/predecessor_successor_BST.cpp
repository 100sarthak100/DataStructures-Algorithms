// Given a BST and a key. The task is to find the inorder successor 
// and predecessor of the given key. In case, if either of predecessor
// or successor is not present, then print -1.

// Input:          50
//                /  \
//               /    \
//             30     70
//            / \     / \
//           /   \   /   \
//          20   40 60   80
//             key = 65
// Output: Predecessor : 60
//         Successor : 70

// Input:          50
//                /  \
//               /    \
//             30     70
//            / \     / \
//           /   \   /   \
//          20   40 60   80
//             key = 100
// Output: predecessor : 80
//         successor : -1
// Explanation: As no node in BST has key value greater 
// than 100 so -1 is printed for successor.

// Predecessor is 60
// Successor is 70

// Time Complexity: O(N)
// Auxiliary Space: O(1)

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

Node* insert(Node* root, int data)
{
    if(root == NULL)
        return makeNode(data);
    else if(root->data > data)
        root->left = insert(root->left, data);        
    else
        root->right = insert(root->right, data);
    return root;
}

void findPreSuc(Node* root, Node*& pre, Node*& suc, int data)
{
    if(root == NULL)
        return;

    while(root != NULL)
    {
        if(root->data == data)
        {
            if(root->left)
            {
                pre = root->left;
                while(pre->right)
                    pre = pre->right;
            }

            if(root->right)
            {
                suc = root->right;
                while(suc->left)
                    suc = suc->left;
            }

            return;
        }
        else if(root->data > data)
        {
            suc = root;
            root = root->left;
        }
        else
        {
            pre = root;
            root = root->right;
        }
    }
}

int main()
{
    Node* root = NULL;
    root = insert(root, 50); 
    root = insert(root, 30); 
    root = insert(root, 20); 
    root = insert(root, 40); 
    root = insert(root, 70); 
    root = insert(root, 60); 
    root = insert(root, 80);

    Node *pre = NULL, *suc = NULL;
    int key = 65;
    findPreSuc(root, pre, suc, key); 

    if(pre != NULL)
        cout<<"predecessor "<<pre->data<<" ";
    else cout<<-1<<" ";

    if(suc != NULL)
        cout<<"successor "<<suc->data<<" ";
    else cout<<-1<<" ";

    return 0;
}