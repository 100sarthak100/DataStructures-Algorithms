Node *insert(Node *root, int data)
{
    if (root == NULL)
    {
        Node *newNode = new Node(data);
        newNode->left = NULL;
        newNode->right = NULL;
        root = newNode;
        return root;
    }
    else if (data <= root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);

    return root;
}
