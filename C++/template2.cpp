#include <iostream>

using namespace std;

template <class T>
T sum (T a, T b) {
    T result;
    result = a + b;
    return result;
}

int main(void) {
    cout << sum<int>(3, 5) << endl;
    cout << sum<double>(3.2, 4.1) << endl;

    return 0;
}