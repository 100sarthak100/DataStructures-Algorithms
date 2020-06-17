// Input:
// 2
// 1 3 2
// 10 20 30 40 60 N N
// Output:
// 1 3
// 10 20 40

// Explanation:
// Testcase 1: Below is the given tree with its nodes
//          1                   
//        /     \
//      3        2
// Here left view of the tree will be 1 3.

// Left view of following tree is 1 2 4 8.

//           1
//        /     \
//      2        3
//    /     \    /    \
//   4     5   6    7
//    \
//      8   

// Expected Time Complexity: O(N).
// Expected Auxiliary Space: O(Height of the Tree).

void leftView(Node *root)
{
   if(root == NULL)
        return;
    
    cout<<root->data<<" ";
    while(root != NULL)
    {
        if(!root->left && !root->right)
            break;
        if(root->left)
        {
            root = root->left;
            cout<<root->data<<" ";
        }
        else
        {
            root = root->right;
            cout<<root->data<<" ";
        }
    }
}