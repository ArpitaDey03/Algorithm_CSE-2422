#include <bits/stdc++.h>
using namespace std;

vector<int> rabinKarp(string text, string pattern) {
    int n = text.size();
    int m = pattern.size();

    vector<int> result;

    int base = 256;
    int mod = 101;

    int pHash = 0, tHash = 0;
    int power = 1;

    for (int i = 0; i < m - 1; i++)
        power = (power * base) % mod;

    for (int i = 0; i < m; i++) {
        pHash = (pHash * base + pattern[i]) % mod;
        tHash = (tHash * base + text[i]) % mod;
    }

    for (int i = 0; i <= n - m; i++) {

        if (pHash == tHash) {
            if (text.substr(i, m) == pattern) {
                result.push_back(i);
            }
        }

        if (i < n - m) {
            tHash = (tHash - text[i] * power) % mod;
            if (tHash < 0) tHash += mod;

            tHash = (tHash * base + text[i + m]) % mod;
        }
    }

    return result;
}

int main() {
    string text, pattern;
    cin >> text >> pattern;

    vector<int> matches = rabinKarp(text, pattern);

    for (int pos : matches) {
        cout << "Pattern found at index: " << pos
             << " => " << text.substr(pos, pattern.size()) << endl;
    }

    return 0;
}
