/*Task #4:
Create a dynamic program that manages monthly expenses for a family.
=> Use a 1D dynamic array to store expenses for n months.
=> Add a feature to resize the array if the user wants to track more months later.
=> Compute and display the total and average expenses.*/

#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Months: ";
    cin >> n;

    double *exp = new double[n];
    for (int i = 0; i < n; i++) {
        cout << "Expense " << i+1 << ": ";
        cin >> exp[i];
    }

    char ch;
    cout << "Add more months? (y/n): ";
    cin >> ch;

    if (ch == 'y' || ch == 'Y') {
        int more;
        cout << "How many more: ";
        cin >> more;

        double *temp = new double[n + more];
        for (int i = 0; i < n; i++) temp[i] = exp[i];
        delete[] exp;
        exp = temp;

        for (int i = n; i < n + more; i++) {
            cout << "Expense " << i+1 << ": ";
            cin >> exp[i];
        }
        n += more;
    }

    double sum = 0;
    for (int i = 0; i < n; i++) sum += exp[i];
    cout << "\nTotal: " << sum;
    cout << "\nAverage: " << sum / n;

    delete[] exp;
}
