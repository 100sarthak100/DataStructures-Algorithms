// Input: [[10,20],[30,200],[400,50],[30,20]]
// Output: 110
// Explanation: 
// The first person goes to city A for a cost of 10.
// The second person goes to city A for a cost of 30.
// The third person goes to city B for a cost of 50.
// The fourth person goes to city B for a cost of 20.

// The total minimum cost is 10 + 30 + 50 + 20 = 110 to have half the people interviewing in each city.
 
// method 1
class Solution {  
public:
    static bool comp(const vector<int> &a, const vector<int> &b) {
        return (a[0]-a[1] < b[0]-b[1]);
    }
    int twoCitySchedCost(vector<vector<int>>& cost) {
        
        sort(cost.begin(), cost.end(), comp);
        int n = cost.size()/2;
        
        int totalCost = 0;
        for (int i = 0; i < n; i++) 
            totalCost += cost[i][0];
        for (int i = n; i < 2*n; i++) 
            totalCost += cost[i][1];
        
        return totalCost;
    }
};

// method 2 (using sets)
class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        set<pair<int, int>> diff;
        int index = 0;
        for(auto i : costs)
        {
            int d = i[0] - i[1];
            diff.insert(make_pair(d, index));
            index++;
        }
        int n = costs.size();
        int count = 1;
        int sum = 0;
        for(auto i : diff)
        {
            if(count <= n/2)
            {
                sum += costs[i.second][0];
                //cout<<costs[i.second][0]<<" "<<costs[i.second][1]<<endl;
                count++;
            }
            else
            {
                sum += costs[i.second][1];
                //cout<<i.second<<endl;
                count++;
            } 
        }
        return sum;
    }
};