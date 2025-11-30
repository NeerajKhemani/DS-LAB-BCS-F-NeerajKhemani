#include <iostream>
#include <vector>
using namespace std;

const int TABLE_SIZE = 1000;

vector<pair<int,int>> hashTable[TABLE_SIZE];

int main() {
    int arr[] = {3,4,7,1,2,9,8};
    int n = sizeof(arr)/sizeof(arr[0]);

    bool found = false;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {

            int sum = arr[i] + arr[j];
            int index = sum % TABLE_SIZE;

            for (auto &p : hashTable[index]) {
                int a = p.first;
                int b = p.second;

                if (a != arr[i] && a != arr[j] &&
                    b != arr[i] && b != arr[j]) {

                    cout << "(" << a << ", " << b << ") and ("
                         << arr[i] << ", " << arr[j] << ")\n";
                    found = true;
                    break;
                }
            }

            if (found) break;

            hashTable[index].push_back({arr[i], arr[j]});
        }
        if (found) break;
    }

    if (!found) cout << "No pairs found\n";
}
