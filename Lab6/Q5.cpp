#include <iostream>
#include <stack>
#include <string>
#include <cctype>
#include <cmath>
using namespace std;

int prec(char c){
   if(c=='^') return 3;
   if(c=='*' || c=='/') return 2;
   if(c=='+' || c=='-') return 1;
   return -1;
}

string infixToPostfix(string s){
   stack<char> st;
   string res="";
   for(int i=0;i<s.length();i++){
      char c=s[i];
      if(isalnum(c)) res+=c;
      else if(c=='(') st.push(c);
      else if(c==')'){
         while(!st.empty() && st.top()!='('){
            res+=st.top(); st.pop();
         }
         if(!st.empty()) st.pop();
      }
      else{
         while(!st.empty() && prec(st.top())>=prec(c)){
            res+=st.top(); st.pop();
         }
         st.push(c);
      }
   }
   while(!st.empty()){ res+=st.top(); st.pop(); }
   return res;
}

int evalPostfix(string exp){
   stack<int> st;
   for(int i=0;i<exp.length();i++){
      char c=exp[i];
      if(isdigit(c)) st.push(c-'0');
      else{
         int v2=st.top(); st.pop();
         int v1=st.top(); st.pop();
         switch(c){
            case '+': st.push(v1+v2); break;
            case '-': st.push(v1-v2); break;
            case '*': st.push(v1*v2); break;
            case '/': st.push(v1/v2); break;
            case '^': st.push(pow(v1,v2)); break;
         }
      }
   }
   return st.top();
}


int main(){
   string infix;
   cout<<"Enter infix expression: ";
   cin>>infix;

   string postfix = infixToPostfix(infix);
   cout<<"Postfix: "<<postfix<<endl;

   int result = evalPostfix(postfix);
   cout<<"Result: "<<result<<endl;
}
