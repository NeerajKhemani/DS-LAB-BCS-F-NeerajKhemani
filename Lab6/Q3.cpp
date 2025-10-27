#include <iostream>
using namespace std;

class Queue{
   int arr[100];
   int front, rear, size;
public:
   Queue(int s=10){
      size=s; front=-1; rear=-1;
   }

   void enqueue(int x){
      if(rear==size-1){
         cout<<"Queue Full!\n";
         return;
      }
      if(front==-1) front=0;
      arr[++rear]=x;
      cout<<x<<" added to queue\n";
   }

   void dequeue(){
      if(front==-1 || front>rear){
         cout<<"Queue Empty!\n";
         return;
      }
      cout<<"Removed: "<<arr[front++]<<endl;
      if(front>rear){ front=-1; rear=-1; }
   }

   void display(){
      if(front==-1){ cout<<"Queue Empty!\n"; return; }
      cout<<"Queue: ";
      for(int i=front;i<=rear;i++)
         cout<<arr[i]<<" ";
      cout<<endl;
   }

   void check(){
      if(front==-1) cout<<"Queue is Empty\n";
      else if(rear==size-1) cout<<"Queue is Full\n";
      else cout<<"Queue has space\n";
   }
};


int main(){
   Queue q(5);
   int ch,x;

   while(1){
      cout<<"\n1.Enqueue  2.Dequeue  3.Display  4.Check  5.Exit\n";
      cout<<"Enter choice: ";
      cin>>ch;

      switch(ch){
         case 1:
            cout<<"Enter value: "; cin>>x;
            q.enqueue(x);
            break;

         case 2:
            q.dequeue();
            break;

         case 3:
            q.display();
            break;

         case 4:
            q.check();
            break;

         case 5:
            cout<<"Bye!\n";
            return 0;

         default:
            cout<<"Invalid!\n";
      }
   }
}
