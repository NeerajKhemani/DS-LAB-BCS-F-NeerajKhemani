#include <iostream>
using namespace std;

class CQueue{
   int arr[100];
   int front, rear, size;
public:
   CQueue(int s=5){
      size=s;
      front=-1;  rear=-1;
   }

   void enqueue(int x){
      if( (front==0 && rear==size-1) || (rear+1)%size==front ){
         cout<<"Queue Full!\n";
         return;
      }
      if(front==-1) front=0;
      rear = (rear+1)%size;
      arr[rear]=x;
      cout<<x<<" added\n";
   }

   void dequeue(){
      if(front==-1){
         cout<<"Queue Empty!\n";
         return;
      }
      cout<<"Removed: "<<arr[front]<<endl;
      if(front==rear){
         front=-1; rear=-1;
      } else {
         front = (front+1)%size;
      }
   }

   void display(){
      if(front==-1){ cout<<"Queue Empty!\n"; return; }
      cout<<"Queue: ";
      int i=front;
      while(true){
         cout<<arr[i]<<" ";
         if(i==rear) break;
         i = (i+1)%size;
      }
      cout<<endl;
   }
};


int main(){
   CQueue q(5);
   int ch,x;

   while(1){
      cout<<"\n1.Enqueue  2.Dequeue  3.Display  4.Exit\n";
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
            cout<<"Bye!\n";
            return 0;

         default:
            cout<<"Invalid!\n";
      }
   }
}
