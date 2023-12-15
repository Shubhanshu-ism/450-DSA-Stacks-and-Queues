#include <bits/stdc++.h>
vector<long long> nsl(vector<int>&arr){
    stack<long long> st;
    long long n=arr.size();
    vector<long long> ans;
    for(int i=0;i<n;i++){
      if(st.empty()) ans.push_back(-1);
      else if(st.size() && arr[st.top()]< arr[i]) ans.push_back(st.top());
      else{
          while(st.size() && arr[st.top()] >= arr[i]) st.pop();
          if(st.empty()) ans.push_back(-1);
          else ans.push_back(st.top());
        }
        st.push(i);
    }
    return ans;
}
vector<long long> nsr(vector<int>&arr){
    stack<long long> st;
    long long n=arr.size();
    vector<long long> ans;
    for(int i=n-1;i>=0;i--){
      if(st.empty()) ans.push_back(n);
      else if(st.size() && arr[st.top()]< arr[i]) ans.push_back(st.top());
      else{
          while(st.size() && arr[st.top()] >= arr[i]) st.pop();
          if(st.empty()) ans.push_back(n);
          else ans.push_back(st.top());
        }
        st.push(i);
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
int largestRectangle(vector < int > & heights){
    vector<long long>left= nsl(heights);
    vector<long long>right= nsr(heights);
    int n=heights.size();
    long long mx=0;
    for(int i=0;i<n;i++){
      long long cur =heights[i];
      mx = max(mx, cur*(right[i]-left[i]-1));
    }
    return mx;
}
