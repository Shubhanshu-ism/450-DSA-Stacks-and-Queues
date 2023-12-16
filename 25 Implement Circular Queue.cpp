// Method 1: Without current size counter
#include <bits/stdc++.h> 
class CircularQueue
{
    int *arr;
    int front;
    int rear;
    int size;
    
    public:
    // Initialize your data structure.
    CircularQueue(int n)
    {
        size = n;
        arr = new int[n];
        front=rear=-1;
        
    }

    // Enqueues 'X' into the queue. Returns true if it gets pushed into the stack, and false otherwise.
    bool enqueue(int value){
    
        if( (rear+1)%size==front) return false;
        
        if(front==-1) front=0;

        rear = (rear + 1) % size;
        arr[rear] = value;
        return true;
       
    }

    // Dequeues top element from queue. Returns -1 if the stack is empty, otherwise returns the popped element.
    int dequeue(){
        if(front==-1) return -1;

        int temp = arr[front];

        if(front==rear)
        {
            front=rear=-1;
        }
        else front=(front+1)%size;

        return temp;
    }
};
// Method 2: By Maintaining the Current size counter

class CircularQueue{
    int currentSize;
    int *arr;
    int front;
    int rear;
    int size;
    
    public:
    // Initialize your data structure.
    CircularQueue(int n){
        size = n;
        arr = new int[n];
        front=rear=-1;
        // currentSize=0;
    }

    // Enqueues 'X' into the queue. Returns true if it gets pushed into the stack, and false otherwise.
    bool enqueue(int value){
    
        if( (rear+1)%size==front) return false;
        if(front==-1) front=0;
        rear = (rear + 1) % size;
        arr[rear] = value;
        return true;
       
    }

    // Dequeues top element from queue. Returns -1 if the stack is empty, otherwise returns the popped element.
    int dequeue(){
        if(front==-1) return -1;
        int temp = arr[front];
        // arr[front]=-1;
        if(front==rear){
            front=rear=-1;
        }
        else front=(front+1)%size;
        return temp;
    }
};
