#include <iostream>

using namespace std;

class Cmy {
public:
    int x, y;

    Cmy(int a, int b) : x(a), y(b) {}

    Cmy operator+(Cmy t) {
        return Cmy(x + t.x, y + t.y);
    }

    friend istream &operator>>(istream &is, Cmy &me) {
        int a, b;
        is >> a >> b;
        me.x += a;
        me.y += b;
        return is;
    }
};

int main() {
    Cmy my1(1, 2);
    Cmy my2 = Cmy(0, 0);
    Cmy my3 = Cmy(0, 0);
    cin >> my2;

    cout << "==== my1 ====" << endl;
    cout << "x: " << my1.x << " y: " << my1.y << endl;

    cout << "==== my2 ====" << endl;
    cout << "x: " << my2.x << " y: " << my2.y << endl;

    my3 = my1 + my2;
    cout << "==== my3 ====" << endl;
    cout << "x: " << my3.x << " y: " << my3.y << endl;
}