#include <bits/stdc++.h> 
class Queue {
    int  *q;
    int f;
    int rear;
    int n=5001;
public:
    Queue() {
        q = new int[5001];
        f=rear=0;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        return f==rear;
    }

    void enqueue(int data) {
        q[rear]=data;
        rear=(rear+1)%n;
    }

    int dequeue() {
        if(f==rear) return -1;
        int ans=q[f];
        f=(f+1)%n;
        return ans;
    }

    int front() {
        if(rear==f) return -1;
        return q[f];
    }
};
