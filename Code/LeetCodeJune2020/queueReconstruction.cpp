// Input:
// [[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]

// Output:
// [[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]

// Suppose you have a random list of people standing in a queue. 
// Each person is described by a pair of integers (h, k), where h 
// is the height of the person and k is the number of people in 
// front of this person who have a height greater than or 
// equal to h. Write an algorithm to reconstruct the queue.

bool cmp(vector<int> a, vector<int> b)
{
        if(a[0] == b[0]) return a[1] > b[1];
        return a[0] < b[0];
}
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& p) {
      sort(p.begin(), p.end(), cmp);
      vector < vector <int> > ans;
      for(auto i : p)
      {
          cout<<"["<<i[0]<<","<<i[1]<<"]"<<" ";
      }
      for(int i = p.size()-1; i>=0; i--){
         ans.insert(ans.begin() + p[i][1], p[i]);
         cout<<p[i][1]<<" "<<endl;
      }
      return ans;
    }
};