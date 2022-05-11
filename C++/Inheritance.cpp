#include <iostream>

using namespace std;

class CPoly {
protected:
    int width, height;
};

class CRect: public CPoly {
public:
    CRect() {
        width = 0, height = 0;
    }
    CRect(int width, int height) {
        this->width = width, this->height = height;
    }

    void Pr() {
        cout << "Width : " << width << " Height : " << height << endl;
        cout << "Area is " << width * height << endl;
    }
};

class CTriangle: public CPoly {
public:
    CTriangle() {
        width = 0, height = 0;
    }
    CTriangle(int width, int height) {
        this->width = width, this->height = height;
    }

    void Pr() {
        cout << "Width : " << width << " Height : " << height << endl;
        cout << "Triangle Area is " << width * height / 2 << endl;
    }
};


int main(void) {
    CRect r1(3, 7);
    CTriangle r2(6, 4);

    r1.Pr();
    r2.Pr();
}
