#include <iostream>
using namespace std;

class Node {
public:
    int x;
    Node* nxt;
    Node(int v): x(v), nxt(NULL) {}
};

class Circle {
public:
    Node* head;
    Circle(): head(NULL) {}

    void add(int v){
        Node* n = new Node(v);
        if(!head){
            head = n;
            n->nxt = head;
            return;
        }
        Node* t = head;
        while(t->nxt != head) t = t->nxt;
        t->nxt = n;
        n->nxt = head;
    }

    int josephus(int k){
        Node* p = head;
        Node* prev = NULL;

        while(p->nxt != p){
            for(int i=1;i<k;i++){ prev = p; p = p->nxt; }
            prev->nxt = p->nxt;
            Node* del = p;
            p = p->nxt;
            delete del;
        }
        return p->x;
    }
};

int main(){
    int N=7 , k=3;
    Circle c;
    for(int i=1;i<=N;i++) c.add(i);

    cout << "N="<<N<<" k="<<k<<" -> survivor: " << c.josephus(k) << "\n";
}
