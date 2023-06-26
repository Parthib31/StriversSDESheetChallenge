#include <bits/stdc++.h> 

void insert(vector<int>& heap, int num)
{
    int ind = heap.size();
    heap.push_back(num);
    while(ind > 0 && heap[(ind-1)/2] > heap[ind])
    {
        swap(heap[(ind-1)/2], heap[ind]);
        ind = (ind-1) / 2;
    }
}

void del(vector<int>& heap)
{
    int size = heap.size();
    int last = heap[size-1];
    swap(heap[0], last);
    heap.pop_back();
    int ind = 0;

    while(ind < heap.size())
    {
        if(heap[ind] > heap[2*ind+1]) 
        {
            swap(heap[0], heap[2*ind+1]);
            ind = 2*ind+1;
        }
        else if(heap[ind] > heap[2*ind+2]) 
        {
            swap(heap[0], heap[2*ind+2]);
            ind = 2*ind+2;
        }
        else break;
    }
}

vector<int> minHeap(int n, vector<vector<int>>& q) {
    // Write your code here.
    vector<int> heap;
    vector<int> ans;

    for(int ind = 0 ; ind < q.size() ; ind++)
    {
        if(q[ind][0] == 0)
        {
            insert(heap, q[ind][1]);
        }
        else
        {
            ans.push_back(heap[0]);
            del(heap);
        }
    }
    return ans;
}
