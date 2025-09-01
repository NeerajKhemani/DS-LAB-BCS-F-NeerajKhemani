/*Task #5:
Write a C++ program that dynamically creates a 2D matrix and provides:
=> Addition of two matrices.
=> Subtraction of two matrices.
=> Ensure safe memory handling with proper allocation/deallocation.*/

#include <iostream>
using namespace std;

int main() {
    int r, c;
    cout << "Rows: ";
    cin >> r;
    cout << "Cols: ";
    cin >> c;

    int **a = new int*[r], **b = new int*[r], **sum = new int*[r], **diff = new int*[r];
    for (int i = 0; i < r; i++) {
        a[i] = new int[c];
        b[i] = new int[c];
        sum[i] = new int[c];
        diff[i] = new int[c];
    }

    cout << "Matrix A:\n";
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++) cin >> a[i][j];

    cout << "Matrix B:\n";
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++) cin >> b[i][j];

    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++) {
            sum[i][j] = a[i][j] + b[i][j];
            diff[i][j] = a[i][j] - b[i][j];
        }

    cout << "\nSum:\n";
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) cout << sum[i][j] << " ";
        cout << "\n";
    }

    cout << "\nDifference:\n";
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) cout << diff[i][j] << " ";
        cout << "\n";
    }

    for (int i = 0; i < r; i++) {
        delete[] a[i];
        delete[] b[i];
        delete[] sum[i];
        delete[] diff[i];
    }
    delete[] a;
    delete[] b;
    delete[] sum;
    delete[] diff;
}
