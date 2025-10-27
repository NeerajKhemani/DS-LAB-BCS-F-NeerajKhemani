#include <iostream>
#include <stack>
#include <queue>
using namespace std;

struct Process{
   int id;
   int prio;
};

class JobSystem{
   queue<Process> q;
   stack<Process> s;

public:
   void addProcess(int id, int p){
      Process proc;
      proc.id=id; proc.prio=p;
      q.push(proc);
      cout<<"Process "<<id<<" (Priority "<<p<<") added\n";
   }

   void moveToStack(){
      if(q.empty()){ cout<<"No process in queue\n"; return; }

      while(!q.empty()){
         s.push(q.front());
         q.pop();
      }
      cout<<"All queued processes moved to stack for execution\n";
   }

   void executeJob(){
      if(s.empty()){ cout<<"No process to execute\n"; return; }
      Process p=s.top(); s.pop();
      cout<<"Executing Process "<<p.id<<" (Priority "<<p.prio<<")\n";
   }

   void showQueue(){
      if(q.empty()){ cout<<"Queue empty\n"; return; }
      queue<Process> temp=q;
      cout<<"Queue (Arrival Order): ";
      while(!temp.empty()){
         cout<<"["<<temp.front().id<<","<<temp.front().prio<<"] ";
         temp.pop();
      }
      cout<<endl;
   }

   void showStack(){
      if(s.empty()){ cout<<"Stack empty\n"; return; }
      stack<Process> temp=s;
      cout<<"Stack (Execution Order): ";
      while(!temp.empty()){
         cout<<"["<<temp.top().id<<","<<temp.top().prio<<"] ";
         temp.pop();
      }
      cout<<endl;
   }
};


int main(){
   JobSystem js;
   int ch,id,p;

   while(1){
      cout<<"\n1.Add Process  2.Move to Stack  3.Execute Job  4.Show Queue  5.Show Stack  6.Exit\n";
      cout<<"Enter choice: "; cin>>ch;

      switch(ch){
         case 1:
            cout<<"Enter Process ID: "; cin>>id;
            cout<<"Enter Priority: "; cin>>p;
            js.addProcess(id,p);
            break;

         case 2:
            js.moveToStack();
            break;

         case 3:
            js.executeJob();
            break;

         case 4:
            js.showQueue();
            break;

         case 5:
            js.showStack();
            break;

         case 6:
            cout<<"Bye!\n"; return 0;

         default:
            cout<<"Invalid!\n";
      }
   }
}
