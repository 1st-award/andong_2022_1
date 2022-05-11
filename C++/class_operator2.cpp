#include <iostream>

using namespace std;

class CMy {
    int x;
public:
    CMy(int a) : x(a) {}

    int operator++(int) { return (x++); }

    int operator++() { return (++x); }
};

int main() {
    CMy me(1);
    cout << me++ << endl;
    cout << ++me << endl;
}
