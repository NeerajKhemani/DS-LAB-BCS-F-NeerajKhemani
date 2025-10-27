#include <iostream>
#include <string>
using namespace std;

struct Node{
   string url;
   Node* next;
};

class Stack{
   Node* top;
public:
   Stack(){ top=NULL; }

   void push(string link){
      Node* n = new Node();
      n->url = link;
      n->next = top;
      top = n;
      cout<<"Visited: "<<link<<endl;
   }

   void pop(){
      if(!top){ cout<<"No previous page\n"; return; }
      cout<<"Back from "<<top->url<<endl;
      Node* t = top;
      top = top->next;
      delete t;
   }

   void peek(){
      if(!top){ cout<<"No current page\n"; return; }
      cout<<"Current: "<<top->url<<endl;
   }

   void display(){
      if(!top){ cout<<"History empty\n"; return; }
      cout<<"History:\n";
      Node* temp = top;
      while(temp){
         cout<<" -> "<<temp->url<<endl;
         temp = temp->next;
      }
   }
};


int main(){
   Stack history;
   int ch;
   string link;

   while(1){
      cout<<"\n1.Visit Page  2.Go Back  3.Current Page  4.Show History  5.Exit\n";
      cout<<"Enter choice: ";
      cin>>ch;

      switch(ch){
         case 1:
            cout<<"Enter URL: ";
            cin>>link;
            history.push(link);
            break;

         case 2:
            history.pop();
            break;

         case 3:
            history.peek();
            break;

         case 4:
            history.display();
            break;

         case 5:
            cout<<"Exiting...\n";
            return 0;

         default:
            cout<<"Invalid!\n";
      }
   }
}
