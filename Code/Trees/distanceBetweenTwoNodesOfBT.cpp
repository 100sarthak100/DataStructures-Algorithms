// #include <bits/stdc++.h>
// using namespace std;

// int findLevel(Node* root, int k, int level)
// {
//     if(root == NULL)
//         return -1;
//     if(root->key == k)
//         return level;
    
//     int l = findLevel(root->left, k, level+1);
//     return (l != -1)? l : findLevel(root->right, k, level+1);
// }

// Node* findDistanceUtil(Node* root, int n1, int n2, int &d1, int &d2, int &dist, int lvl)
// {
//     if(root == NULL) return NULL;
//     if(root->key == n1)
//     {
//         d1 = lvl;
//         return root;
//     }
//     if(root->key == n2)
//     {
//         d2 = lvl;
//         return root;
//     }

//     Node* left_lca = findDistUtil(root->left, n1, n2, d1, d2, dist, lvl+1);
//     Node* right_lca = findDistUtil(root->right, n1, n2, d1, d2, dist, lvl+1);

//     if(left_lca && right_lca)
//     {
//         dist = d1 + d2 - 2*lvl;
//         return root;
//     }

//     return (left_lca != NULL)? left_lca : right_lca;
// }

// int findDistance(Node* root, int n1, int n2)
// {
//     int d1 = -1, d2 = -1, dist;
//     Node* lca = findDistanceUtil(root, n1, n2, d1, d2, dist, 1);

//     if(d1 != -1 && d2 != -1)
//         return dist;

//     if(d1 != -1)
//     {
//         dist = findLevel(lca, n2, 0);
//         return dist;
//     }

//     if(d2 != -1)
//     {
//         dist = findLevel(lca, n1, 0);
//         return dist;
//     }
//     return -1;
// }

Node* LCA(Node* root, int n1, int n2)
{
    if(root == NULL) return root;
    if(root->key == n1 || root->key == n2)
        return root;
    
    Node* left = LCA(root->left, n1, n2);
    Node* right = LCA(root->right, n1, n2);
    
    if(left != NULL && right != NULL)
        return root;
    
    if(left != NULL)
        return LCA(root->left, n1, n2);
    
    return LCA(root->right, n1, n2);
}

int findLevel(Node* root, int k, int level)
{
    if(root == NULL)
        return -1;
    if(root->key == k)
        return level;
    
    int l = findLevel(root->left, k, level+1);
    return (l != -1)? l : findLevel(root->right, k, level+1);
}

int findDistance(Node* root, int a, int b)
{
    Node* lca = LCA(root, a, b);

    int d1 = findLevel(lca, a, 0);
    int d2 = findLevel(lca, b, 0);

    return d1 + d2;
}
