#include <iostream>
using namespace std;

struct node{
    int d;
    node *n;
};

node* newNode(int x){
    node* t = new node;
    t->d=x; t->n=nullptr;
    return t;
}

void push(node **h,int x){
    node* t=newNode(x);
    t->n=*h;
    *h=t;
}

void swapp(node* a,node* b){
    int t=a->d;
    a->d=b->d;
    b->d=t;
}

node* part(node* l,node* h){
    int p=h->d;
    node* i=l , *j=l;

    while(j!=h){
        if(j->d <= p){
            swapp(i,j);
            i=i->n;
        }
        j=j->n;
    }
    swapp(i,h);
    return i;
}

void quickS(node* l,node* h){
    if(!l || l==h || !h) return;

    node* p=part(l,h);

    if(p!=l){
        node* t=l;
        while(t->n!=p) t=t->n;
        quickS(l,t);
    }
    quickS(p->n,h);
}

node* last(node* h){
    while(h && h->n) h=h->n;
    return h;
}

void print(node *h){
    while(h){
        cout<<h->d<<" ";
        h=h->n;
    }
    cout<<endl;
}

int main(){

    node *h=nullptr;

    push(&h,3);
    push(&h,5);
    push(&h,1);
    push(&h,9);
    push(&h,8);
    push(&h,7);
    push(&h,10);

    node* e = last(h);

    quickS(h,e);

    print(h);

    return 0;
}
