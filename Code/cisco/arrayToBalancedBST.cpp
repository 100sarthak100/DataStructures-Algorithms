// Given a sorted array. Write a program that creates a Balanced 
// Binary Search Tree using array elements. If there are N elements 
// in array, then floor(n/2)'th element should be chosen as root and 
// same should be followed recursively.

// Input:
// 1
// 7
// 1 2 3 4 5 6 7

// Output:
// 4 2 1 3 6 5 7

// Time Complexity: O(n)

#include<iostream>
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

Node* arrayToBST(int arr[], int l, int r)
{
    if(l > r)
        return NULL;
    
    int mid = (l + r)/2;
    Node* root = makeNode(arr[mid]);
    
    root->left = arrayToBST(arr, l, mid - 1);
    root->right = arrayToBST(arr, mid+1, r);
    return root;
}

void preorder(Node* root)
{
    if(root == NULL)
        return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

int main()
 {
	int t;cin>>t;
	while(t--)
	{
	    int n;cin>>n;
	    int arr[n];
	    for(int i=0; i<n; i++)
	        cin>>arr[i];
	   Node* root = arrayToBST(arr, 0, n-1);
	   preorder(root);
	   cout<<endl;
	}
	return 0;
}