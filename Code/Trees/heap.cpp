#include <bits/stdc++.h>
using namespace std;

struct minHeap
{
private:
    vector<int> A;
    int parent(int i) { return (i - 1) / 2; }
    int LEFT(int i) { return (2 * i + 1); }
    int RIGHT(int i) { return (2 * i + 2); }

    void heapify_down(int i)
    {
        int left = LEFT(i);
        int right = RIGHT(i);
        int smallest = i;

        if (left < size() && A[left] < A[i])
            smallest = left;
        if (right < size() && A[right] < A[smallest])
            smallest = right;
        if (smallest != i)
        {
            swap(A[i], A[smallest]);
            heapify_down(smallest);
        }
    }

    void heapify_up(int i)
    {
        if (i && A[parent(i)] > A[i])
        {
            swap(A[i], A[parent(i)]);
            heapify_up(parent(i));
        }
    }

public:
    // returns size of the heap
    unsigned int size() { return A.size(); }

    bool empty()
    {
        if (size() == 0)
            return true;
        else
            return false;
    }

    void push(int key)
    {
        A.push_back(key);
        int index = size() - 1;
        heapify_up(index);
    }

    void pop()
    {
        if (size() == 0)
            cout << "index out of range";
        else
        {
            A[0] = A.back();
            A.pop_back();
            heapify_down(0);
        }
    }

    int top()
    {
        if (size() == 0)
        {
            cout << "index out of range";
            return 99999;
        }
        else
            return A[0];
    }
};

int main()
{
    minHeap m;

    m.push(3);
    m.push(2);
    m.push(15);
    cout << "size is : " << m.size() << endl;
    cout << "top is : " << m.top();
}