// Let us consider the below traversals:

// Inorder sequence: D B E A F C
// Preorder sequence: A B D E C F

// In a Preorder sequence, leftmost element is the root of the tree. 
// So we know ‘A’ is root for given sequences. By searching ‘A’ in 
// Inorder sequence, we can find out all elements on left side of ‘A’ 
// are in left subtree and elements on right are in right subtree. 
// So we know below structure now.

//                  A
//                /   \
//              /       \
//            D B E     F C

//          A
//        /   \
//      /       \
//     B         C
//    / \        /
//  /     \    /
// D       E  F

// output -
// Inorder traversal of the constructed tree is 
// D B E A F C

// Time Complexity: O(n^2). 
// Worst case occurs when tree is left skewed. 
// #include <bits/stdc++.h>
// using namespace std;

// struct Node
// {
//     char data;
//     Node* left;
//     Node* right;
// };

// Node* makeNode(char data)
// {
//     Node* newNode = new Node;
//     newNode->data = data;
//     newNode->left = NULL;
//     newNode->right = NULL;
//     return newNode;
// }

// int search(char in[], int start, int end, char data)
// {
//     int i;
//     for(i=start; i<=end; i++)
//     {
//         if(in[i] == data)
//             return i;
//     }
//     return i;
// }

// Node* buildTree(char in[], char pre[], int start, int end)
// {
//     if(start > end)
//         return NULL;
    
//     static int preIndex = 0;

//     Node* tNode = makeNode(pre[preIndex]);
//     preIndex++;

//     if(start == end)
//         return tNode;

//     int inIndex = search(in, start, end, tNode->data);

//     tNode->left = buildTree(in, pre, start, inIndex-1);
//     tNode->right = buildTree(in, pre, inIndex+1, end);
//     return tNode;
// }

// void inorder(Node* root)
// {
//     if(root == NULL)
//         return;
//     inorder(root->left);
//     cout<<root->data<<" ";
//     inorder(root->right);
// }

// int main()
// {
//     char in[] = { 'D', 'B', 'E', 'A', 'F', 'C' };  
//     char pre[] = { 'A', 'B', 'D', 'E', 'C', 'F' };  
//     int siz = sizeof(in)/sizeof(in[0]);
//     Node* root = buildTree(in, pre, 0, siz - 1);

//     cout<<"Inorder Traversal "<<endl;
//     inorder(root);
//     return 0;
// }

// Time Complexity : O(n)
// best solution
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    char data;
    Node* left;
    Node* right;
};

Node* makeNode(char data)
{
    Node* newNode = new Node;
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* buildTree(char in[], char pre[], int start, int end, unordered_map<char, int> &mp)
{
    if(start > end)
        return NULL;
    
    static int preIndex = 0;

    char curr = pre[preIndex];
    Node* tNode = makeNode(curr);
    preIndex++;

    if(start == end)
        return tNode;

    int inIndex = mp[curr];

    tNode->left = buildTree(in, pre, start, inIndex-1, mp);
    tNode->right = buildTree(in, pre, inIndex+1, end, mp);
    return tNode;
}

void inorder(Node* root)
{
    if(root == NULL)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

Node* buildTreeWrap(char in[], char pre[], int len)
{
    unordered_map<char, int> mp;
    for(int i=0; i<len; i++)
        mp[in[i]] = i;

    return buildTree(in, pre, 0, len-1, mp);
}

int main()
{
    char in[] = { 'D', 'B', 'E', 'A', 'F', 'C' };  
    char pre[] = { 'A', 'B', 'D', 'E', 'C', 'F' };  
    int siz = sizeof(in)/sizeof(in[0]);
    Node* root = buildTreeWrap(in, pre, siz);

    cout<<"Inorder Traversal "<<endl;
    inorder(root);
    return 0;
}