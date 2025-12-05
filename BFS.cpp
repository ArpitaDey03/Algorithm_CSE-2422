
#include<bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> tree(n + 1);

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    int root = 1;

    vector<bool> visited(n + 1, false);
    queue<int> q;

    visited[root] = true;
    q.push(root);

    cout << "BFS / Level Order: ";

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        cout << node << " ";

        for (int child : tree[node]) {
            if (!visited[child]) {
                visited[child] = true;
                q.push(child);
            }
        }
    }

    return 0;
}
