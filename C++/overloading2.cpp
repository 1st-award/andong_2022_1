#include <iostream>

using namespace std;

int sum(int a, int b) {
    return a + b;
}

double sum(double a, double b) {
    return a + b;
}

int main(void) {
    cout << sum(3, 5) << endl;
    cout << sum(3.2, 2.3) << endl;

    return 0;
}