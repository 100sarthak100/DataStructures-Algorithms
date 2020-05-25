int isLeaf(Node* root)
{
    if(root == NULL) return 0;
    if(root->left == NULL && root->right == NULL)
        return 1;
    else return 0;
}


bool isSumTree(Node* root)
{
    
    int ls;
    int rs;
    
    if(root == NULL || isLeaf(root))
        return 1;
        
    while(isSumTree(root->left) && isSumTree(root->right))
    {
        if(root->left == NULL)
            ls = 0;
        else if(isLeaf(root->left))
            ls = root->left->data;
        else ls = 2*(root->left->data);
        
        if(root->right == NULL)
            rs = 0;
        else if(isLeaf(root->right))
            rs = root->right->data;
        else rs = 2*(root->right->data);
        
        return(root->data == ls + rs);
    }
    return 0;
}