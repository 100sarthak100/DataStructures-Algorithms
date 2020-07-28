// There are a total of numCourses courses you have to take, 
// labeled from 0 to numCourses-1.

// Some courses may have prerequisites, for example to take course 
// 0 you have 
// to first take course 1, which is expressed as a pair: [0,1]

// Given the total number of courses and a list of prerequisite 
// pairs, is it possible for you to finish all courses?

// Example 1:

// Input: numCourses = 2, prerequisites = [[1,0]]
// Output: true
// Explanation: There are a total of 2 courses to take. 
//              To take course 1 you should have finished 
//              course 0. So it is possible.
// Example 2:

// Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
// Output: false
// Explanation: There are a total of 2 courses to take. 
//              To take course 1 you should have finished course 
//              0, and to take course 0 you should
//              also have finished course 1. So it is impossible.

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> mp;
        for(auto pairs : prerequisites)
            mp[pairs[1]].push_back(pairs[0]);
        
        vector<int> inDegree(numCourses);
        for(auto it = mp.begin(); it != mp.end(); it++)
        {
            for(int num : it->second)
                inDegree[num]++;
        }
        
        queue<int> q;
        for(int i=0; i<numCourses; i++)
        {
            if(inDegree[i] == 0)
                q.push(i);
        }
        
        while(!q.empty())
        {
            int c = q.front();
            q.pop();
            numCourses--;
            for(int num : mp[c])
            {
                inDegree[num]--;
                if(inDegree[num] == 0)
                    q.push(num);
            }
        }
        
        return (numCourses == 0);
    }
};

// to print courses (in topological sort)
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> mp;
        for(auto pairs : prerequisites)
            mp[pairs[1]].push_back(pairs[0]);
        
        vector<int> inDegree(numCourses);
        for(auto it = mp.begin(); it != mp.end(); it++)
        {
            for(int num : it->second)
                inDegree[num]++;
        }
        
        queue<int> q;
        for(int i=0; i<numCourses; i++)
        {
            if(inDegree[i] == 0)
                q.push(i);
        }
        
        vector<int> courses;
        while(!q.empty())
        {
            int c = q.front();
            q.pop();
            numCourses--;
            courses.push_back(c);
            for(int num : mp[c])
            {
                inDegree[num]--;
                if(inDegree[num] == 0)
                {
                    q.push(num);
                }
            }
        }
        if(numCourses != 0)
            return {};
        else
            return courses;
    }
};