#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    int arr[100];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int low[100], high[100];
    int top = -1;

    low[++top] = 0;
    high[top] = n - 1;


    while (top >= 0) {
        int l = low[top];
        int h = high[top];
        top--;

        int pivot = arr[h];
        int i = l - 1;

        for (int j = l; j < h; j++) {
            if (arr[j] < pivot) {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[h]);
        int p = i + 1;

        if (p - 1 > l) {
            low[++top] = l;
            high[top] = p - 1;
        }


        if (p + 1 < h) {
            low[++top] = p + 1;
            high[top] = h;
        }
    }

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
