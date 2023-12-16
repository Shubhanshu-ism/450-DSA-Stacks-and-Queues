//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

class StackQueue{
private:
    stack<int> s1;
    stack<int> s2;
public:
    void push(int B);
    int pop();

};
int main()
{

    int T;
    cin>>T;
    while(T--)
    {
        StackQueue *sq = new StackQueue();

        int Q;
        cin>>Q;
        while(Q--){
        int QueryType=0;
        cin>>QueryType;
        if(QueryType==1)
        {
            int a;
            cin>>a;
            sq->push(a);
        }else if(QueryType==2){
            cout<<sq->pop()<<" ";

        }
        }
        cout<<endl;
    }


}

// } Driver Code Ends


/* The structure of the class is
class StackQueue{
private:   
    // These are STL stacks ( http://goo.gl/LxlRZQ )
    stack<int> s1;
    stack<int> s2;
public:
    void push(int);
    int pop();
}; */

//Function to push an element in queue by using 2 stacks.
void StackQueue :: push(int x)
{
    /*
        stack1      stack 2         
        | 3 |       |   |
        | 2 |       |   |
        | 1 |       |   |
         ---         ---
    */
    while(s1.size())
    {
        s2.push(s1.top());
        s1.pop();
    }
    /*
        stack1      stack 2         
        |   |        | 1 |
        |   |        | 2 |
        |   |        | 3 |
         ---         ---
    */
    
    s1.push(x);
    /*
        stack1      stack 2         
        |   |        | 1 |
        |   |        | 2 |
        | x |        | 3 |
         ---         ---
    */
    
    while(s2.size())
    {
        s1.push(s2.top());
        s2.pop();
    }
    /*
        stack1      stack 2         
        | 3 |       |   |
        | 2 |       |   |
        | 1 |       |   |
        | x |       |   |
         ---         ---
    */
}

//Function to pop an element from queue by using 2 stacks.
int StackQueue :: pop()
{
    /*
        stack1      stack 2         
        | 3 |       |   |
        | 2 |       |   |
        | 1 |       |   |
        | x |       |   |
         ---         ---
        
       temp = 3;
       
       /*
        stack1      stack 2         
        |   |       |   |
        | 2 |       |   |
        | 1 |       |   |
        | x |       |   |
         ---         ---
    */
    */
    if(s1.empty()) return -1;
    int top = s1.top();
    s1.pop();
    return top;
}
