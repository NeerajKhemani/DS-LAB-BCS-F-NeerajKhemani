/* Create a C++ class named "Exam" using DMA designed to manage student exam records,
complete with a shallow copy implementation? Define attributes such as student name, exam
date, and score within the class, and include methods to set these attributes and display exam
details. As part of this exercise, intentionally omit the implementation of the copy constructor and copy assignment operator. Afterward, create an instance of the "Exam" class, generate a
shallow copy, and observe any resulting issues? */

#include <iostream>
#include <cstring>
using namespace std;

class Exam {
private:
    char* studentName;
    char* examDate;
    int score;

public:
    Exam(const char* name, const char* date, int s) {
        studentName = new char[strlen(name) + 1];
        strcpy(studentName, name);
        examDate = new char[strlen(date) + 1];
        strcpy(examDate, date);
        score = s;
    }

    void setDetails(const char* name, const char* date, int s) {
        strcpy(studentName, name);
        strcpy(examDate, date);
        score = s;
    }

    void display() {
        cout << "Student Name: " << studentName << endl;
        cout << "Exam Date: " << examDate << endl;
        cout << "Score: " << score << endl;
    }

    ~Exam() {
        delete[] studentName;
        delete[] examDate;
    }
};

int main() {
    Exam exam1("Neeraj", "2025-08-25", 95);
    cout << "Original Exam Record:" << endl;
    exam1.display();

    Exam exam2 = exam1; 
    cout << "\nCopied Exam Record:" << endl;
    exam2.display();

    cout << "\nChanging original data..." << endl;
    exam1.setDetails("John", "2025-09-10", 88);

    cout << "\nAfter Modification:" << endl;
    cout << "Original Exam Record:" << endl;
    exam1.display();
    cout << "Copied Exam Record:" << endl;
    exam2.display();

    return 0;
}

/* Resulting Issues:
This leads to double free, which is undefined behavior in C++. */
