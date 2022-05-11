#include <iostream>

using namespace std;

class CPnt {
    int p1, p2;
public:
    CPnt (int a, int b) {
        p1 = a, p2 = b;
    }

    CPnt(void) {
        p1 = 0, p2 = 0;
    }

    CPnt operator+(CPnt cpnt) {
        CPnt temp;
        temp.p1 = p1 + cpnt.p1;
        temp.p2 = p2 + cpnt.p2;
        return temp;
    }

    void pr() {
        cout << p1 << ", " << p2 << endl;
    }
};

int main() {
    CPnt a(1,2);
    CPnt b(3,4);
    CPnt c;
    c = a + b;  // a.operator +(b); <- a.Add(b) operator overloading
    c.pr();

}
