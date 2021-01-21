// The stock span problem is a financial problem where we have a series 
// of n daily price quotes for a stock and we need to calculate the span 
// of stock’s price for all n days. 
// The span Si of the stock’s price on a given day i is defined as the 
// maximum number of consecutive days just before the given day, for which the price of the stock on the current day is less than or equal to its price on the given day.
// For example, if an array of 7 days prices is given as 
// {100, 80, 60, 70, 60, 75, 85}, then the span values for corresponding 
// 7 days are {1, 1, 1, 2, 1, 4, 6}.

// Example 1:

// Input: 
// N = 7, price[] = [100 80 60 70 60 75 85]
// Output:
// 1 1 1 2 1 4 6
// Explanation:
// Traversing the given input span for 100 
// will be 1, 80 is smaller than 100 so the 
// span is 1, 60 is smaller than 80 so the 
// span is 1, 70 is greater than 60 so the 
// span is 2 and so on. Hence the output will 
// be 1 1 1 2 1 4 6.

// Example 2:

// Input: 
// N = 6, price[] = [10 4 5 90 120 80]
// Output:
// 1 1 2 4 5 1
// Explanation:
// Traversing the given input span for 10 
// will be 1, 4 is smaller than 10 so the 
// span will be 1, 5 is greater than 4 so 
// the span will be 2 and so on. Hence, the 
// output will be 1 1 2 4 5 1.

// Time - O(N)
// Space - O(N)

// Same as Nearest greater to left, but store indexex instead 
// of values.

vector <int> calculateSpan(int price[], int n)
{
   stack<pair<int, int>> s;
   vector<int> vec;
   
   for(int i=0; i<n; i++)
   {
        if(s.size() == 0)
            vec.push_back(-1);
        else if(s.size() > 0 && s.top().first > price[i])
            vec.push_back(s.top().second);
        else if(s.size() > 0 && s.top().first <= price[i])
        {
            while(s.size() > 0 && s.top().first <= price[i])
                s.pop();
                
            if(s.size() == 0)
                vec.push_back(-1);
            else
                vec.push_back(s.top().second);
        }
        
        s.push({price[i], i});
   }
   
   for(int i=0; i<n; i++)
        vec[i] = i - vec[i];
        
   return vec;
}