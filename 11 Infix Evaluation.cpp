#include <bits/stdc++.h> 
int precedence(char c){
	if(c=='*' || c=='/') return 2;
	else if(c=='+' || c=='-') return 1;
	return -1;
}
bool isOperator(char c){
	if(c=='+'||c=='-'||c=='*' ||c=='/') return true;
	return false;
}
vector<string> PostFix(string &expression){
	vector<string> postfix;
	stack<char> st;
	int n=expression.size();
	for(int i=0;i<n;i++)
	{
		
		if(expression[i]=='(') st.push('(');
		else if(expression[i]==')')
		{
			while(st.size() && st.top()!='(')
			{
				string temp =string(1,st.top());
				postfix.push_back(temp);
				st.pop();
			}
			if(!st.empty()) st.pop();
		}
		else if(isOperator(expression[i])) 
		{
			int preceTop = precedence(expression[i]);
			while(!st.empty() && precedence(st.top()) >= preceTop){
				string temp =string(1,st.top());
				postfix.push_back(temp);
				st.pop();
			}
			st.push(expression[i]);

		}
		else{
			string num="";
			while(expression[i]!=')' && !isOperator(expression[i])){
				num+=expression[i];
				i++;
			}
			i--;
			postfix.push_back(num);
		}

	}
	while(st.size()){

		string temp =string(1,st.top());
		postfix.push_back(temp);
		st.pop();
	}
	return postfix;
}
int oper(int a, int b,char c){
	if(c=='+') return a+b;
	else if(c=='*') return a*b;
	else if(c=='-') return a-b;
	else if(c=='/') return a/b;
}
int PostFixVal(vector<string> & s){
	stack<int> st;
	int ans=0;
	for(string str: s)
	{
		char ch=str[0];
		if(isOperator(ch))
		{
			int b=0;
			if(st.size()){
				 b= st.top();
				 st.pop();
			}
			int a=0;
			if(st.size()){
				 a= st.top();
				 st.pop();
			}
			int val = oper(a,b,ch);
			st.push(val);
		}
		else{
			int num=stoi(str);
			st.push(num);
		}
	}
	if(st.size()) ans=st.top();
	return ans;
}
int evaluateArithmeticExpression(string &expression) 
{
	vector<string> postfix =PostFix(expression);
	int ans = PostFixVal(postfix);
	return ans;

}
