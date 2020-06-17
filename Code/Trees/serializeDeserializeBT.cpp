// using preorder traversal

// Input:
// 2
// 1 2 3
// 10 20 30 40 60
// Output:
// 2 1 3
// 40 20 60 10 30

void serialize(Node *root,vector<int> &A)
{
    if(root == NULL)
    {
        A.push_back(-1);
        return;
    }
    
    A.push_back(root->data);
    serialize(root->left, A);
    serialize(root->right, A);
}

int i = 0;
Node * deSerialize(vector<int> &A)
{
   if(A[i] == -1 || i > A.size())
   {
       i++;
       i %= A.size();
       return NULL;
   }
   Node* root = new Node(A[i]);
   i++;
   i %= A.size();
   root->left = deSerialize(A);
   root->right = deSerialize(A);
   return root;
}
