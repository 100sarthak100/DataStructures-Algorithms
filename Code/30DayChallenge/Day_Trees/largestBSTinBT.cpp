// Given a Binary Tree, write a function that returns the size 
// of the largest subtree which is also a Binary Search Tree (BST). 
// If the complete Binary Tree is BST, 
// then return the size of the whole tree.

// Examples:

// Input: 
//       5
//     /  \
//    2    4
//  /  \
// 1    3

// Output: 3 
// The following subtree is the 
// maximum size BST subtree 
//    2  
//  /  \
// 1    3


// Input: 
//        50
//      /    \
//   30       60
//  /  \     /  \ 
// 5   20   45    70
//               /  \
//             65    80
// Output: 5
// The following subtree is the
// maximum size BST subtree 
//       60
//      /  \ 
//    45    70
//         /  \
//       65    80

// Time Complexity : O(n)

// struct info
// {
//     int sz;
//     int max;
//     int min;
//     int ans;
//     bool isBST;
// };

info largest(Node* root)
{
    if(root == NULL)
        return {0, INT_MIN, INT_MAX, 0, true};
    
    if(!root->left && !root->right)
        return {1, root->data, root->data, 1, true};
    
    // postorder traversal
    info l = largest(root->left);
    info r = largest(root->right);
    
    info ret;
    ret.sz = 1 + l.sz + r.sz;
    
    if(l.isBST && r.isBST && l.max < root->data && r.min > root->data)
    {
        ret.min = min(l.min, min(root->data, r.min));
        ret.max = max(l.max, max(root->data, r.max));
        ret.ans = ret.sz;
        ret.isBST = true;
        return ret;
    }
    
    ret.ans = max(l.ans, r.ans);
    ret.isBST = false;
    
    return ret;
}

int largestBst(Node *root)
{
	return largest(root).ans;
}