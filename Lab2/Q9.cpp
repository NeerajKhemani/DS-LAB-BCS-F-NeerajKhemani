/*Task #9:
Implement a program to represent a sparse matrix using a dynamic 2D array.
=> Input matrix elements.
=> Display the matrix in normal form.
=> Display the matrix in compressed form (row, column, value).*/

#include <iostream>
using namespace std;

int main() {
    int r, c;
    cout << "Rows: ";
    cin >> r;
    cout << "Cols: ";
    cin >> c;

    int **mat = new int*[r];
    for (int i = 0; i < r; i++) {
        mat[i] = new int[c];
        for (int j = 0; j < c; j++) cin >> mat[i][j];
    }

    cout << "\nMatrix:\n";
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) cout << mat[i][j] << " ";
        cout << "\n";
    }

    int nonZero = 0;
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            if (mat[i][j] != 0) nonZero++;

    int **comp = new int*[nonZero];
    for (int i = 0; i < nonZero; i++) comp[i] = new int[3];

    int k = 0;
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            if (mat[i][j] != 0) {
                comp[k][0] = i;
                comp[k][1] = j;
                comp[k][2] = mat[i][j];
                k++;
            }

    cout << "\nCompressed (row col val):\n";
    for (int i = 0; i < nonZero; i++)
        cout << comp[i][0] << " " << comp[i][1] << " " << comp[i][2] << "\n";

    for (int i = 0; i < r; i++) delete[] mat[i];
    delete[] mat;

    for (int i = 0; i < nonZero; i++) delete[] comp[i];
    delete[] comp;
}
