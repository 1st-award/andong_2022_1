#include <iostream>

using namespace std;
class CSq;
class CRect {
    int w, h;
public:
    CRect(int a, int b): w(a), h(b){}
    int area() {return w * h;}
    void Conv(CSq a);
};

class CSq {
    int s;
    friend CRect;
public:
    CSq(int a): s(a) {}
};

void CRect::Conv(CSq a) {
    w = a.s;
    h = a.s;
}

int main(void) {
    CRect c(3, 5);
    CSq s(4);

    cout << c.area() << endl;
    c.Conv(s);
    cout << c.area() << endl;
}