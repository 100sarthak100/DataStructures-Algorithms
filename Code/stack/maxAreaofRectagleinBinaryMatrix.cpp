// Given a rows x cols binary matrix filled with 0's and 1's, find the 
// largest rectangle containing only 1's and return its area.

// Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
// Output: 6
// Explanation: The maximal rectangle is shown in the above picture.

// Example 2:

// Input: matrix = []
// Output: 0

// Example 3:

// Input: matrix = [["0"]]
// Output: 0

// Example 4:

// Input: matrix = [["1"]]
// Output: 1

// Example 5:

// Input: matrix = [["0","0"]]
// Output: 0

// Time - O(N*M)
// Space - O(M)

// Using maximum area of Histogram (MAH = arr[i]*(NSL - NSR - 1)) in this.

// Accepted in Leetcode, but rejected in GFG (TLE)
class Solution
{
public:
    void nearestSmallestLeft(vector<int> &nsl, vector<int> arr, int n)
    {
        stack<pair<int, int>> s;

        for (int i = 0; i < n; ++i)
        {
            if (s.size() == 0)
                nsl.push_back(-1);
            else if (s.size() > 0 && s.top().first < arr[i])
                nsl.push_back(s.top().second);
            else if (s.size() > 0 && s.top().first >= arr[i])
            {
                while (s.size() > 0 && s.top().first >= arr[i])
                    s.pop();

                if (s.size() == 0)
                    nsl.push_back(-1);
                else
                    nsl.push_back(s.top().second);
            }

            s.push({arr[i], i});
        }

        return;
    }

    void nearestSmallestRight(vector<int> &nsr, vector<int> arr, int n)
    {
        stack<pair<int, int>> s;

        for (int i = n - 1; i >= 0; --i)
        {
            if (s.size() == 0)
                nsr.push_back(n);
            else if (s.size() > 0 && s.top().first < arr[i])
                nsr.push_back(s.top().second);
            else if (s.size() > 0 && s.top().first >= arr[i])
            {
                while (s.size() > 0 && s.top().first >= arr[i])
                    s.pop();

                if (s.size() == 0)
                    nsr.push_back(n);
                else
                    nsr.push_back(s.top().second);
            }

            s.push({arr[i], i});
        }

        reverse(nsr.begin(), nsr.end());

        return;
    }

    int mah(vector<int> arr, int n)
    {
        vector<int> nsl, nsr, width, area;
        int maxArea = 0;

        nearestSmallestLeft(nsl, arr, n);
        nearestSmallestRight(nsr, arr, n);

        for (int i = 0; i < n; i++)
            width.push_back(nsr[i] - nsl[i] - 1);

        for (int i = 0; i < n; i++)
            area.push_back(arr[i] * width[i]);

        for (int i = 0; i < n; i++)
            maxArea = max(maxArea, area[i]);

        return maxArea;
    }

    int maximalRectangle(vector<vector<char>> &M)
    {

        if (M.empty())
            return 0;
        vector<int> vec;
        int n = M.size();
        int m = M[0].size();
        for (int i = 0; i < m; i++)
            vec.push_back(M[0][i] - '0');

        int maxArea = mah(vec, m);
        // cout<<maxArea<<endl;

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (M[i][j] == '0')
                    vec[j] = 0;
                else
                    vec[j] += (M[i][j] - '0');
            }
            maxArea = max(maxArea, mah(vec, m));
            // cout<<mah(vec, m)<<" "<<maxArea<<endl;
        }
        return maxArea;
    }
};