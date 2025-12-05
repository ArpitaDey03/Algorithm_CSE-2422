#include <bits/stdc++.h>
using namespace std;

struct Node {
    char ch;
    int freq;
    Node *left, *right;

    Node(char c, int f) {
        ch = c;
        freq = f;
        left = right = NULL;
    }
};

struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};

void buildCodes(Node* root, string s, unordered_map<char,string>& mp) {
    if (!root) return;

    if (!root->left && !root->right) {
        mp[root->ch] = s;
        return;
    }

    buildCodes(root->left, s + "0", mp);
    buildCodes(root->right, s + "1", mp);
}

string encodeText(string text, unordered_map<char,string>& codes) {
    string encoded = "";
    for (char c : text)
        encoded += codes[c];
    return encoded;
}

string decodeText(Node* root, string encoded) {
    string decoded = "";
    Node* curr = root;

    for (char bit : encoded) {
        if (bit == '0') curr = curr->left;
        else curr = curr->right;

        if (!curr->left && !curr->right) {
            decoded += curr->ch;
            curr = root;
        }
    }
    return decoded;
}

int main() {
    string text;
    cout << "Enter text: ";
    getline(cin, text);

    unordered_map<char, int> freq;
    for (char c : text) freq[c]++;

    priority_queue<Node*, vector<Node*>, Compare> pq;
    for (auto &p : freq)
        pq.push(new Node(p.first, p.second));

    while (pq.size() > 1) {
        Node *a = pq.top(); pq.pop();
        Node *b = pq.top(); pq.pop();

        Node *merged = new Node('*', a->freq + b->freq);
        merged->left = a;
        merged->right = b;

        pq.push(merged);
    }

    Node* root = pq.top();

    unordered_map<char, string> codes;
    buildCodes(root, "", codes);

    cout << "\nHuffman Codes:\n";
    for (auto &p : codes)
        cout << p.first << ": " << p.second << endl;

    string encoded = encodeText(text, codes);
    cout << "\nEncoded string:\n" << encoded << endl;

    string decoded = decodeText(root, encoded);
    cout << "\nDecoded string:\n" << decoded << endl;

    return 0;
}
