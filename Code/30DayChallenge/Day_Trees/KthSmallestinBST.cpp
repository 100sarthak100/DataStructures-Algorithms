// Given a Binary Search Tree (BST) and a positive integer k, find 
// the k’th smallest element in the Binary Search Tree.

// Inorder traversal of BST then elements are in Increasing order

// Input:
// 2
// 2 1 3
// 2
// 2 1 3
// 5
// Output:
// 2
// -1

// Using Inorder Traversal (O(n) time and O(h) auxiliary space)

Node* smallest(Node* root, int &k)
{
    if(root == NULL)
        return NULL;
    
    Node* leftVal = smallest(root->left, k);
    if(leftVal != NULL)
        return leftVal;
    
    k--;
    if(k == 0)
        return root;
    
    return smallest(root->right, k);
}

int KthSmallestElement(Node *root, int K)
{
    Node* val = smallest(root, K);  
    if(val != NULL)
        return val->data;
    else return -1;
}