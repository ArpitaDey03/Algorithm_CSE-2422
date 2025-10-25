#include <iostream>
using namespace std;


int getMax(int A[], int n) {
    int mx = A[0];
    for (int i = 1; i < n; i++) {
        if (A[i] > mx)
            mx = A[i];
    }
    return mx;
}

void countsort(int A[], int n, int pos) {
    int output[100];
    int count[10] = {0};


    for (int i = 0; i < n; i++) {
        int digit = (A[i] / pos) % 10;
        count[digit]++;
    }


    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }


    for (int i = n - 1; i >= 0; i--) {
        int digit = (A[i] / pos) % 10;
        output[--count[digit]] = A[i];
    }

   for (int i = 0; i < n; i++) {
        A[i] = output[i];
    }
}


void radixsort(int A[], int n) {
    int m = getMax(A, n);

    for (int pos = 1; m / pos > 0; pos *= 10) {
        countsort(A, n, pos);
    }
}

int main() {
    int n;
    cout << "Enter size: ";
    cin >> n;

    int A[100];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> A[i];

    radixsort(A, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) cout << A[i] << " ";
    cout << "\n";

    return 0;
}
