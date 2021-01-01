/*Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

Example:

Input: [1,2,3,null,5,null,4]
Output: [1, 3, 4]
Explanation:

   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---

Time - O(N)
Space - O(1)

*/

class Solution {
public:
    
    void BFS(TreeNode* root, vector<int>& res)
    {
		
        queue<pair<TreeNode*, int>> q;
        q.push(make_pair(root, 0));
        
        while(!q.empty())
        {
            auto element = q.front();
            TreeNode* v = element.first;
            int level = element.second;
            q.pop();
            
            //push in res
            if(res.size() < level+1)
                res.push_back(v->val);
            else
                res[level] = v->val;
            
            if(v->left != NULL) q.push(make_pair(v->left, level+1));
            if(v->right != NULL) q.push(make_pair(v->right, level+1));
        }
    }
    vector<int> rightSideView(TreeNode* root) {
        
        vector<int> res;
        if(root == NULL) return res;
        BFS(root, res);
        return res;
    }
};