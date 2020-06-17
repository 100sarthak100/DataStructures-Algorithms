// Design a data structure that supports the following operations 
// in Θ(1) time.

// insert(x): Inserts an item x to the data structure if not 
// already present.

// remove(x): Removes an item x from the data structure if present.

// search(x): Searches an item x in the data structure.

// getRandom(): Returns a random element from current set of 
// elements

#include <bits/stdc++.h>
using namespace std;

// gfg
// class myStructure
// {
//     vector<int> arr;
//     map<int, int> mp;

//     public:

//     void add(int x)
//     {
//         if(mp.find(x) != mp.end())
//             return;
        
//         int index = arr.size();
//         arr.push_back(x);
//         mp.insert(make_pair(x, index));
//         return;
//     }

//     void remove(int x)
//     {
//         if(mp.find(x) == mp.end())
//             return;
        
//         int index = mp[x];
//         mp.erase(x);
//         arr[index] = arr[arr.size() - 1];
//         arr.pop_back();
//         mp[arr[index]] = index;
//         return;
//     }

//     int search(int x)
//     {
//         if(mp.find(x) != mp.end())
//             return mp[x];
//         return -1;
//     }

//     int getRandom()
//     {
//         srand (time(NULL));
//         int random_index = rand() % arr.size();
//         return arr[random_index];
//     }
// };

// int main()
// {
//     myStructure ds;
//     ds.add(10); 
//     ds.add(20); 
//     ds.add(30); 
//     ds.add(40); 
//     cout << ds.search(30) << endl; 
//     ds.remove(20); 
//     ds.add(50); 
//     cout << ds.search(50) << endl; 
//     cout << ds.getRandom() << endl; 
// }

// leetcode
class RandomizedSet {
    //unordered_set<int> _elems;
    vector<int> _nums;
    unordered_map<int, int> _positions;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(_positions.find(val) != _positions.end())
            return false;
        _nums.push_back(val);
        _positions.insert({val, _nums.size()-1});
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(_positions.find(val) == _positions.end())
            return false;
        int pos = _positions[val];
        _nums[pos] = _nums[_nums.size()-1];
        _positions[_nums[pos]] = pos;
        _nums.pop_back();
        _positions.erase(val);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return _nums[rand() % _nums.size()];
    }
};

