// Given a non-empty binary tree, return the average value of the 
// nodes on each level 
// in the form of an array.

// Input:
//     3
//    / \
//   9  20
//     /  \
//    15   7
// Output: [3, 14.5, 11]
// Explanation:
// The average value of nodes on level 0 is 3,  on level 1 is 14.5, 
// and on level 2 is 11. Hence return [3, 14.5, 11].

class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        vector<double> ret;
        if(root == NULL)
            return ret;
        
        while(!q.empty())
        {
            int size = q.size();
            double sum = 0;
            double count = size;
            
            while(size--)
            {
                TreeNode* temp = q.front();
                q.pop();
                sum += temp->val;
                
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);         
            }
            if(size <= 0)
            {
                double avg = sum/count;
                ret.push_back(avg);
            }  
        }
        return ret;
    }
};