// Given a Binary Search Tree and a target number, return true if 
// there exist two elements in the BST such that their 
// sum is equal to the given target.

// Example 1:

// Input: 
//     5
//    / \
//   3   6
//  / \   \
// 2   4   7

// Target = 9

// Output: True
 

// Example 2:

// Input: 
//     5
//    / \
//   3   6
//  / \   \
// 2   4   7

// Target = 28

// Output: False

// Time Complexity is O(n).

class Solution {
public:
    bool target(TreeNode* root, int k, unordered_set<int> &st)
    {
        if(root == NULL)
            return false;
        
        if(target(root->left, k, st))
            return true;
        
        if(st.find(k - root->val) != st.end())
            return true;
        else
            st.insert(root->val);
        
        return target(root->right, k, st);
        
    }
    
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> st;
        return target(root, k, st);
    }
};