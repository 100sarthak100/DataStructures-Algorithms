int Solution::maxPoints(vector<int> &A, vector<int> &B)
{
    int n = A.size();
    map<pair<double, double>, int> mp;
    if (n < 2)
        return n;
    double x1, x2, y1, y2, m, c;
    int soln = 1;
    for (int i = 0; i < n; ++i)
    {
        x1 = A[i];
        y1 = B[i];
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                continue;
            x2 = A[j];
            y2 = B[j];
            if (x1 == x2)
            {
                m = INT_MAX;
                c = x1;
            }
            else
            {
                m = (y2 - y1) / (x2 - x1);
                c = y1 - m * x1;
            }
            pair<double, double> p;
            p.first = m;
            p.second = c;
            if (mp.find(p) == mp.end())
            {
                mp[p] = 2;
                soln = max(soln, mp[p]);
            }
            else
            {
                mp[p]++;
                soln = max(soln, mp[p]);
            }
        }
        mp.clear();
    }
    return soln;
}