#include <iostream>
using namespace std;

class Stack {
    int top;
    int stackArr[100];     
    int maxSize;

public:

    Stack(int size = 10) {
        top = -1;
        maxSize = size;
    }

    void push(int value) {
        if (top >= maxSize - 1) {
            cout << "Stack Overflow! cannot push " << value << endl;
            return;
        }
        stackArr[++top] = value;
        cout << value << " pushed into stack.\n";
    }

    void pop() {
        if (top < 0) {
            cout << "Stack Underflow! nothing to pop.\n";
            return;
        }
        cout << "Popped element: " << stackArr[top--] << endl;
    }

    void peek() {
        if (top < 0) {
            cout << "Stack is empty.\n";
            return;
        }
        cout << "Top element: " << stackArr[top] << endl;
    }

    void display() {
        if (top < 0) {
            cout << "Stack is empty.\n";
            return;
        }

        cout << "Stack contents (top to bottom): ";
        for (int i = top; i >= 0; i--) {
            cout << stackArr[i] << " ";
        }
        cout << endl;
    }
};


int main() {
    Stack   myStack(5);
    int choice, value;

    while (true) {
        cout << "\n--- Stack Menu ---\n";
        cout << "1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                myStack.push(value);
                break;

            case 2:
                myStack.pop();
                break;

            case 3:
                myStack.peek();
                break;

            case 4:
                myStack.display();
                break;

            case 5:
                cout << "Exiting...\n";
                return 0;

            default:
                cout << "Invalid choice!\n";
        }
    }
}
