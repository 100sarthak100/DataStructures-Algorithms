#include <bits/stdc++.h>
using namespace std;

// Converts key current character into index 
// use only 'A' through 'Z' 
#define char_int(c) ((int)c - (int)'A')
#define SIZE (26)
#define M 3
#define N 3

struct TrieNode
{
    bool leaf;
    TrieNode* Child[SIZE];
};

TrieNode* getNode()
{
    TrieNode* newNode = new TrieNode;
    newNode->leaf = false;
    for(int i = 0; i< SIZE; i++)
        newNode->Child[i] = NULL;
    return newNode;
}

void insert(TrieNode* root, char *Key)
{
    int n = strlen(Key);
    TrieNode* pChild = root;

    for(int i = 0; i<n; i++)
    {
        int index = char_int(Key[i]);
        if(pChild->Child[index] == NULL)
            pChild->Child[index] = getNode();
        
        pChild = pChild->Child[index];
    }
    pChild->leaf = true;
}

int main()
{
    char *dictionary[] = {"GEEKS", "FOR", "QUIZ", "GEE"};
    TrieNode* root = getNode();
}