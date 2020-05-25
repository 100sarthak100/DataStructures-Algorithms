void for


void top_view(Node *root)
{
    if (root->left != NULL)
        for_left(root->left);
    cout << root->data << " ";
    if (root->right != NULL)
        for_right(root->right);
    return;
}