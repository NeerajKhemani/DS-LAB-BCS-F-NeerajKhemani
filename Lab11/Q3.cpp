#include <iostream>
#include <list>
#include <vector>
using namespace std;

class Hash {
private:
    int bucketCount;
    vector<list<int>> table;

    int hashFunction(int key) {
        return key % bucketCount;
    }

public:
    Hash(int buckets) {
        bucketCount = buckets;
        table.resize(bucketCount);
    }

    void insert(int key) {
        int index = hashFunction(key);
        for (int x : table[index])
            if (x == key)
                return;
        table[index].push_back(key);
    }

    void remove(int key) {
        int index = hashFunction(key);
        table[index].remove(key);
    }

    bool search(int key) {
        int index = hashFunction(key);
        for (int x : table[index])
            if (x == key)
                return true;
        return false;
    }

    void display() {
        for (int i = 0; i < bucketCount; i++) {
            cout << i << " --> ";
            for (int x : table[i])
                cout << x << " ";
            cout << "\n";
        }
    }
};

int main() {
    Hash h(7);

    h.insert(10);
    h.insert(20);
    h.insert(15);
    h.insert(7);
    h.insert(17);

    h.display();

    cout << (h.search(15) ? "Found\n" : "Not Found\n");

    h.remove(20);

    h.display();

    return 0;
}
