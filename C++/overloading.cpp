#include <iostream>
using namespace std;

int op(int a, int b) {
    return a + b;
}

double op(double a, double b) {
    return a - b;
}

void op(void) {
    cout << "Hello World!" << endl;
}

int main(void) {
    cout << op(2, 3) << endl;
    cout << op(4.1 , 5.2) << endl;
    op();
}