// How to implement LRU caching scheme? What data structures 
// should be used?
// We are given total possible page numbers that can be 
// referred. We are also given cache (or memory) size (Number 
// of page frames that cache can hold at a time). The LRU caching 
// scheme is to remove the least recently used frame when the cache 
// is full and a 
// new page is referenced which is not there in cache.

// queue (doubly linked list) + hash

// refer time - O(1)
// space - O(1)

#include <bits/stdc++.h>
using namespace std;

class LRUcache
{
    list<int> dq; // store keys of cache
    // store reference of keys in cache
    unordered_map<int, list<int>::iterator> mp;
    int maxSize; // max size of cache

    public:
    LRUcache(int);
    void refer(int);
    void display();
};

LRUcache::LRUcache(int n)
{
    maxSize = n;
}

// refer key x within the LRU cache
void LRUcache::refer(int x)
{
    if(mp.find(x) == mp.end())
    {
        if(dq.size() == maxSize)
        {
            int last = dq.back();
            dq.pop_back();
            mp.erase(last);
        }
    }
    else // present in cache
        dq.erase(mp[x]);

    // update reference
    dq.push_front(x);
    mp[x] = dq.begin();
}

// function to display content of LRU cache
void LRUcache::display()
{
    // iterate in dequeue and print all the elements
    for(auto it = dq.begin(); it != dq.end(); it++)
        cout<<*it<<" ";
    cout<<endl;
}

int main()
{
    LRUcache ca(4);
    ca.refer(1); 
    ca.refer(2); 
    ca.refer(3); 
    ca.refer(1); 
    ca.refer(4); 
    ca.refer(5); 
    ca.display();
    return 0;
}