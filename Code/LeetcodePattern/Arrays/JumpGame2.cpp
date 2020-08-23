
// O(N^2) solution
// prints the minimum jump and the jump index also
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)
            return 0;
        
        vector<long long> dp(n);
        for(int i=0; i<n; i++)
            dp[i] = INT_MAX;
        vector<int> jump(n);
        
        dp[0] = 0;
        jump[0] = 0;
        
        for(int i=1; i<n; i++)
        {
            for(int j=0; j<i; j++)
            {
                if(j + nums[j] >= i)
                {
                    if(dp[i] > dp[j] + 1)
                    {
                        dp[i] = dp[j] + 1;
                        jump[i] = j;
                    }
                }
            }
        }
        if(dp[n-1] == INT_MAX)
            return -1;
        return dp[n-1];
    }
};

// O(N) solution
// only prints the minimum jump 
// stair and ladder concept
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n == 0 || n == 1)
            return 0;
        
        int ladder = nums[0];
        int stairs = nums[0];
        int jump = 1;
        
        for(int i=1; i<n; i++)
        {
            if(i == n-1)
                return jump;
            
            if(i + nums[i] > ladder)
                ladder = i + nums[i];
            
            stairs--;
            if(stairs == 0)
            {
                jump++;
                stairs = ladder - i;
                // not reachable
                if(stairs == 0)
                    return -1;
            }
        }
        return jump;
    }
};