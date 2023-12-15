//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

class SortedStack{
public:
	stack<int> s;
	void sort();
};

void printStack(stack<int> s)
{
    while (!s.empty())
    {
        printf("%d ", s.top());
       	s.pop();
    }
    printf("\n");
}

int main()
{
int t;
cin>>t;
while(t--)
{
	SortedStack *ss = new SortedStack();
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
	int k;
	cin>>k;
	ss->s.push(k);
	}
	ss->sort();
	printStack(ss->s);
}
}
// } Driver Code Ends


/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
};
*/

/* The below method sorts the stack s 
you are required to complete the below method */
void insert(int x,stack<int> &st){
    if(st.size()==0) st.push(x);
    else if(st.size() && st.top()<=x) st.push(x);
    else{
        int temp = st.top();
        st.pop();
        insert(x,st);
        st.push(temp);
    }
}
void SortedStack :: sort()
{
    if(s.size()<2) return;
    int temp = s.top();
    s.pop();
    sort();
    stack<int> st;
    st=s;
    insert(temp,st);
    s=st;
    
}
