#include <algorithm>
#include <iostream>

using namespace std;

void Pr(int arr[], int len) {
    for (int i = 0; i < len; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {3, 1, 2, 4, 5};
    int len = sizeof(arr) / sizeof(arr[0]);

    cout << "Before: ";
    Pr(arr, len);

    sort(arr, arr + len);
    cout << "After: ";
    Pr(arr, len);
}