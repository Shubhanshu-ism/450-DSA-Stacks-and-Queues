//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends


class twoStacks
{
    int *st;
    int p1,p2;
    int size;
    public:
    twoStacks(int n=1000)
    {
        size=n;
        st= new int[n];
        p1=-1;
        p2=n;
    }
 
    //Function to push an integer into the stack1.
    void push1(int x)
    {
        if(p2-p1>1){
            st[++p1]=x;
        }
        
    }
    
    //Function to push an integer into the stack2.
    void push2(int x)
    {
       if(p2-p1>1){
            st[--p2]=x;
        }
    }
    
    //Function to remove an element from top of the stack1.
    int pop1()
    {
        if(p1==-1) return -1;
        int ans=st[p1--];
        return ans;
    }
    
    //Function to remove an element from top of the stack2.
    int pop2()
    {
        if(p2==size) return -1;
        int ans=st[p2++];
        return ans;
    }
};



//{ Driver Code Starts.

int main()
{

    int T;
    cin>>T;
    while(T--)
    {
        twoStacks *sq = new twoStacks();

        int Q;
        cin>>Q;
        while(Q--){
        int stack_no;
        cin>>stack_no;
        int QueryType=0;
        cin>>QueryType;
        
        if(QueryType==1)
        {
            int a;
            cin>>a;
            if(stack_no ==1)
            sq->push1(a);
            else if(stack_no==2)
            sq->push2(a);
        }else if(QueryType==2){
        	if(stack_no==1)
            cout<<sq->pop1()<<" ";
            else if(stack_no==2)
            cout<<sq->pop2()<<" ";

        }
        }
        cout<<endl;
    }
}

// } Driver Code Ends
/*
input:
6
1 1 2 
1 1 3 
2 1 4 
1 2 
2 2 
2 2

output:
3 4 -1

Input Format:
First line contains an integer Q denoting the number of queries . 
A Query Q is of 4 Types
(i)    1 1 x    (a query of this type means  pushing 'x' into the stack 1)
(ii)   1 2      (a query of this type means to pop element from stack1  and print the poped element)
(iii)  2 1 x  (a query of this type means pushing 'x' into the stack 2)
(iv)  2 2     (a query of this type means to pop element from stack2 and print the poped element)
The second line contains Q queries seperated by space.
*/
