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