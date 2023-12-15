//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for c++
class Solution {
  public:
    //Greedy solution
    int findMaxLen(string s) {
        
        int o=0, c=0;
        int ans=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(') o++;
            else if(s[i]==')') c++;
            if(o==c) ans=max(ans,o+c);
            else if(c>o){
                o=c=0;
            }
        }
        o=c=0;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]==')') c++;
            else if(s[i]=='(') o++;
            if(o==c) ans=max(ans,o+c);
            else if(o>c){
                o=c=0;
            }
        }
        return ans;
    }
    //Stack solution
    int findMaxLenST(string s) {
        // code here
        int ans=0;
        stack<int> st;
        st.push(-1);
        
        for(int i=0;i<s.size();i++){
            if(s[i]=='(') st.push(i);
            else 
            {
                st.pop();
                if(st.size()){
                    ans=max(ans, i-st.top());
                }
                else st.push(i);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S; 
        Solution ob;
        cout << ob.findMaxLen(S) << endl;
    }
    return 0;
}

// } Driver Code Ends
