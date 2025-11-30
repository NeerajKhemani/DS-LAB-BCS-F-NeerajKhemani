#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string key;
    string value;
    Node* next;

    Node(string k, string v) {
        key = k;
        value = v;
        next = nullptr;
    }
};

class HashTable {
public:
    int size;
    Node** table;

    HashTable(int s = 10) {
        size = s;
        table = new Node*[size];
        for(int i=0;i<size;i++) table[i] = nullptr;
    }

    int hashFunction(string s) {
        int sum = 0;
        for(char c : s) sum += int(c);
        return sum % size;
    }

    void insert(string k , string v) {
        int idx = hashFunction(k);
        Node* n = new Node(k,v);
        n->next = table[idx];
        table[idx] = n;
    }

    void display() {
        for(int i=0;i<size;i++) {
            cout << "[" << i << "] -> ";
            Node* t = table[i];
            while(t) {
                cout << "(" << t->key << "," << t->value << ") ";
                t = t->next;
            }
            cout << endl;
        }
    }
};

int main() {
    HashTable myhash;

    myhash.insert("A","aaaaa");
    myhash.insert("B","bbbbb");
    myhash.insert("C","ccccc");
    myhash.insert("A","zzzzz");

    myhash.display();

    return 0;
}
