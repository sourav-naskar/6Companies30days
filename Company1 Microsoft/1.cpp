#include<bits/stdc++.h>
using namespace std;

long evaluate (long a, string op, long b){
long ans;

if (op == "+")
ans = a+b;
else if (op == "-")
ans = a-b;
else if (op == "*")
ans = a*b;
else if (op == "/" && b!=0)
ans = a/b;

return ans;
}

int evalRPN(vector<string>& tokens) {
stack <long> s;
int size = tokens.size();
for (int i=0; i<size;++i ){
 if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/"){

    string operation = tokens[i];
    
    long firstOprnd, secOprnd;
    if (!s.empty()){
    secOprnd = s.top();
    s.pop();
    }
    if (!s.empty()){
    firstOprnd = s.top();
    s.pop();
    s.push(evaluate(firstOprnd, operation, secOprnd));
    }
}
else
 s.push(stol(tokens[i]));

}

long ans = -1;
if (!s.empty()){
ans = s.top();
}
return (int)ans;
}

int main(){
	int n;
	cin>>n;
	string s;
	vector<string>v;
	while(n--){
		
		cin>>s;
		v.push_back(s);
	}
	cout<<evalRPN(v);
	return 0;
}