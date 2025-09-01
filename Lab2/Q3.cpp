/*Task #3:
Design a program to handle marks of students in different courses using a jagged array
(since each student is enrolled in a different number of courses).
=> Input the number of courses each student takes.
=> Dynamically allocate memory for each student accordingly.
=> Calculate and display each student’s average marks. */

#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Students: ";
    cin >> n;

    int **marks = new int*[n];
    int *courses = new int[n];

    for (int i = 0; i < n; i++) {
        cout << "Courses for student " << i+1 << ": ";
        cin >> courses[i];
        marks[i] = new int[courses[i]];
        for (int j = 0; j < courses[i]; j++) {
            cout << "Mark " << j+1 << ": ";
            cin >> marks[i][j];
        }
    }

    cout << "\nAverages:\n";
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j < courses[i]; j++) sum += marks[i][j];
        cout << "Student " << i+1 << ": " << (sum / (float)courses[i]) << "\n";
    }

    for (int i = 0; i < n; i++) delete[] marks[i];
    delete[] marks;
    delete[] courses;
}
