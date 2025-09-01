/*Task #7:
A company has multiple departments, each department has a different number of employees.
=> Use a jagged array where each row corresponds to a department and columns store employee
salaries.
 Calculate:
 -> The highest salary in each department.
 -> The department with the overall maximum average salary.*/

#include <iostream>
using namespace std;

int main() {
    int d;
    cout << "Departments: ";
    cin >> d;

    int **sal = new int*[d];
    int *emp = new int[d];

    for (int i = 0; i < d; i++) {
        cout << "Employees in dept " << i+1 << ": ";
        cin >> emp[i];
        sal[i] = new int[emp[i]];
        for (int j = 0; j < emp[i]; j++) {
            cout << "Salary " << j+1 << ": ";
            cin >> sal[i][j];
        }
    }

    cout << "\nHighest in each dept:\n";
    for (int i = 0; i < d; i++) {
        int maxSal = sal[i][0];
        for (int j = 1; j < emp[i]; j++)
            if (sal[i][j] > maxSal) maxSal = sal[i][j];
        cout << "Dept " << i+1 << ": " << maxSal << "\n";
    }

    int maxDept = 0;
    double maxAvg = 0;
    for (int i = 0; i < d; i++) {
        double sum = 0;
        for (int j = 0; j < emp[i]; j++) sum += sal[i][j];
        double avg = sum / emp[i];
        if (avg > maxAvg) {
            maxAvg = avg;
            maxDept = i;
        }
    }

    cout << "\nDept with max avg salary: " << maxDept+1 << " (Avg: " << maxAvg << ")\n";

    for (int i = 0; i < d; i++) delete[] sal[i];
    delete[] sal;
    delete[] emp;
}
