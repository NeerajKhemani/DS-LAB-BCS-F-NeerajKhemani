/*Task #10:
Design a program that maintains library book records using dynamic arrays.
=> Each row represents a category (e.g., Fiction, Science, History).
=> Each category has a different number of books (use a jagged array).
=> Store book IDs dynamically and allow the user to search for a given book ID.
=> Print whether the book is available and in which category.*/

#include <iostream>
using namespace std;

int main() {
    int cat;
    cout << "Categories: ";
    cin >> cat;

    int **books = new int*[cat];
    int *count = new int[cat];

    for (int i = 0; i < cat; i++) {
        cout << "Books in category " << i+1 << ": ";
        cin >> count[i];
        books[i] = new int[count[i]];
        for (int j = 0; j < count[i]; j++) {
            cout << "Book ID " << j+1 << ": ";
            cin >> books[i][j];
        }
    }

    int id;
    cout << "\nEnter Book ID to search: ";
    cin >> id;

    bool found = false;
    for (int i = 0; i < cat; i++) {
        for (int j = 0; j < count[i]; j++) {
            if (books[i][j] == id) {
                cout << "Book found in category " << i+1 << "\n";
                found = true;
                break;
            }
        }
        if (found) break;
    }

    if (!found) cout << "Book not found\n";

    for (int i = 0; i < cat; i++) delete[] books[i];
    delete[] books;
    delete[] count;
}
