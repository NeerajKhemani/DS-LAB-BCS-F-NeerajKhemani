#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node(int v) : val(v), next(NULL) {}
};

class LinkedList {
    Node* head;

    Node* reverse(Node* h) {
        Node* prev = NULL;
        Node* cur = h;
        while(cur){
            Node* nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
        }
        return prev;
    }

public:
    LinkedList() {
        head = NULL;
    }

    void add(int v){
        Node* n = new Node(v);
        if(!head){ head = n; return; }
        Node* t = head;
        while(t->next) t = t->next;
        t->next = n;
    }

    bool checkPalindrome(){
        if(!head || !head->next) return true;

        Node* slow = head;
        Node* fast = head;
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        Node* half = reverse(slow->next);
        Node* p1 = head;
        Node* p2 = half;

        bool ok = true;
        while(p2){
            if(p1->val != p2->val){
                ok = false;
                break;
            }
            p1 = p1->next;
            p2 = p2->next;
        }

        slow->next = reverse(half);
        return ok;
    }

    void show(){
        Node* t = head;
        while(t){
            cout << t->val << " ";
            t = t->next;
        }
        cout << "\n";
    }
};

int main(){
    LinkedList lst;
    lst.add(1);
    lst.add(2);
    lst.add(3);
    lst.add(2);
    lst.add(1);

    lst.show();
    cout << (lst.checkPalindrome() ? "true" : "false") << endl;
}
