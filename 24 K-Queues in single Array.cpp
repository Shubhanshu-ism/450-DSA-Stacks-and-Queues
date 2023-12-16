#include <bits/stdc++.h> 
class NQueue{
    int *arr, *front, *rear, *next;
    int freeIndex;
public:
    // Initialize your data structure.
    NQueue(int n, int s)
    {
        arr = new int[s];
        front = new int[n];
        rear = new int[n];
        next = new int[s];
        for(int i=0;i<n;i++) front[i]=rear[i]=-1;
        for(int i=0;i<s;i++) next[i]=i+1;
        next[s-1]=-1;
        freeIndex=0;
    }

    // Enqueues 'X' into the Mth queue. Returns true if it gets pushed into the queue, and false otherwise.
    bool enqueue(int x, int m){
        //for underflowchecking
       if(freeIndex == -1) return false;

       //get new index with freeIndex
       int ind = freeIndex;

       //update freeIndex with next Index array
       freeIndex = next[ind];

       // if first time entry
       if(front[m-1]==-1) front[m-1]=ind;
       //update next of rear to index
       else next[rear[m-1]]=ind;

       //make next index = -1 ie not free
       next[ind]=-1;

       arr[ind]=x;

       //update rear 
       rear[m-1]=ind;

       return true;
    }

    // Dequeues top element from Mth queue. Returns -1 if the queue is empty, otherwise returns the popped element.
    int dequeue(int m){
        //check for underflow
        if(front[m-1]==-1) return -1;

        //get index from front
        int index = front[m-1];

        //update front from next of index
        front[m-1] = next[index];

        
        next[index]=freeIndex;
        freeIndex=index;
        return arr[index];
    }
};
