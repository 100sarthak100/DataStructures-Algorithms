// Given a set of N jobs where each job i has a deadline 
// and profit associated to it. Each job takes 1 unit of time 
// to complete and only one job can be scheduled at a time. 
// We earn the profit if and only if the job is completed by 
// its deadline. The task is to 
// find the maximum profit and the number of jobs done.

// Input:
// 2
// 4
// 1 4 20 2 1 10 3 1 40 4 1 30
// 5
// 1 2 100 2 1 19 3 2 27 4 1 25 5 1 15

// Output:
// 2 60
// 2 127

// Explanation:
// Test Case 1: You can do job 3 followed by the job 1. 
// The overall profit = 40 + 20 = 60
// Test Case 2: You can do job 1 followed by the job 3. 
// The overall profit = 100 + 27 = 127

// time - O(N^2)

#include<bits/stdc++.h>
using namespace std;

struct job
{
    int id;
    int dead;
    int w;
};

bool cmp(job a, job b)
{
    return (a.w > b.w);
}

void maxProfit(job arr[], int n)
{
    sort(arr, arr+n, cmp);
    
    int results[n];
    bool check[n];
    for(int i=0; i<n; i++)
        check[i] = false;
        
    for(int i=0; i<n; i++)
    {
        for(int j= min(n, arr[i].dead)-1; j>=0; j--)
        {
            if(check[j] == false)
            {
                check[j] = true;
                results[j] = i;
                break;
            }
        }
    }
    
    int sum = 0;
    int count = 0;
    for(int i=0; i<n; i++)
    {
        if(check[i])
        {
            sum += arr[results[i]].w;
            count++;
        }
    }
    cout<<count<<" "<<sum<<endl;
}

int main()
 {
	int t;cin>>t;
	while(t--)
	{
	    int n;cin>>n;
	    job arr[n];
	    int a, b, c;
	    for(int i=0; i<n; i++)
	    {
	        cin>>a>>b>>c;
	        arr[i].id = a;
	        arr[i].dead = b;
	        arr[i].w = c;
	    }
	    maxProfit(arr, n);
	}
	return 0;
}