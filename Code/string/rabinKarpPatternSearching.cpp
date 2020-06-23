// Given a text txt[0..n-1] and a pattern pat[0..m-1], write a 
// function search(char pat[], char txt[]) that prints all 
// occurrences of pat[] in txt[]. 
// You may assume that n > m.

// Pattern found at index 0
// Pattern found at index 10

// The average and best case running time of the Rabin-Karp 
// algorithm is O(n+m), 
// but its worst-case time is O(nm).

//RKA
#include <bits/stdc++.h>
using namespace std;

#define d 256

void search(char pat[], char txt[], int q)
{
    int n = strlen(txt);
    int m = strlen(pat);
    int h = 1;
    int i, j;
    for(i=0; i<m-1; i++)
        h = (h*d)%q;

    int p=0, t=0;
    for(i=0; i<m; i++)
    {
        p = (p*d + pat[i])%q;
        t = (t*d + txt[i])%q; 
    }

    for(i=0; i<=n-m; i++)
    {
        if(p == t)
        {
            for(j=0; j<m; j++)
            {
                if(txt[i + j] != pat[j])
                    break;
            }
            if(j == m)
                cout<<"pattern found at index "<<i<<endl;
        }

        if(i < n-m)
        {
            t = (d*(t - txt[i]*h) + txt[i+m])%q;
            if(t < 0)
                t = t + q;
        }
    }
}

int main()  
{  
    char txt[] = "GEEKS FOR GEEKS";  
    char pat[] = "GEEK";  
    int q = 101; // A prime number  
    search(pat, txt, q);  
    return 0;  
}  
 