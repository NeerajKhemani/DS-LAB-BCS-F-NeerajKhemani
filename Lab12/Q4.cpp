#include <iostream>
#include <vector>
using namespace std;

vector<int> computeLPS(string pat) {
    int m = pat.size();
    vector<int> lps(m,0);
    int len = 0, i = 1;
    while(i < m) {
        if(pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if(len != 0) len = lps[len-1];
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

vector<int> KMPSearch(string text, string pat) {
    vector<int> result;
    int n = text.size();
    int m = pat.size();
    vector<int> lps = computeLPS(pat);
    int i=0, j=0;
    while(i < n) {
        if(pat[j] == text[i]) {
            i++; j++;
        }
        if(j == m) {
            result.push_back(i-j);
            j = lps[j-1];
        } else if(i<n && pat[j] != text[i]) {
            if(j != 0) j = lps[j-1];
            else i++;
        }
    }
    return result;
}

int main() {
    string text = "ababababc";
    string pat = "ab";

    vector<int> positions = KMPSearch(text, pat);

    cout << "[ ";
    for(int x : positions) cout << x << " ";
    cout << "]" << endl;
}
