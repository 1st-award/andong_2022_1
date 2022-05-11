#include <iostream>

using namespace std;

class CRect {
    int width, height;

public:
    CRect(int a, int b):width(a), height(b){}

    int Area() {
        return width * height;
    }
};

int main(void) {
    CRect r(4, 5);
    cout << "(4, 5) Area is: " << r.Area() << endl;
    return 0;
}