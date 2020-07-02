// Input:

// 2
// 3 4 5 -10 4
// -15 5 6 -8 1 3 9 2 -3 N N N N N 0 N N N N 4 -1 N N 10 N

// Output:

// 16
// 27

// Explanation:
// Testcase 2: The maximum possible sum from one leaf node to another is (3 + 6 + 9 + 0 + -1 + 10 = 27)

// time - O(n)

int maxPathSumUtil(Node *root, int &res)
{
    if (root == NULL)
        return 0;
    if (!root->left && !root->right)
        return root->data;

    int ls = maxPathSumUtil(root->left, res);
    int rs = maxPathSumUtil(root->right, res);

    if (root->left && root->right)
    {
        res = max(res, ls + rs + root->data);

        return max(ls, rs) + root->data;
    }

    return (!root->left) ? rs + root->data : ls + root->data;
}

int maxPathSum(Node *root)
{
    int res = INT_MIN;
    maxPathSumUtil(root, res);
    return res;
}
// maximum path sum btw any node and any node
// commom syntax
// dp on trees
// time - O(N)
// best
class Solution
{
public:
    int solve(TreeNode *root, int &res)
    {
        if (root == NULL)
            return 0;

        int l = solve(root->left, res);
        int r = solve(root->right, res);

        int temp = max(root->val + max(l, r), root->val);
        int ans = max(temp, root->val + l + r);
        res = max(res, ans);

        return temp;
    }

    int maxPathSum(TreeNode *root)
    {
        int res = INT_MIN;
        solve(root, res);
        return res;
    }
};

// maximum path sum btw 2 leaf nodes
// little different from the main syntax
// time - O(N)
// best soln
int solve(Node *root, int &res)
{
    if (root == NULL)
        return 0;

    if (!root->right && !root->left)
        return root->data;
    if (root->left && !root->right)
        return solve(root->left, res) + root->data;
    if (root->right && !root->left)
        return solve(root->right, res) + root->data;

    int l = solve(root->left, res);
    int r = solve(root->right, res);

    int temp = root->data + max(l, r);

    int ans = root->data + l + r;
    res = max(res, ans);

    return temp;
}

int maxPathSum(Node *root)
{
    int res = INT_MIN;
    solve(root, res);
    return res;
}