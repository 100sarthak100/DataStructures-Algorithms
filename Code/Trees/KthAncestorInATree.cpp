bool rootToNode(Node* root, int node, vector<int> &v)
{
    if(root == NULL) return false;
    
    v.push_back(root->data);
    //cout<<root->data<<" ";
    
    if(root->data == node)
        return true;
        
    if( rootToNode(root->left, node, v) || 
    rootToNode(root->right, node, v))
        return true;
        
    v.pop_back();
    return false;
}


int kthAncestor(Node *root, int k, int node)
{
    vector<int> v;
    rootToNode(root, node, v);
    // for(auto x : v)
    //     cout<<x<<" ";
    if(k > v.size() - 1 || k <= 0)
        return -1;
    else return v[v.size() - 1 - k];
}