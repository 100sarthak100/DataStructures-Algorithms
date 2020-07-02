
// banker's algo (deadlock avoidance)
// determine the total number of safe sequences and print all safe sequences.
#include <iostream>
#include <string.h>
#include <vector>

#define P 4
#define R 3

int total = 0;

using namespace std;

bool is_avilable(int process_id, int allocated[][R], int maxx[][R], int need[][R], int available[])
{
    bool flag = true;

    for(int i=0; i<R; i++)
    {
        if(need[process_id][i] > available[i])
            flag = false;
    }
    return flag;
}

void safe_sequence(bool marked[], int allocated[][R], int maxx[][R], int need[][R], int available[], vector<int> safe)
{
    for(int i=0; i<P; i++)
    {
        if(!marked[i] && is_avilable(i, allocated, maxx, need, available))
        {
            marked[i] = true;
            
            for(int j=0; j<R; j++)
                available[j] += allocated[i][j];

            safe.push_back(i);
            safe_sequence(marked, allocated, maxx, need, available, safe);
            safe.pop_back();
            marked[i] = false;

            for(int j=0; j<R; j++)
                available[j] -= allocated[i][j];
        }
    }
    if(safe.size() == P)
    {
        total++;
        for(int i=0; i<P; i++)
        {
            cout<<"P"<<safe[i] + 1;
            if(i != (P - 1))
                cout<<" --> ";
        }
        cout<<endl;
    }

}

int main()
{
    // allocated matrix of size P*R 
    int allocated[P][R] = { {0, 1, 0},
                            {2, 0, 0},
                            {3, 0, 2},
                            {2, 1, 1}};

    // max matrix of size P*R 
    int maxx[P][R] = { { 7, 5, 3 }, 
                      { 3, 2, 2 }, 
                      { 9, 0, 2 }, 
                      { 2, 2, 2 } };

    // Initial total resources 
    int resources[R] = { 10, 5, 7 }; 

    // available vector of size R 
    int available[R]; 

    for(int i=0; i<R; i++)
    {
        int sum = 0;
        for(int j=0; j<P; j++)
            sum += allocated[j][i];
        available[i] = resources[i] - sum;
    }

    vector<int> safe;

    bool marked[P];
    memset(marked, false, sizeof(marked));

    int need[P][R];
    for(int i=0; i<P; i++)
        for(int j=0; j<R; j++)
            need[i][j] = maxx[i][j] - allocated[i][j];

    safe_sequence(marked, allocated, maxx, need, available, safe);
    cout<<total<< " safe sequence"<<endl;
}