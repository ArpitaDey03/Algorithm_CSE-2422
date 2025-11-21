
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int start[100], finish[100];

    for(int i = 0; i < n; i++) cin >> start[i];
    for(int i = 0; i < n; i++) cin >> finish[i];

    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(finish[j] > finish[j + 1]) {

                int temp = finish[j];
                finish[j] = finish[j + 1];
                finish[j + 1] = temp;

                temp = start[j];
                start[j] = start[j + 1];
                start[j + 1] = temp;
            }
        }
    }

    cout << "Selected activities:\n";

    int lastFinish = finish[0];
    cout << start[0] << " " << finish[0] << endl;

    for(int i = 1; i < n; i++) {
        if(start[i] >= lastFinish) {
            cout << start[i] << " " << finish[i] << endl;
            lastFinish = finish[i];
        }
    }

    return 0;
}
