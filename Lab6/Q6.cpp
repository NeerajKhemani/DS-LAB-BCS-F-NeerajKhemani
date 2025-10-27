#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
#include <cctype>
#include <cmath>
using namespace std;

int prec(char c){
   if(c=='^') return 3;
   if(c=='*' || c=='/') return 2;
   if(c=='+' || c=='-') return 1;
   return -1;
}

string infixToPrefix(string s){
   reverse(s.begin(), s.end());
   for(int i=0;i<s.length();i++){
      if(s[i]=='(') s[i]=')';
      else if(s[i]==')') s[i]='(';
   }

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
         while(!st.empty() && prec(st.top())>prec(c)){
            res+=st.top(); st.pop();
         }
         st.push(c);
      }
   }
   while(!st.empty()){ res+=st.top(); st.pop(); }

   reverse(res.begin(), res.end());
   return res;
}

int evalPrefix(string s){
   stack<int> st;
   for(int i=s.length()-1;i>=0;i--){
      char c=s[i];
      if(isdigit(c)) st.push(c-'0');
      else{
         int a=st.top(); st.pop();
         int b=st.top(); st.pop();
         switch(c){
            case '+': st.push(a+b); break;
            case '-': st.push(a-b); break;
            case '*': st.push(a*b); break;
            case '/': st.push(a/b); break;
            case '^': st.push(pow(a,b)); break;
         }
      }
   }
   return st.top();
}


int main(){
   string infix;
   cout<<"Enter infix expression: ";
   cin>>infix;

   string prefix = infixToPrefix(infix);
   cout<<"Prefix: "<<prefix<<endl;

   int result = evalPrefix(prefix);
   cout<<"Result: "<<result<<endl;
}
