#include <iostream>

using namespace std;

class CPoly {
protected:
    int width, height;
public:
    virtual void Area() = 0;
};

class CRect : public CPoly {
public:
    CRect(int width, int height) {
        this->width = width;
        this->height = height;
    }

    void Area() {
        cout << "==== CRect ====" << endl;
        cout << "Area: " << width * height << endl;
    }
};

class CTri: public CPoly {
public:
    CTri(int width, int height) {
        this->width = width;
        this->height = height;
    }
    void Area() {
        cout << "==== CTri ====" << endl;
        cout << "Area: " << (width * height) / 2 << endl;
    }
};

int main(void) {
    CPoly* p;
    CRect r(2,3);
    CTri t(2, 3);

    p = &r; p->Area();
    p = &t; p->Area();
}