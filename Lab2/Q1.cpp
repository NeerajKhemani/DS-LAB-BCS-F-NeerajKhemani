#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size: ";
    cin >> n;

    int *a = new int[n];
    for (int i = 0; i < n; i++) a[i] = 0;

    char ch;
    do {
        int idx, val;
        cout << "Index: ";
        cin >> idx;
        if (idx >= 0 && idx < n) {
            cout << "Value: ";
            cin >> val;
            a[idx] = val;
        } else {
            cout << "Invalid index\n";
        }
        cout << "Update more? (y/n): ";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');

    cout << "Array: ";
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << "\n";

    delete[] a;
}
