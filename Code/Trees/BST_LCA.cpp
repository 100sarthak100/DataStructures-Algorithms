// least common ancestor O(n) (for BST)
// iterative

// Time Complexity: O(h).
// The Time Complexity of the above solution is O(h), where h is 
// the height of the tree.
// Space Complexity: O(1).
// The space complexity of the above solution is constant.

Node *lca(Node *root, int v1, int v2)
{
    while (root != NULL)
    {
        if (root->data > v1 && root->data > v2)
            root = root->left;
        else if (root->data < v1 && root->data < v2)
            root = root->right;
        else
            break;
    }
    return root;
}

// recursive
Node* lca(Node* root, int v1, int v2)
{
    if(root == NULL) return NULL;

    if(root->data > v1 && root->data > v2)
        lca(root->left,v1,v2);
    else if(root->data < v1 && root->data < v2)
        lca(root->right,v1,v2);

    return root;
}