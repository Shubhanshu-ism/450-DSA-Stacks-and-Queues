#include <bits/stdc++.h> 
class NStack
{
    int *st;
    int *getIndex;
    int *top;
    
    int n,size;

    int free;
public:
    // Initialize your data structure.
    NStack(int N, int S)
    {
        st = new int[S];
        size = S;
        n=N;
        getIndex =new int[S];
        top = new int[N];
        for(int i=0;i<S;i++) getIndex[i]=i+1;
        getIndex[S-1]=-1;
        for(int i=0;i<N;i++) top[i]=-1;  
        free=0;      
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {
        if(free==-1) return false; //check free space
        int ind = free;            // get free index to ind
        free = getIndex[ind];    // grt new free index with the help of next array of given index
        st[ind]=x;              // store value at ind of stack
        getIndex[ind]=top[m-1];  // assign prevous index with the help of top array
        top[m-1]=ind;           // get new top posission
        return true;
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {
        if(top[m-1]==-1) return -1;
        int ind = top[m-1];
        top[m-1]=getIndex[ind];
        getIndex[ind] = free;
        free=ind;
        return st[ind];
    }
};
