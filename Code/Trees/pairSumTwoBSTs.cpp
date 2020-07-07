// Given two Binary Search Trees (BST) and a given sum. 
// The task is to find pairs with given sum such that each pair 
// elements must lie in different BST.

// Input : sum = 10
//      8                    5
//    /   \                /   \
//   3     10             2    18
//  /  \      \         /   \  
// 1    6      14      1     3
//     / \     /              \  
//    5   7   13              4          
// Output : (5,5), (6,4), (7,3), (8,2)
// In above pairs first element lies in first
// BST and second element lies in second BST

// Time complexity : O(n)
// Auxiliary space : O(n)

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* makeNode(int data)
{
    Node* newNode = new Node;
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int data)
{
    if(root == NULL)
        return makeNode(data);
    
    if(root->data > data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);
    return root;
}

void store(Node* root, vector<int> & ret)
{
    if(root == NULL)
        return;
    
    store(root->left, ret);
    ret.push_back(root->data);
    store(root->right, ret);
}

void findPair(vector<int> rt1, vector<int> rt2, int sum, vector<vector<int>> &ret)
{
    int start = 0, end = rt2.size()-1;

    while(start < rt1.size() && end>=0)
    {
        if(rt1[start] + rt2[end] == sum)
        {
            ret.push_back({rt1[start], rt2[end]});
            start++;
            end--;
        }
        else if(rt1[start] + rt2[end] < sum)
            start++;
        else
            end--;
    }
    return;
}

vector<vector<int>> pairSum(Node* root1, Node* root2, int sum)
{
    vector<int> rt1, rt2;
    store(root1, rt1);
    store(root2, rt2);

    vector<vector<int>> ret;
    findPair(rt1, rt2, sum, ret);
    return ret;
}

int main()
{
    Node* root1 = NULL; 
    root1 = insert(root1, 8); 
    root1 = insert(root1, 10); 
    root1 = insert(root1, 3); 
    root1 = insert(root1, 6); 
    root1 = insert(root1, 1); 
    root1 = insert(root1, 5); 
    root1 = insert(root1, 7); 
    root1 = insert(root1, 14); 
    root1 = insert(root1, 13); 
  
    // second BST 
    Node* root2 = NULL; 
    root2 = insert(root2, 5); 
    root2 = insert(root2, 18); 
    root2 = insert(root2, 2); 
    root2 = insert(root2, 1); 
    root2 = insert(root2, 3); 
    root2 = insert(root2, 4); 
  
    int sum = 10; 
    vector<vector<int>> ret = pairSum(root1, root2, sum); 
    for(auto vec : ret)
        cout<<"("<<vec[0]<<" ,"<<vec[1]<<")"<<endl;
  
    return 0; 
}