string arrangeStudents(vector<int> a, vector<int> b) {
    int n = a.size();
    int m = b.size();
    int i = 0, j = 0;
    char prev = 'n';
    
    if(a[0] <= b[0])
    {
        prev = 'b';
        i++;
    }
    else
    {
        prev = 'g';
        j++;
    }
    
    while(i < n && j < m)
    {
        if(a[i] <= b[j] && prev != 'b')
        {
            prev = 'b';
            i++;
        }
        else if(a[i] >= b[j] && prev != 'g')
        {
            prev = 'g';
            j++;
        }
        else
        {
            return "NO";
        }
    }
    if(i == n && j == m-1)
    {
        if(prev != 'g')
            return "YES";
        else return "NO";
    }
    else if(j == m && i == n-1)
    {
        if(prev != 'b')
            return "YES";
        else return "NO";
    }
    else return "NO";
}
