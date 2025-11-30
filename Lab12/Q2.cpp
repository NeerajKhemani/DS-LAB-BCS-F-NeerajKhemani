#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> rabinKarp(string text, string pat, int &modulus, int &falsePositives) {
    vector<int> positions;
    falsePositives = 0;

    int n = text.size();
    int m = pat.size();
    int d = 256;
    int h = 1;

    for (int i = 0; i < m - 1; i++) h = (h * d) % modulus;

    int pHash = 0, tHash = 0;
    for (int i = 0; i < m; i++) {
        pHash = (d * pHash + pat[i]) % modulus;
        tHash = (d * tHash + text[i]) % modulus;
    }

    for (int i = 0; i <= n - m; i++) {
        if (pHash == tHash) {
            bool match = true;
            for (int j = 0; j < m; j++) {
                if (text[i + j] != pat[j]) {
                    match = false;
                    falsePositives++;
                    break;
                }
            }
            if (match) positions.push_back(i);
        }

        if (i < n - m) {
            tHash = (d * (tHash - text[i] * h) + text[i + m]) % modulus;
            if (tHash < 0) tHash += modulus;
        }
    }

    return positions;
}

int main() {
    string text = "Data structures and algorithms are fun. Algorithms make tasks easier.";
    string pat = "Algorithms";
    int modulus = 101;
    int falsePositives = 0;

    vector<int> ans = rabinKarp(text, pat, modulus, falsePositives);

    cout << "[ ";
    for (int x : ans) cout << x << " ";
    cout << "]\n";

    cout << "False-positive hash matches discarded: " << falsePositives << endl;
}
