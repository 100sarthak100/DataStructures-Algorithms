#include <bits/stdc++.h>
using namespace std;

const int ALPHABET = 26;

struct TrieNode
{
    TrieNode *children[ALPHABET];
    bool isEndOfWord;
};

TrieNode *getNode()
{
    TrieNode *pNode = new TrieNode;
    pNode->isEndOfWord = false;
    for (int i = 0; i < ALPHABET; ++i)
        pNode->children[i] = NULL;
    return pNode;
}

void insert(TrieNode *root, string key)
{
    TrieNode *pCrawl = root;
    for (int i = 0; i < key.size(); ++i)
    {
        int index = key[i] - 'a';
        if (!pCrawl->children[index])
            pCrawl->children[index] = getNode();
        pCrawl = pCrawl->children[index];
    }
    pCrawl->isEndOfWord = true;
}

bool search(TrieNode *root, string key)
{
    TrieNode *pCrawl = root;
    for (int i = 0; i < key.length(); ++i)
    {
        int index = key[i] - 'a';
        if (!pCrawl->children[index])
            return false;
        pCrawl = pCrawl->children[index];
    }
    return {pCrawl != NULL && pCrawl->isEndOfWord};
}

int main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        TrieNode *root = getNode();
        string keys[n];
        for (int i = 0; i < n; ++i)
        {
            cin >> keys[i];
            insert(root, keys[i]);
        }
        string a;
        cin >> a;
        bool sh = search(root, a);
        if (sh == true)
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }
}