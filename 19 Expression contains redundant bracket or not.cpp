//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int checkRedundancy(string s)
    {
        int n=s.size();
        stack<char> st;
        
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(' || isOperator(s[i])) st.push(s[i]);
            else if( s[i]==')' )
            {
                if( st.top()=='(' ) return true;
                while(st.size() && st.top()!='(') st.pop();
                st.pop();
            }
        }
        
        return false;
    }
    
    bool isOperator(char c){
        if(c=='+' || c=='*' || c=='-' || c=='/') return true;
	    return false;
    }
};

bool checkStringExpression(string str) 
{
	int n= str.size();
	stack<char> st;
	for(int i=0;i<n;i++)
	{
		if(str[i]=='(' || isOperator(str[i]))
		{
			st.push(str[i]);
		}
		else
		{
			if(str[i]==')')
			{
				bool isRedundant = true;
				while(st.top()!='(')
				{
					char t = st.top();
					if(isOperator(t)) isRedundant= false;
					st.pop();
				}
				if(isRedundant) return true;
				st.pop();
			}
		}
	}
	return false;
}

//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        
    
        string s; 
        cin>>s;
        
        Solution obj;
        int res = obj.checkRedundancy(s);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends
