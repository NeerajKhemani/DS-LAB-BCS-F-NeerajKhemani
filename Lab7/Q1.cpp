#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct node {
    string name;
    int score;
    node *next;
};

void addNode(node **h,string n,int s){
    node *t=new node;
    t->name=n; t->score=s;
    t->next=*h;
    *h=t;
}

int getMaxScore(node *h){
    int m=0;
    while(h){
        if(h->score>m) m=h->score;
        h=h->next;
    }
    return m;
}

void pushBack(node **h,string n,int s){
    node *t=new node; t->name=n; t->score=s; t->next=nullptr;
    if(!*h){ *h=t; return; }
    node *p=*h;
    while(p->next) p=p->next;
    p->next=t;
}

void radixSort(node **head){

    int mx = getMaxScore(*head);
    int exp=1;

    while(mx/exp > 0){

        vector<node*> b(10,nullptr),tails(10,nullptr);
        node *cur=*head;

        while(cur){
            int d = (cur->score/exp)%10;
            if(!b[d]){
                b[d]=tails[d]=cur;
            } else {
                tails[d]->next=cur;
                tails[d]=cur;
            }
            cur=cur->next;
        }

        node *newH=nullptr,*last=nullptr;

        for(int i=0;i<10;i++){
            if(b[i]){
                if(!newH){
                    newH=b[i];
                    last=tails[i];
                } else {
                    last->next=b[i];
                    last=tails[i];
                }
            }
        }

        if(last) last->next=nullptr;

        *head=newH;
        exp*=10;
    }
}

vector<node*> listToArray(node *h){
    vector<node*> a;
    while(h){ a.push_back(h); h=h->next; }
    return a;
}

int bs(vector<node*> &a,string x,int val){
    
    int l=0,r=a.size()-1;

    while(l<=r){
        int m=(l+r)/2;
        if(a[m]->score==val && a[m]->name==x) return m;

        if(a[m]->score < val) l=m+1;
        else if(a[m]->score > val) r=m-1;
        else {
            if(a[m]->name < x) l=m+1;
            else r=m-1;
        }
    }
    return -1;
}

void deleteNode(node **h,string nm,int sc){
    node *p=*h,*pr=nullptr;

    while(p){
        if(p->name==nm && p->score==sc){
            if(pr==nullptr){
                *h=p->next;
            } else pr->next=p->next;
            delete p;
            return;
        }
        pr=p;
        p=p->next;
    }
}

void printList(node *h){
    while(h){
        cout<<h->name<<" "<<h->score<<"\n";
        h=h->next;
    }
}

int main(){

    node *head=nullptr;

    addNode(&head,"Ayan",90);
    addNode(&head,"Zameer",60);
    addNode(&head,"Sara",70);
    addNode(&head,"Sohail",30);
    addNode(&head,"Ahmed",20);

    radixSort(&head);

    printList(head);

    cout<<"\nenter name : ";
    string n;
    cin>>n;
    cout<<"enter score : ";
    int s;
    cin>>s;

    vector<node*> arr = listToArray(head);

    int idx = bs(arr,n,s);

    if(idx!=-1){
        deleteNode(&head,n,s);
        cout<<"\nupdated list:\n";
        printList(head);
    }

    return 0;
}
