Given a reference of a node in a connected undirected graph.

Return a deep copy (clone) of the graph.

Input: adjList = [[2],[1]]
Output: [[2],[1]]

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

// bfs
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == NULL)
            return NULL;
        
        unordered_map<Node*, Node*> m;
        Node* tempN = new Node(node->val);
        m[node] = tempN;
        queue<Node*> q;
        q.push(node);
    
        while(!q.empty())
        {
            Node* tempT = q.front();
            q.pop();
            tempN = m[tempT];
            
            for(int i=0; i< tempT->neighbors.size(); i++)
            {
                Node* n = tempT->neighbors[i];
                if(m.count(n))
                    tempN->neighbors.push_back(m[n]);
                else
                {
                    Node* newN = new Node(n->val);
                    tempN->neighbors.push_back(newN);
                    m[n] = newN;
                    q.push(n);
                }
            }
        }
        return m[node];
    }
};

// DFS
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) {return node;}
        if (visited.count(node)) {return visited[node];}
        Node* node_cp = new Node(node->val);
        visited[node] = node_cp;
        for (int i = 0; i < node->neighbors.size(); ++i) {
            node_cp->neighbors.push_back(cloneGraph(node->neighbors[i]));
        }
        return node_cp;   
    }
private:
    unordered_map<Node*, Node*> visited;
};