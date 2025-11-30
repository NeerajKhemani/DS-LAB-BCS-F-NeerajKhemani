#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string key;
    string value;
    Node* next;

    Node(string k , string v) {
        key = k;
        value = v;
        next = nullptr;
    }
};

class Dictionary {
public:
    Node* table[100];

    Dictionary() {
        for(int i=0;i<100;i++) table[i] = nullptr;
    }

    int hashFunction(string s) {
        int sum = 0;
        for(char c : s) sum += int(c);
        return sum % 100;
    }

    void Add_Record(string k , string v) {
        int idx = hashFunction(k);
        Node* n = new Node(k,v);
        n->next = table[idx];
        table[idx] = n;
    }

    void Word_Search(string k) {
        int idx = hashFunction(k);
        Node* t = table[idx];

        while(t) {
            if(t->key == k) {
                cout << "search key " << k << ": " << t->value << endl;
                return;
            }
            t = t->next;
        }

        cout << "Key " << k << " not found!" << endl;
    }

    void Delete_Record(string k) {
        int idx = hashFunction(k);
        Node* t = table[idx];
        Node* prev = nullptr;

        while(t) {
            if(t->key == k) {
                if(prev) prev->next = t->next;
                else table[idx] = t->next;

                cout << "key " << k << " deleted successfully !" << endl;
                delete t;
                return;
            }
            prev = t;
            t = t->next;
        }

        cout << "Key " << k << " not found!" << endl;
    }

    void Print_Dictionary() {
        for(int i=0;i<100;i++) {
            if(table[i]) {
                cout << "index " << i << ": ";
                Node* t = table[i];
                while(t) {
                    cout << "(" << t->key << ", " << t->value << ") ";
                    t = t->next;
                }
                cout << endl;
            }
        }
    }
};

int main() {

    Dictionary d;

    d.Add_Record("AB" , "FASTNU");
    d.Add_Record("CD" , "CS");
    d.Add_Record("EF" , "AI");

    d.Word_Search("AB");

    d.Delete_Record("EF");

    d.Print_Dictionary();

    return 0;
}
