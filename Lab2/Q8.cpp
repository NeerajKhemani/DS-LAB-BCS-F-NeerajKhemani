/*Task #8:
Create a dynamic program to store temperature readings of a city for n days and m different times in a day
using a 2D array.
=> Calculate the daily average temperature.
=> Find the hottest and coldest day.*/

#include <iostream>
using namespace std;

int main() {
    int n, m;
    cout << "Days: ";
    cin >> n;
    cout << "Readings per day: ";
    cin >> m;

    double **temp = new double*[n];
    for (int i = 0; i < n; i++) {
        temp[i] = new double[m];
        cout << "Day " << i+1 << ":\n";
        for (int j = 0; j < m; j++) cin >> temp[i][j];
    }

    double *avg = new double[n];
    for (int i = 0; i < n; i++) {
        double sum = 0;
        for (int j = 0; j < m; j++) sum += temp[i][j];
        avg[i] = sum / m;
    }

    int hot = 0, cold = 0;
    for (int i = 1; i < n; i++) {
        if (avg[i] > avg[hot]) hot = i;
        if (avg[i] < avg[cold]) cold = i;
    }

    cout << "\nDaily Averages:\n";
    for (int i = 0; i < n; i++) cout << "Day " << i+1 << ": " << avg[i] << "\n";

    cout << "\nHottest day: " << hot+1 << "\n";
    cout << "Coldest day: " << cold+1 << "\n";

    for (int i = 0; i < n; i++) delete[] temp[i];
    delete[] temp;
    delete[] avg;
}
