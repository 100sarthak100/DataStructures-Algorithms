// Input: [1,8,6,2,5,4,8,3,7]
// Output: 49

class Solution {
public:
    int min(int a, int b)
    {
        return (a < b)? a : b;
    }
    
    
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size() - 1;
        int maxArea = INT_MIN;
        int tempArea;
        while(i < j)
        {
            //cout<<height[i]<<" "<<height[j]<<endl;
            int minH = min(height[i], height[j]);
            
            tempArea =  minH * (j - i);
            maxArea = max(maxArea, tempArea);
            if(height[i] < height[j])
                i++;
            else j--;
            
        }
        return maxArea;
    }
};