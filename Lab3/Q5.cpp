#include <iostream>
using namespace std;

class SNode {
public:
    int x;
    SNode* nxt;
    SNode(int v): x(v), nxt(NULL) {}
};

class DNode {
public:
    int x;
    DNode* nxt;
    DNode* prev;
    DNode(int v): x(v), nxt(NULL), prev(NULL) {}
};

class Singly {
public:
    SNode* head;
    Singly(): head(NULL) {}

    void add(int v){
        SNode* n = new SNode(v);
        if(!head){ head=n; return; }
        SNode* t=head;
        while(t->nxt) t=t->nxt;
        t->nxt = n;
    }

    void show(){
        SNode* t=head;
        while(t){ cout<<t->x<<" "; t=t->nxt; }
        cout<<"\n";
    }

    DNode* toDoubly(){
        if(!head) return NULL;
        SNode* t=head;
        DNode* dHead = new DNode(t->x);
        DNode* dCur = dHead;
        t = t->nxt;
        while(t){
            DNode* n = new DNode(t->x);
            dCur->nxt = n;
            n->prev = dCur;
            dCur = n;
            t = t->nxt;
        }
        return dHead;
    }

    SNode* toCircular(){
        if(!head) return NULL;
        SNode* t=head;
        while(t->nxt) t=t->nxt;
        t->nxt=head;
        return head;
    }
};

void showD(DNode* h){
    DNode* t=h;
    while(t){ cout<<t->x<<" "; t=t->nxt; }
    cout<<"\n";
}

void showC(SNode* h, int n){
    SNode* t=h;
    for(int i=0;i<n;i++){ cout<<t->x<<" "; t=t->nxt; }
    cout<<"\n";
}

int main(){
    Singly L;
    for(int i=1;i<=5;i++) L.add(i);

    cout<<"Singly: "; L.show();

    DNode* dHead = L.toDoubly();
    cout<<"Doubly: "; showD(dHead);

    SNode* cHead = L.toCircular();
    cout<<"Circular (10 steps): "; showC(cHead, 10);
}
