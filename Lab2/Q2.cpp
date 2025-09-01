#include <iostream>
using namespace std;

int main() {
    int r, c;
    cout << "Rows: ";
    cin >> r;
    cout << "Seats per row: ";
    cin >> c;

    int **seat = new int*[r];
    for (int i = 0; i < r; i++) {
        seat[i] = new int[c];
        for (int j = 0; j < c; j++) seat[i][j] = 0;
    }

    char ch;
    do {
        int x, y;
        cout << "Enter row and seat: ";
        cin >> x >> y;
        if (x >= 0 && x < r && y >= 0 && y < c) {
            seat[x][y] = 1;
        } else {
            cout << "Invalid\n";
        }
        cout << "More? (y/n): ";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');

    cout << "\nChart:\n";
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) cout << seat[i][j] << " ";
        cout << "\n";
    }

    for (int i = 0; i < r; i++) delete[] seat[i];
    delete[] seat;
}
