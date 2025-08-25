/* Q3. Create a C++ class Box that uses dynamic memory allocation for an integer. Implement the
Rule of Three by defining a destructor, copy constructor, and copy assignment operator.
Demonstrate the behavior of both shallow and deep copy using test cases */

#include <iostream>
using namespace std;

class Box {
private:
    int* data;
    bool shallowMode;
public:
    Box(int value, bool shallow = false) {
        data = new int(value);
        shallowMode = shallow;
    }
    ~Box() {
        delete data;
    }
    Box(const Box& other) {
        if (other.shallowMode) {
            data = other.data; // Shallow copy
        } else {
            data = new int(*other.data); // Deep copy
        }
        shallowMode = other.shallowMode;
    }
    Box& operator=(const Box& other) {
        if (this != &other) {
            delete data;
            if (other.shallowMode) {
                data = other.data;
            } else {
                data = new int(*other.data);
            }
            shallowMode = other.shallowMode;
        }
        return *this;
    }
    void setValue(int value) {
        *data = value;
    }
    int getValue() const {
        return *data;
    }
};

int main() {
    cout << "Deep Copy" << endl;
    Box b1(10);
    Box b2 = b1;
    b2.setValue(20);
    cout << "b1 value: " << b1.getValue() << endl;
    cout << "b2 value: " << b2.getValue() << endl;

    cout << "\nShallow Copy" << endl;
    Box s1(30, true);
    Box s2 = s1;
    s2.setValue(40);
    cout << "s1 value: " << s1.getValue() << endl;
    cout << "s2 value: " << s2.getValue() << endl;

    return 0;
}

/* Deep Copy Behavior

1)Each object gets its own copy of the data in separate memory locations.

2)Changing one object does not affect the other.

3)No crash occurs because each object deletes its own memory safely.

Shallow Copy Behavior

1)Objects share the same memory location for data.

2)Changing one object also changes the other.

3)Crash occurs at the end because both objects try to delete the same memory (double free).
 */
