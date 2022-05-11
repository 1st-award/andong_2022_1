#include <iostream>

using namespace std;

class CX {
    int x;

public:
    void Pr() {
        cout << x <<endl;
    }

    void Plus() {
        x++;
    }

    void operator++(int) {
        this->x++;
    }
};



int main(void) {
    CX x;

    x.Pr();
    x.Plus();
    x.Pr();
    x++;
    x.Pr();
}