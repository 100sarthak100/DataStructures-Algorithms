#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left, *right;
};

Node* newnode(int data)
{
    Node* newNode = new Node;
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

bool sumSubTreeUtil(Node* root, int* currSum, int sum)
{
    if(root == NULL)
    {
        *currSum = 0;
        return false;
    }

    int sumLeft = 0, sumRight = 0;
    return (sumSubTreeUtil(root->left, &sumLeft, sum) ||
            sumSubTreeUtil(root->right, &sumRight, sum) ||
            ((*currSum = sumLeft + sumRight + root->data) == sum));
}

bool sumSubTree(Node* root, int sum)
{
    int currSum = 0;
    return sumSubTreeUtil(root, &currSum, sum);
}

int main()
{
    Node* root = newnode(8);
    root->left = newnode(5); 
    root->right = newnode(4); 
    root->left->left = newnode(9); 
    root->left->right = newnode(7); 
    root->left->right->left = newnode(1); 
    root->left->right->right = newnode(12); 
    root->left->right->right->right = newnode(2); 
    root->right->right = newnode(11); 
    root->right->right->left = newnode(3); 

    int sum = 22;
    if(sumSubTree(root, sum))
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
}