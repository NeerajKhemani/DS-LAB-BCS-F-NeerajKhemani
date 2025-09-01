/*Task #6:
Implement a Safe Pointer class to wrap around an integer pointer.
=> Provide methods for setValue(), getValue(), and release().
=>
Demonstrate the class by storing marks of 5 students and printing them safely without
direct pointer manipulation.*/

#include <iostream>
using namespace std;

class SafePtr {
    int *ptr;
public:
    SafePtr() { ptr = new int; }
    void setValue(int v) { *ptr = v; }
    int getValue() { return *ptr; }
    void release() { delete ptr; ptr = nullptr; }
};

int main() {
    SafePtr students[5];
    for (int i = 0; i < 5; i++) {
        int m;
        cout << "Mark " << i+1 << ": ";
        cin >> m;
        students[i].setValue(m);
    }

    cout << "\nMarks:\n";
    for (int i = 0; i < 5; i++) cout << students[i].getValue() << " ";

    for (int i = 0; i < 5; i++) students[i].release();
}
