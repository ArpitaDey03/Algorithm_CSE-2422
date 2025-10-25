#include <bits/stdc++.h>
using namespace std;

int binary_search(int arr[], int n, int data) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == data)
            return mid;
        else if (arr[mid] < data)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main() {
    int n, data;
    cout << "Size: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter element to search: ";
    cin >> data;

    sort(arr, arr + n);

    int result = binary_search(arr, n, data);
    if (result != -1) {
        cout << "Element found at index (after sorting): " << result << endl;
    } else {
        cout << "Element not found" << endl;
    }

    return 0;
}
