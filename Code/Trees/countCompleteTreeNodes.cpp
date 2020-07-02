// Given a complete binary tree, count the number of nodes.

// Input: 
//     1
//    / \
//   2   3
//  / \  /
// 4  5 6

// Output: 6

// method 1 : using simple pre order recursive tree traversal.
// time O(N)
class Solution {
public:
    void countNodes(TreeNode* root, int &count)
    {
        if(root == NULL)
            return;
        count++;
        countNodes(root->left, count);
        countNodes(root->right, count);
    }
    
    
    int countNodes(TreeNode* root) {
        int count = 0;
        countNodes(root, count);
        return count;
    }
};

// Number of nodes in a full binary tree if we know the height 
// h is, N = 2^h- 1.
// Compare left height and right height, if equal, use the 
// formula (2^h- 1) otherwise recurvisely search left and right 
// at next level.
// O(log n * log n)

class Solution {
public:
   int leftheight(TreeNode* root)
   {
       if(root == NULL)
           return 0;
       return 1 + leftheight(root->left);
   }
    
   int rightheight(TreeNode* root)
   {
       if(root == NULL)
           return 0;
       return 1 + rightheight(root->right);
   }
    
    int countNodes(TreeNode* root) {
        int leftHeight = leftheight(root);
        int rightHeight = rightheight(root);
        
        // (1 << leftHeight) - 1 == 2^h - 1
        return (leftHeight == rightHeight) ? (1 << leftHeight) - 1 : 
                                            1 + countNodes(root->left) + countNodes(root->right);
    }
};