#include <iostream>
using namespace std;

class Node {
public:
    int x;
    Node* nxt;
    Node(int v): x(v), nxt(NULL) {}
};

class List {
public:
    Node* head;
    List(): head(NULL) {}

    void add(int v){
        Node* n = new Node(v);
        if(!head){ head = n; return; }
        Node* t = head;
        while(t->nxt) t = t->nxt;
        t->nxt = n;
    }

    void show(){
        Node* t = head;
        while(t){
            cout << t->x << " ";
            t = t->nxt;
        }
        cout << "\n";
    }

    static Node* merge(Node* a , Node* b){
        if(!a) return b;
        if(!b) return a;

        Node* start;
        if(a->x < b->x){ start = a; a=a->nxt; }
        else{ start = b; b=b->nxt; }

        Node* tail = start;

        while(a && b){
            if(a->x < b->x){ tail->nxt = a; a=a->nxt; }
            else{ tail->nxt = b; b=b->nxt; }
            tail = tail->nxt;
        }

        if(a) tail->nxt = a;
        if(b) tail->nxt = b;

        return start;
    }
};

int main(){
    List A, B;

    A.add(1); A.add(3); A.add(5);
    B.add(2); B.add(4); B.add(6);

    cout << "A: "; A.show();
    cout << "B: "; B.show();

    Node* merged = List::merge(A.head , B.head);

    cout << "merged: ";
    Node* t = merged;
    while(t){ cout << t->x << " "; t = t->nxt; }
    cout << "\n";
}
