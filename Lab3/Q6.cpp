#include <iostream>
using namespace std;

class Node {
public:
    int x;
    Node* nxt;
    Node* child;
    Node(int v): x(v), nxt(NULL), child(NULL) {}
};

class MList {
public:
    Node* head;
    MList(): head(NULL) {}

    void add(int v){
        Node* n=new Node(v);
        if(!head){ head=n; return; }
        Node* t=head;
        while(t->nxt) t=t->nxt;
        t->nxt=n;
    }

    void show(Node* h){
        Node* t=h;
        while(t){ cout<<t->x<<" "; t=t->nxt; }
        cout<<"\n";
    }

    Node* flatten(Node* h){
        if(!h) return NULL;
        Node* t=h;
        while(t){
            if(t->child){
                Node* nxt = t->nxt;
                Node* cHead = flatten(t->child);
                t->nxt = cHead;
                Node* tail=cHead;
                while(tail->nxt) tail=tail->nxt;
                tail->nxt = nxt;
                t->child=NULL;
            }
            t=t->nxt;
        }
        return h;
    }
};

int main(){
    MList ml;

    ml.add(1);
    ml.add(2);
    ml.add(3);

    // attach child to node 2
    Node* t = ml.head;
    while(t && t->x!=2) t=t->nxt;

    t->child = new Node(4);
    t->child->nxt = new Node(5);

    cout<<"before flatten: 1->2->3 with child 4->5 under 2\n";

    Node* flat = ml.flatten(ml.head);
    cout<<"after flatten: ";
    ml.show(flat);
}
