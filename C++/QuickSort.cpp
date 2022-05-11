#include <iostream>
#include <cstdlib>

using namespace std;

void Pr(int arr[], int len) {
    for(int i = 0; i < len; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int comp(const void* a, const void* b) {
    const int x = *((int*)a);
    const int y = *((int*)b);

    if(x > y)       return 1;
    else if(x < y)  return -1;
    else            return 0;
}

int main(void) {
    int arr[] = {3, 1, 2, 4, 5};
    int len = sizeof(arr) / sizeof(arr[0]);

    cout << "Before: ";
    Pr(arr, len);

    qsort(arr, len, sizeof(int), comp);
    cout << "After: ";
    Pr(arr, len);
}
