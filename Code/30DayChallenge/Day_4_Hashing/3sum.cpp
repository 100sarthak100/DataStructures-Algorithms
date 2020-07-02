// Time complexity: O(N^2).
// There are only two nested loops traversing the array, 
// so time complexity is O(n^2).
// Space Complexity: O(1).

// with hashing and extra space for hash table
#include<bits/stdc++.h>
using namespace std;

int Threesum(int arr[], int n, int s)
{
    for(int i=0; i<n-2; i++)
    {
        unordered_set<int> st;
        int cur_sum = s - arr[i];
        for(int j=i+1; j<n; j++)
        {
            int k = cur_sum - arr[j];
            if(st.find(k) != st.end())
            {
                return 1;
            }
            else
                st.insert(arr[j]);
        }
    }
    return 0;
}

int main()
 {
	int t;cin>>t;
	while(t--)
	{
	    int n, s;
	    cin>>n>>s;
	    int arr[n];
	    for(int i=0; i<n; i++)
	        cin>>arr[i];
	   cout<<Threesum(arr, n, s)<<endl;
	}
	return 0;
}

// without extra space
// two pointer method
#include<bits/stdc++.h>
using namespace std;

int Threesum(int arr[], int n, int s)
{
    sort(arr, arr+n);
    for(int i=0; i<n-2; i++)
    {
        int left = i+1;
        int right = n-1;
        while(left < right)
        {
            int curSum = arr[i] + arr[left] + arr[right];
            if(s == curSum)
            {
                //cout<<arr[i]<<" "<<arr[left]<<" "<<arr[right];
                return 1;
            }
            else if(curSum < s)
                left++;
            else
                right--;
        }
        
    }
    return 0;
}

int main()
 {
	int t;cin>>t;
	while(t--)
	{
	    int n, s;
	    cin>>n>>s;
	    int arr[n];
	    for(int i=0; i<n; i++)
	        cin>>arr[i];
	   cout<<Threesum(arr, n, s)<<endl;
	}
	return 0;
}

// 3 sum (sum == 0) triplets print all
// can print any sum == k triplets
// two pointers
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ret;
        vector<int> vec;
        if(n == 0)
            return ret;
        
        sort(nums.begin(), nums.end());
        
        for(int i=0; i<n-2; i++)
        {
            if(i == 0 || (i > 0 && nums[i] != nums[i-1]))
            {
                int low = i+1;
                int high = n-1;
            
                 while(low < high)
                {
                     int sum = nums[i] + nums[low] + nums[high];
                     // sum == k
                     if(sum == 0)
                     {
                         vec = {nums[i], nums[low], nums[high]};
                         ret.push_back(vec);
                         vec.clear();
                         while(low < high && nums[low] == nums[low+1])
                             low++;
                         while(low < high && nums[high] == nums[high-1])
                             high--;
                         low++;
                         high--;
                     }
                     else if(sum < 0)
                         low++;
                     else
                         high--;
                }
            }  
        }
        return ret;
    }
};