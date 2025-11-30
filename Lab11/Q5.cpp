#include <iostream>
using namespace std;

class Student {
public:
    int roll;
    string name;
    bool occupied;

    Student() {
        roll = -1;
        name = "";
        occupied = false;
    }
};

class StudentHashTable {
public:
    Student table[15];

    int hashFunc(int roll) {
        return roll % 15;
    }

    void InsertRecord(int roll, string name) {
        int index = hashFunc(roll);
        int attempt = 0;

        while (attempt < 15) {
            int newIndex = (index + attempt * attempt) % 15;
            if (!table[newIndex].occupied) {
                table[newIndex].roll = roll;
                table[newIndex].name = name;
                table[newIndex].occupied = true;
                return;
            }
            attempt++;
        }
        cout << "Table full, cannot insert\n";
    }

    void SearchRecord(int roll) {
        int index = hashFunc(roll);
        int attempt = 0;

        while (attempt < 15) {
            int newIndex = (index + attempt * attempt) % 15;

            if (table[newIndex].occupied && table[newIndex].roll == roll) {
                cout << "Found: " << table[newIndex].name << endl;
                return;
            }

            if (!table[newIndex].occupied) break;

            attempt++;
        }
        cout << "Record not found\n";
    }
};

int main() {
    StudentHashTable ht;

    ht.InsertRecord(101, "Ali");
    ht.InsertRecord(116, "Sara");
    ht.InsertRecord(131, "Ahmed");

    ht.SearchRecord(116);
    ht.SearchRecord(200);

    return 0;
}
