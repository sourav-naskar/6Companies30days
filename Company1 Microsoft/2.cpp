#include<bits/stdc++.h>
using namespace std;


int solve(long op1,long  op2,string i){
                if(i == "+") 
                    op1 = op2 + op1 ;
                if(i == "-") 
                    op1 = op2 - op1 ;
                if(i == "*") 
                    op1 = op2*op1 ; 
                if(i == "/") 
                    op1 = op2/op1 ; 
                return op1;
}

int evalRPN(vector<string>& tokens) {
        stack<long > s ;
        
        for(auto &i:tokens)
        { 
            if(i == "+" || i == "-" || i == "*" || i == "/") // operators 
            {
                long  op1 = s.top() ; 
                
                s.pop() ;
                long  op2 = s.top() ; 
                s.pop() ;
                
                int x=solve(op1,op2,i);
                
                s.push(x) ;
            }
            else 
                s.push(stol(i)) ; // number -> need to convert from str to int
        }
        int ans = -1;
        if (!s.empty()){
        ans = s.top();
        }
        return ans;
    }    
         

   

int main(){
	long n;
	cin>>n;
	string s;
	vector<string>v;
	while(n--){
		
		cin>>s;
		v.push_back(s);
	}
	cout<<evalRPN(v);
}