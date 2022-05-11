#include <iostream>

using namespace std;

class CPnt {
    int x, y;

public:
    CPnt() : x(0), y(0) {}

    CPnt(int x, int y) : x(x), y(y) {}

    CPnt operator+(CPnt temp) {
        return CPnt(this->x + temp.x, this->y + temp.y);
    }

    void Pr();
};

void CPnt::Pr() {
    cout << x << ", " << y << endl;
}

int main(void) {
    CPnt p1(2, 3);
    CPnt p2(4, 5);
    CPnt p3;
    p3 = p1 + p2;

    p1.Pr();
    p2.Pr();
    p3.Pr();
}
