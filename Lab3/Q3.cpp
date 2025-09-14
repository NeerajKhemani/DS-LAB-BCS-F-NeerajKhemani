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
        while(t){ cout << t->x << " "; t = t->nxt; }
        cout << "\n";
    }

    Node* reverseK(Node* h , int k){
        if(!h) return NULL;
        Node* cur = h;
        Node* prev = NULL;
        Node* nxt = NULL;
        int cnt = 0;

        Node* tmp = h;
        for(int i=0;i<k && tmp;i++) tmp=tmp->nxt;
        if(!tmp && cnt<k && !h->nxt) return h;

        while(cur && cnt<k){
            nxt = cur->nxt;
            cur->nxt = prev;
            prev = cur;
            cur = nxt;
            cnt++;
        }

        if(nxt) h->nxt = reverseK(nxt , k);

        return prev;
    }
};

int main(){
    List L;
    for(int i=1;i<=8;i++) L.add(i);

    cout << "orig: "; L.show();

    int k = 3;
    L.head = L.reverseK(L.head , k);

    cout << "k="<<k<<" rev: ";
    L.show();
}
