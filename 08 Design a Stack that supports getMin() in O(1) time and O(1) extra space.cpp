//{ Driver Code Starts
#include<iostream>
#include<stack>
using namespace std;
void push(stack<int>& s,int a);
bool isFull(stack<int>& s,int n);
bool isEmpty(stack<int>& s);
int pop(stack<int>& s);
int getMin(stack<int>& s);
//This is the STL stack (http://quiz.geeksforgeeks.org/stack-container-adaptors-the-c-standard-template-library-stl/).
stack<int> s;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,a;
		cin>>n;
		while(!isEmpty(s)){
		    pop(s);
		}
		while(!isFull(s,n)){
			cin>>a;
			push(s,a);
		}
		cout<<getMin(s)<<endl;
	}
}
// } Driver Code Ends


int m=1e9;
void push(stack<int>& s, int a){
	if(m>a) m=a;
	s.push(a);
}

bool isFull(stack<int>& s,int n){
	return s.size()==n;
}

bool isEmpty(stack<int>& s){
	return s.empty();
}

int pop(stack<int>& s){
    if(s.empty()) return -1;
    int ans=s.top();
    s.pop();
    if(!s.empty() &&s.top()<m) m=s.top();
    else if(s.empty()) m=1e9;
	return ans;
}

int getMin(stack<int>& s){
    if(s.size()==0) return -1;
	return m;
}
