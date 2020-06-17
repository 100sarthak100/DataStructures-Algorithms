/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// space - O(n) in stack
// time - O(n)

// input -
//      4
//    /   \
//   2     7
//  / \   / \
// 1   3 6   9

// Output -
//      4
//    /   \
//   7     2
//  / \   / \
// 9   6 3   1

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL)
            return NULL;
        if(root->left && root->right)
        {
            TreeNode* temp = root->left;
            root->left = root->right;
            root->right = temp;
            invertTree(root->left);
            invertTree(root->right);
        }
        else if(root->left)
        {
            root->right = root->left;
            root->left = NULL;
            invertTree(root->right);
        }
        else if(root->right)
        {
            root->left = root->right;
            root->right = NULL;
            invertTree(root->left);
        }
        
        return root;
    }
};