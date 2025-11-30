#include <iostream>
#include <vector>
using namespace std;

vector<int> bruteForceSearch(string text, string pat, int &comparisons) {
    vector<int> idx;
    comparisons = 0;

    int n = text.size();
    int m = pat.size();

    for (int i = 0; i <= n - m; i++) {
        int j = 0;
        while (j < m && text[i + j] == pat[j]) {
            comparisons++;
            j++;
        }
        if (j < m) comparisons++;
        if (j == m) idx.push_back(i);
    }

    return idx;
}

int main() {
    string text = "the quick brown fox jumps over the lazy dog";
    string pat = "the";

    int comp = 0;
    vector<int> ans = bruteForceSearch(text, pat, comp);

    cout << "[ ";
    for (int x : ans) cout << x << " ";
    cout << "]" << endl;

    cout << "Total Comparisons: " << comp << endl;
}
