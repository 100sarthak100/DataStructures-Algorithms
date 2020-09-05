// Time - O(nlogn)
// Space - O(N)

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    int leftSubTreeSize;
    Node* left;
    Node* right;
};

Node* newNode(int data)
{
    Node* newnode = new Node;
    newnode->data = data;
    newnode->leftSubTreeSize = 0;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

Node* insert(Node* root, int data, int idx, vector<int> &ret, int numSmallerAtInsertTime=0)
{
    if(root == NULL)
    {
        ret[idx] = numSmallerAtInsertTime;
        return newNode(data);
    }
    
    if(root->data > data)
    {   root->leftSubTreeSize += 1;
        root->left = insert(root->left, data, idx, ret, numSmallerAtInsertTime);
    }
    else
    {
        numSmallerAtInsertTime += root->leftSubTreeSize;
        numSmallerAtInsertTime++;
        root->right = insert(root->right, data, idx, ret, numSmallerAtInsertTime);
    }
    
    return root;
}

void rightSmaller(int arr[], int n)
{
    if(n == 0)
        return;
    vector<int> ret(n, 0);
    Node* root = newNode(arr[n-1]);
    for(int i=n-2; i>=0; i--)
        root = insert(root, arr[i], i, ret);

    for(int i=0; i<n; i++)
        cout<<ret[i]<<" ";
    cout<<endl;
}

int main()
{
    int arr[] = {8, 5, 11, -1, 3, 4, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    rightSmaller(arr, n);
}