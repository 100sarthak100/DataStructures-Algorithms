// Given a BST (Binary Search Tree) that may be unbalanced, 
// convert it into a balanced BST 
// that has minimum possible height.

// Input:
//        30
//       /
//      20
//     /
//    10
// Output:
//      20
//    /   \
//  10     30


// Input:
//          4
//         /
//        3
//       /
//      2
//     /
//    1
// Output:
//       3            3           2
//     /  \         /  \        /  \
//    1    4   OR  2    4  OR  1    3   OR ..
//     \          /                   \
//      2        1                     4 

// Input:
//           4
//         /   \
//        3     5
//       /       \
//      2         6 
//     /           \
//    1             7
// Output:
//        4
//     /    \
//    2      6
//  /  \    /  \
// 1    3  5    7 

// Time - O(n)

#include <bits/stdc++.h> 
using namespace std; 
  
struct Node 
{ 
    int data; 
    Node* left,  *right; 
}; 

void store(Node* root, vector<Node*> &ret)
{
    if(root == NULL)
        return;
    
    store(root->left, ret);
    ret.push_back(root);
    store(root->right, ret);
}

Node* makeBBST(vector<Node*> ret, int start, int end)
{
    if(start > end)
        return NULL;
    
    int mid = (start + end)/2; 
    Node* root = ret[mid];

    root->left = makeBBST(ret, start, mid-1);
    root->right = makeBBST(ret, mid+1, end);
    return root;
}

Node* buildTree(Node* root)
{
    vector<Node*> ret;
    store(root, ret);
    int start = 0, end = ret.size()-1;
    Node* head = makeBBST(ret, start, end);
    return head;
}

Node* newNode(int data) 
{ 
    Node* node = new Node; 
    node->data = data; 
    node->left = node->right = NULL; 
    return (node); 
} 
  
/* Function to do preorder traversal of tree */
void preOrder(Node* node) 
{ 
    if (node == NULL) 
        return; 
    printf("%d ", node->data); 
    preOrder(node->left); 
    preOrder(node->right); 
} 
  
// Driver program 
int main() 
{ 
    /* Constructed skewed binary tree is 
                10 
               / 
              8 
             / 
            7 
           / 
          6 
         / 
        5   */
  
    Node* root = newNode(10); 
    root->left = newNode(8); 
    root->left->left = newNode(7); 
    root->left->left->left = newNode(6); 
    root->left->left->left->left = newNode(5); 
  
    root = buildTree(root); 
  
    printf("Preorder traversal of balanced "
            "BST is : \n"); 
    preOrder(root); 
  
    return 0; 
} 