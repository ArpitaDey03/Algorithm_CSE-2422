#include <iostream>
using namespace std;

#define MAX 100

int temp[MAX];


void merge(int A[], int l, int mid, int h) {
    int i = l;
    int j = mid + 1;
    int k = l;


    while (i <= mid && j <= h) {
        if (A[i] <= A[j]) {
            temp[k] = A[i];
            i++;
        } else {
            temp[k] = A[j];
            j++;
        }
        k++;
    }

    if (i > mid) {
        while (j <= h) {
            temp[k] = A[j];
            j++;
            k++;
        }
    }

    else {
        while (i <= mid) {
            temp[k] = A[i];
            i++;
            k++;
        }
    }


    for (int m = l; m <= h; m++) {
        A[m] = temp[m];
    }
}


void mergeSort(int A[], int l, int h) {
    if (l < h) {
        int mid = (l + h) / 2;
        mergeSort(A, l, mid);
        mergeSort(A, mid + 1, h);
        merge(A, l, mid, h);
    }
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int A[MAX];
    cout << "element: ";
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    mergeSort(A, 0, n - 1);

    cout << "sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;

    return 0;
}
