// Given a binary tree, return the bottom-up level order traversal 
// of its nodes' values. (ie, from left to right, 
// level by level from leaf to root).

// For example:
// Given binary tree [3,9,20,null,null,15,7],
//     3
//    / \
//   9  20
//     /  \
//    15   7
// return its bottom-up level order traversal as:
// [
//   [15,7],
//   [9,20],
//   [3]
// ]

// my solution
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        queue<TreeNode*> q;
        queue<TreeNode*> qt;
        q.push(root);
        stack<vector<int>> st;
        vector<vector<int>> ret;
        vector<int> vec;
        if(root == NULL)
            return ret;
        
        while(!q.empty())
        {
            TreeNode* temp = q.front();
            q.pop();
            
            vec.push_back(temp->val);
            
            if(temp->left)
                qt.push(temp->left);
            if(temp->right)
                qt.push(temp->right);
            
            if(q.empty())
            {
                st.push(vec);
                vec.clear();
                swap(qt, q);
            }
        }
        int si = st.size();
        for(int i=0; i<si; i++)
        {
            ret.push_back(st.top());
            st.pop();
        }
        return ret;
    }
};

// faster than above, without using stacks
// but using inbuilt reverse function
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        queue<TreeNode*> q;
        queue<TreeNode*> qt;
        q.push(root);
        
        
        vector<vector<int>> ret;
        vector<int> vec;
        if(root == NULL)
            return ret;
        
        while(!q.empty())
        {
            TreeNode* temp = q.front();
            q.pop();
            
            vec.push_back(temp->val);
            
            if(temp->left)
                qt.push(temp->left);
            if(temp->right)
                qt.push(temp->right);
            
            if(q.empty())
            {
                ret.push_back(vec);
                vec.clear();
                swap(qt, q);
            }
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};