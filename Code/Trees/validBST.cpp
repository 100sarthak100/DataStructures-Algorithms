bool isBST(Node *root)
{
    Node *prev = NULL;
    return isBSTUtil(root, prev);
}

bool isBSTUtil(Node *root, Node *&prev)
{
    if (root)
    {
        if (!isBSTUtil(root->left, prev))
            return false;
        if (prev != NULL && root->data <= prev->data)
            return false;
        prev = root;
        return isBSTUtil(root->right, prev);
    }
    return true;
}

// alternate version
bool isBSTValid(TreeNode *root, int minValue, int maxValue)
{
    if (root == NULL)
        return 1;
    if (root->val > minValue &&
        root->val < maxValue &&
        isBSTValid(root->left, minValue, root->val) &&
        isBSTValid(root->right, root->val, maxValue))
        return 1;
    else
        return 0;
}

int Solution::isValidBST(TreeNode *A)
{
    return isBSTValid(A, INT_MIN, INT_MAX);
}