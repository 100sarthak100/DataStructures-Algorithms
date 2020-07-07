// Let T be a rooted tree. The lowest common ancestor between two 
// nodes n1 and n2 is defined as the lowest node in T that has both 
// n1 and n2 as descendants 
// (where we allow a node to be a descendant of itself).

// Time complexity of the above solution is O(n)
// worst case O(h)

#include <bits/stdc++.h>
using namespace std;

Node* findLCAUtil(Node* root, int n1, int n2, bool &v1, bool &v2)
{
    if(root == NULL) return NULL;
    if(root->key == n1)
    {
        v1 = true;
        return root;
    }
    if(root->key == n2)
    {
        v2 = true;
        return root;
    }
    Node* left_lca = findLCAUtil(root->left, n1, n2, v1, v2);
    Node* right_lca = findLCAUtil(root->right, n1, n2, v1, v2);

    if(left_lca && right_lca) return root;

    return (left_lca != NULL)? left_lca : right_lca;
}

bool find(Node* root, int k)
{
    if(root == NULL)
        return false;
    if(root->key == k || find(root->left, k) || find(root->right, k))
        return true;
    return false;
}

Node* findLCA(Node* root, int n1, int n2)
{
    bool v1 = false, v2 = false;
    Node* lca = findLCAUtil(root, n1, n2, v1, v2);
    if(v1 && v2 || v1 && find(lca, n2) || v2 && find(lca, n1))
        return lca;
    return NULL;
}

