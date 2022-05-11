#include <iostream>

using namespace std;

class CMy {
public:
    int posX, posY;
public:
    CMy(int x, int y) : posX(x), posY(y) {}

    CMy *operator+(CMy cMy) {
        CMy *temp = new CMy(posX + cMy.posX, posY + cMy.posY);
        return temp;
    }

    CMy *operator>>(CMy cMy) {
        CMy *temp = new CMy(posX + cMy.posX, posY + cMy.posY);
        return temp;
    }
};

int main(void) {
    CMy my1(2, 3);
    CMy my2(1, 5);
    CMy *my3;

    my3 = my1 + my2;
    cout << my3->posX << " " << my3->posY << endl;
    my3 = my1 >> my2;
    cout << my3->posX << " " << my3->posY << endl;
}