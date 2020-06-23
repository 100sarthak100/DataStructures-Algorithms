// An array is called good if the parity of each index matches the parity of the 
// element at that index. More formally, an array is good if for all i (0≤i≤n−1) the
//  equality imod2=a[i]mod2 holds, 
// where xmod2 is the remainder of dividing x by 2.

// For example, the arrays [0,5,2,1] and [0,17,0,3] are good, and the array [2,4,6,7] 
// is bad, because for i=1, the parities of i and a[i] are different: imod2=1mod2=1, 
// but a[i]mod2=4mod2=0.

// input -
// 4
// 4
// 3 2 7 6
// 3
// 3 2 6
// 1
// 7
// 7
// 4 9 2 1 18 3 0

// output -
// 2
// 1
// -1
// 0

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;cin>>t;
    while(t--)
    {
        int n,a;cin>>n;
        int e = 0, o = 0; 
        for(int i = 0; i<n; i++)
        {
            cin>>a;
            if(a % 2 != i % 2)
            {
                if(i % 2 == 0)
                    o++;
                else e++;
            }
        }
        if(o != e)
            cout<<-1<<endl;
        else cout<<o<<endl;
    }
}