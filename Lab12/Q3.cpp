#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int ALPHABET_SIZE = 256;

vector<int> badCharTable(string pat) {
    vector<int> bad(ALPHABET_SIZE, -1);
    for (int i = 0; i < pat.size(); i++)
        bad[pat[i]] = i;
    return bad;
}

vector<int> suffixes(string pat) {
    int m = pat.size();
    vector<int> suff(m);
    suff[m - 1] = m;
    int g = m - 1, f = 0;
    for (int i = m - 2; i >= 0; i--) {
        if (i > g && suff[i + m - 1 - f] < i - g)
            suff[i] = suff[i + m - 1 - f];
        else {
            if (i < g) g = i;
            f = i;
            while (g >= 0 && pat[g] == pat[g + m - 1 - f]) g--;
            suff[i] = f - g;
        }
    }
    return suff;
}

vector<int> goodSuffixTable(string pat) {
    int m = pat.size();
    vector<int> suff = suffixes(pat);
    vector<int> gs(m, m);
    for (int i = m - 1; i >= 0; i--) {
        if (suff[i] == i + 1) {
            for (int j = 0; j < m - 1 - i; j++)
                gs[j] = m - 1 - i;
        }
    }
    for (int i = 0; i <= m - 2; i++)
        gs[m - 1 - suff[i]] = m - 1 - i;
    return gs;
}

vector<int> boyerMooreSearch(string text, string pat) {
    vector<int> result;
    int n = text.size();
    int m = pat.size();
    vector<int> bad = badCharTable(pat);
    vector<int> gs = goodSuffixTable(pat);

    int s = 0;
    while (s <= n - m) {
        int j = m - 1;
        while (j >= 0 && pat[j] == text[s + j]) j--;
        if (j < 0) {
            result.push_back(s);
            s += gs[0];
        } else {
            int bcShift = j - bad[text[s + j]];
            int gsShift = gs[j];
            s += max(1, max(bcShift, gsShift));
        }
    }
    return result;
}

int main() {
    string dna = "ACGTACGTGACG";
    string motif = "ACG";

    vector<int> positions = boyerMooreSearch(dna, motif);

    cout << "[ ";
    for (int x : positions) cout << x << " ";
    cout << "]" << endl;
}
