// Input:
// 3
// 1 2 N N 3
// 10 20 30 40 60 N N
// 4 6 6
// Output:
// 0
// 1
// 1
// Explanation:
// Testcase1: The tree is
//         1
//      /    
//    2
//       \
//        3 
// The max difference in height of left subtree and right subtree is 2, which is greater than 1. Hence unbalanced.
// Testcase2: The tree is
//                            10
//                         /        \
//                      20         30
//                   /       \
//                40       60
// The max difference in height of left subtree and right subtree is 1. Hence balanced.
// Testcase 3: The tree is 
//                             10
//                         /        \
//                       6          6
// The maximum difference in height of left subtree and right subtree is 0. Hence balanced.

// Time Complexity: O(n)

bool isBalancedUtil(Node* root, int* height)
{
    int lh = 0, rh = 0;
    int l = 0, r = 0;
    
    if(root == NULL)
    {
        *height = 0;
        return 1;
    }
    
    l = isBalancedUtil(root->left, &lh);
    r = isBalancedUtil(root->right, &rh);
    
    *height = (lh > rh)? lh + 1 : rh + 1;
    
    if(abs(lh - rh) >= 2)
        return 0;
    else
        return l & r;
}

bool isBalanced(Node *root)
{
    int height = 0;
    int b = isBalancedUtil(root, &height);
    if(b == 1)
        return true;
    else return false;
}
