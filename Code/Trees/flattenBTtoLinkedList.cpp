// Flatten a binary tree into linked list

// Given a binary tree, flatten it into linked list in-place. 
// Usage of auxiliary data structure is not allowed. 

// After flattening, left of each node should point to NULL and 
// right should contain next node in level order.

// Input : 
//           1
//         /   \
//        2     5
//       / \     \
//      3   4     6

// Output :
//     1
//      \
//       2
//        \
//         3
//          \
//           4
//            \
//             5
//              \
//               6

// Input :
//         1
//        / \
//       3   4
//          /
//         2
//          \
//           5
// Output :
//      1
//       \
//        3
//         \
//          4
//           \
//            2
//             \ 
//              5


class Solution {
public:
    void flatten(TreeNode* root) {
        
        if(root == NULL || (!root->left && !root->right))
            return;
        
        if(root->left != NULL)
        {
            flatten(root->left);
            
            TreeNode* temp = root->right;
            root->right = root->left;
            root->left = NULL;
            
            TreeNode* t = root->right;
            while(t->right != NULL)
                t = t->right;
            t->right = temp;
        }
        flatten(root->right);
    }
};