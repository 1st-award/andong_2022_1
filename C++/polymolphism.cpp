#include <iostream>

using namespace std;

class CPoly {
protected:
    int width, height;
public:
    ~CPoly(){}
    virtual void Area() = 0;
};


class CRect : public CPoly {
public:
    CRect(int width, int height) {
        this->width = width;
        this->height = height;
    }

    void Area() {
        cout << "Area" << endl;
        cout << width << " * " << height << " = " << width * height << endl;
    }
};

class CTri : public CPoly {
public:
    CTri(int width, int height) {
        this->width = width;
        this->height = height;
    }

    void Area() {
        cout << "Tri" << endl;
        cout << width << " * " << height << " / 2 = " << width*height/2 << endl;
    }
};

int main() {
    CPoly *p = NULL;
    CRect *r = new CRect(2, 3);
    CTri t(2, 3);

    p = r;
    p->Area();
    p = &t;
    p->Area();

    delete(r);
}