#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

int height(Node *root, int &ans)
{
    if (root == NULL)
        return 0;
    int left_height = height(root->left, ans);
    int right_height = height(root->right, ans);

    ans = max(ans, 1 + left_height + right_height);

    return 1 + max(left_height, right_height);
}

int diameter(Node *root)
{
    if (root == NULL)
        return 0;
    int ans = INT_MIN;
    int height_of_tree = height(root, ans);
    cout << height_of_tree << endl;
    // ans - diameter of the tree
    return ans;
}

struct Node *newNode(int data)
{
    struct Node *node = new Node;
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

int main()
{
    struct Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    printf("Diameter is %d\n", diameter(root));

    return 0;
}

// simple
// common syntax
// dp on trees
// time - O(N)
int height(Node* root, int &res)
{
    if(root == NULL)
        return 0;
    
    int l = height(root->left, res);
    int r = height(root->right, res);
    
    int temp = max(l, r) + 1;
    int ans = max(temp, 1 + l + r);
    res = max(res, ans);
    return temp;
}


int diameter(Node* node) {
    int ans = INT_MIN;
    int h = height(node, ans);
    return ans;
}