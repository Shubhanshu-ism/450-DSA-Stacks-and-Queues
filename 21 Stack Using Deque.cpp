#include <bits/stdc++.h> 
class Stack
{
    deque<int> dq;
    int length;
public:
    // Initialize your data structure.
    Stack()
    {
        length=0;
    }

    // Pushes 'X' into the stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x)
    {
        // Write your code here.
        dq.push_back(x);
        length++;
        return true;
    }

    // Pops top element from Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop()
    {
        if(isEmpty()) return -1;
        int temp = dq.back();
        dq.pop_back();
        length--;
        return temp;
    }

    // Returns the topmost element of the stack. In case the stack is empty, it returns -1.
    int top()
    {
        if(isEmpty()) return -1;
        return dq.back();
    }

    // Returns true if the stack is empty, otherwise false.
    bool isEmpty()
    {
        if(length==0) return true;
        return false;
    }

    // Returns the number of elements currently present in the stack.
    int size()
    {
        return length;
    }
};
