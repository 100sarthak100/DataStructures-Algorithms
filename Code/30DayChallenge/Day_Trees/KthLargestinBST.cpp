// Given a Binary search tree. Your task is to complete the function 
// which will return the Kth largest element without doing any 
// modification in Binary Search Tree.

// Time complexity: The code first traverses down to the rightmost 
// node which takes O(h) time, then traverses k elements in O(k) time. 
// Therefore overall time complexity is O(h + k).

// Example:
// Input:
// 2
// 4 2 9 1 3 N 10
// 3
// 9 N 10
// 1
// Output:
// 4
// 10

Node* largest(Node* root, int &k)
{
    if(root == NULL)
        return NULL;
    
    Node* rightVal = largest(root->right, k);
    if(rightVal != NULL)
        return rightVal;
    k--;
    if(k == 0)
        return root;
    
    return largest(root->left, k);
}

int kthLargest(Node *root, int K)
{
    Node* value = largest(root, K);
    if(value != NULL)
        return value->data;
    else
        return -1;
}
