// Given Postorder and Inorder traversals, construct the tree.

// Examples:

// Input : 
// in[]   = {2, 1, 3}
// post[] = {2, 3, 1}

// Output : Root of below tree
//       1
//     /   \
//    2     3 


// Input : 
// in[]   = {4, 8, 2, 5, 1, 6, 3, 7}
// post[] = {8, 4, 5, 2, 6, 7, 3, 1} 

// Output : Root of below tree
//           1
//        /     \
//      2        3
//    /    \   /   \
//   4     5   6    7
//     \
//       8

// Time Complexity : O(n)
// best solution
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

Node* buildTreeUtil(int in[], int post[], int start, int end, 
int* postIndex, unordered_map<int, int>& mp)
{
    if(start > end)
        return NULL;
    
    int curr = post[*postIndex];
    (*postIndex)--;
    Node* tNode = makeNode(curr);

    if(start == end)
        return tNode;

    int inIndex = mp[curr];

    tNode->right = buildTreeUtil(in, post, inIndex+1, end, postIndex, mp);
    tNode->left = buildTreeUtil(in, post, start, inIndex-1, postIndex, mp);
    return tNode;
}

Node* buildTree(int in[], int post[], int n)
{
    unordered_map<int, int> mp;
    for(int i=0; i<n; i++)
        mp[in[i]] = i;
    
    int postIndex = n-1;

    return buildTreeUtil(in, post, 0, n-1, &postIndex, mp);
}

void inorder(Node* root)
{
    if(root == NULL)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main()
{
    int in[] = { 4, 8, 2, 5, 1, 6, 3, 7 }; 
    int post[] = { 8, 4, 5, 2, 6, 7, 3, 1 }; 
    int n = sizeof(in) / sizeof(in[0]); 
  
    Node* root = buildTree(in, post, n); 
    cout<<"inorder traversal "<<endl;
    inorder(root);
    return 0;
}