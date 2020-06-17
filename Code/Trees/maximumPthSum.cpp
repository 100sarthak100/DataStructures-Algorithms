// Input:

// 2
// 3 4 5 -10 4
// -15 5 6 -8 1 3 9 2 -3 N N N N N 0 N N N N 4 -1 N N 10 N

// Output:

// 16
// 27

 

// Explanation:
// Testcase 2: The maximum possible sum from one leaf node to another is (3 + 6 + 9 + 0 + -1 + 10 = 27)

// time - O(n)

int maxPathSumUtil(Node* root, int &res)
{
    if(root == NULL) return 0;
    if(!root->left && !root->right) return root->data;
    
    int ls = maxPathSumUtil(root->left, res);
    int rs = maxPathSumUtil(root->right, res);
    
    if(root->left && root->right)
    {
        res = max(res, ls + rs + root->data);
        
        return max(ls, rs) + root->data;
    }
    
    return (!root->left)? rs + root->data : ls + root->data;
}

int maxPathSum(Node *root) {
    int res = INT_MIN;
    maxPathSumUtil(root, res);
    return res;
}