#include <iostream>

using namespace std;

class CRect {
    int num1, num2;
public:
    CRect() : num1(1), num2(2) {}

    friend istream &operator>>(istream &is, CRect &me) {
        cin >> me.num1 >> me.num2;
        return is;
    }

    void Pr() {
        cout << num1 << " " << num2 << endl;
    }
};

int main(void) {
    CRect cRect;

    cRect.Pr();
    cin >> cRect;
    cRect.Pr();
}