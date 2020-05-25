int findMissing(int arr[], int n) { 
    
   set<int> s;
   int m = 1;
   
   for(int i = 0;i<n;i++)
   {
       if(m < arr[i])
            s.insert(arr[i]);
        else if(m == arr[i])
        {
            m = m+1;
            while(s.count(m))
            {
                s.erase(m);
                m++;
            }
        }
   }
   return m;
   
}