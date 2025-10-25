#include <iostream>
using namespace std;

#define MAX 100

void selectionSort(int A[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;

        for (int j = i + 1; j < n; j++) {
            if (A[j] < A[minIndex]) {
                minIndex = j;
            }
        }

        if (minIndex != i) {
            int temp = A[i];
            A[i] = A[minIndex];
            A[minIndex] = temp;
        }
    }
}

int main() {
    int n;
    cout << "Enter number of elements (<= " << MAX << "): ";
    cin >> n;


    int A[MAX];

    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    cout << "Before sorting: ";
    for (int i = 0; i < n; i++) cout << A[i] << " ";
    cout << "\n";

    selectionSort(A, n);

    cout << "After sorting:  ";
    for (int i = 0; i < n; i++) cout << A[i] << " ";
    cout << "\n";

    return 0;
}

